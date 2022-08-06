#ifndef SIMPLEKALMANFILTER_H
#define SIMPLEKALMANFILTER_H

#include <iostream>
#include <Eigen/Dense>

/**
 * @brief class of a simple kalman filter
 * 
 */
class SimpleKalmanFilter
{
private:
    int stateSize_;         // size of state vector
    int measureSize_;       // size of measurement vector
    int controlSize_;             // size of control vector

    Eigen::VectorXd x_;     // state vec
    Eigen::VectorXd z_;     // measurement vec
    Eigen::VectorXd u_;     // control vec
    Eigen::MatrixXd A_;     // state_trans mat
    Eigen::MatrixXd B_;     // control_trans mat
    Eigen::MatrixXd P_;     // covariance mat
    Eigen::MatrixXd H_;     // trans mat
    Eigen::MatrixXd R_;     // measurement noise covariance mat
    Eigen::MatrixXd Q_;     // system noise covarianve mat
    Eigen::MatrixXd I_;     // identity mat

public:
    /**
     * @brief Construct a new Simple Kalman Filter object
     * 
     * @param stateSize         // size of state vector
     * @param measureSize       // size of measurement vector
     * @param uSize             // size of control vector
     */
    SimpleKalmanFilter(const int stateSize, const int measureSize, const int controlSize);

    /**
     * @brief Destroy the Simple Kalman Filter object
     * 
     */
    ~SimpleKalmanFilter();

    /**
     * @brief init kalman filter
     * 
     * @param x // state vec
     * @param P // covariance mat
     * @param R // measurement noise covariance mat
     * @param Q // system noise covarianve mat
     */
    void init(const Eigen::VectorXd &x, const Eigen::MatrixXd P, const Eigen::MatrixXd R, const Eigen::MatrixXd Q);

    /**
     * @brief predict without control
     * 
     * @param A // state_trans mat
     * @return Eigen::VectorXd 
     */
    Eigen::VectorXd predict(const Eigen::MatrixXd& A);

    /**
     * @brief predict with control
     * 
     * @param A // state_trans mat
     * @param B // control_trans mat
     * @param u // control vec
     * @return Eigen::VectorXd 
     */
    Eigen::VectorXd predict(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::VectorXd& u);

    /**
     * @brief update with measurement
     * 
     * @param H 
     * @param z 
     * @return Eigen::VectorXd 
     */
    Eigen::VectorXd update(const Eigen::MatrixXd& H, const Eigen::VectorXd& z);
};

/**
 * @brief Construct a new Simple Kalman Filter object
 * 
 * @param stateSize         // size of state vector
 * @param measureSize       // size of measurement vector
 * @param uSize             // size of control vector
 */
SimpleKalmanFilter::SimpleKalmanFilter(const int stateSize, const int measureSize, const int controlSize) :
    stateSize_(stateSize),
    measureSize_(measureSize),
    controlSize_(controlSize)
{
    // check size
    if (stateSize == 0 || measureSize == 0)
    {
        std::cerr << "Error, State size and measurement size must bigger than 0\n";
    }

    // init member size
    this->x_.resize(this->stateSize_);
    this->x_.setZero();
    this->z_.resize(this->measureSize_);
    this->z_.setZero();
    this->u_.resize(this->controlSize_);
    this->u_.setZero();
    this->A_.resize(this->stateSize_, this->stateSize_);
    this->A_.setIdentity();
    this->B_.resize(this->stateSize_, this->controlSize_);
    this->B_.setZero();
    this->P_.resize(this->stateSize_, this->stateSize_);
    this->P_.setIdentity();
    this->H_.resize(this->measureSize_, this->stateSize_);
    this->H_.setZero();
    this->R_.resize(this->measureSize_, this->measureSize_);
    this->R_.setZero();
    this->Q_.resize(this->stateSize_, this->stateSize_);
    this->Q_.setZero();
    this->I_.resize(this->stateSize_, this->stateSize_);
    this->I_.setIdentity();
}

/**
 * @brief Destroy the Simple Kalman Filter object
 * 
 */
SimpleKalmanFilter::~SimpleKalmanFilter()
{

}

/**
 * @brief init kalman filter
 * 
 * @param x // state vec
 * @param P // covariance mat
 * @param R // measurement noise covariance mat
 * @param Q // system noise covarianve mat
 */
void SimpleKalmanFilter::init(const Eigen::VectorXd &x, const Eigen::MatrixXd P, const Eigen::MatrixXd R, const Eigen::MatrixXd Q)
{
    this->x_ = x;
    this->P_ = P;
    this->R_ = R;
    this->Q_ = Q;
}

/**
 * @brief predict without control
 * 
 * @param A // state_trans mat
 * @return Eigen::VectorXd 
 */
Eigen::VectorXd SimpleKalmanFilter::predict(const Eigen::MatrixXd& A)
{
    this->A_ = A;
    this->x_ = this->A_*this->x_;
    this->P_ = this->A_*this->P_*this->A_.transpose() + this->Q_;

    return this->x_;
}

/**
 * @brief predict with control
 * 
 * @param A // state_trans mat
 * @param B // control_trans mat
 * @param u // control vec
 * @return Eigen::VectorXd 
 */
Eigen::VectorXd SimpleKalmanFilter::predict(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::VectorXd& u)
{
    this->A_ = A;
    this->B_ = B; 
    this->u_ = u;

    this->x_ = this->A_*this->x_ + this->B_*this->u_;
    this->P_ = this->A_*this->P_*this->A_.transpose() + this->Q_;

    return this->x_;
}

/**
 * @brief update with measurement
 * 
 * @param H 
 * @param z 
 * @return Eigen::VectorXd 
 */
Eigen::VectorXd SimpleKalmanFilter::update(const Eigen::MatrixXd& H, const Eigen::VectorXd& z)
{
    this->H_ = H;
    this->z_ = z;

    Eigen::MatrixXd y = this->z_ - this->H_*this->x_;
    Eigen::MatrixXd S = this->H_*this->P_*this->H_.transpose() + this->R_;
    Eigen::MatrixXd K = this->P_*this->H_.transpose()*S.inverse();

    this->x_ = this->x_ + K*y;
    this->P_ = (this->I_ - K*this->H_)*this->P_;

    return this->x_;
}


#endif // SIMPLEKALMANFILTER_H