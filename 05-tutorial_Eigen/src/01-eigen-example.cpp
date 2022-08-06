/*************************************************************************
	> File Name: 01-eigen-example.cpp
	> Author: 
	> Mail: 
	> Created Time: Di 14 Jan 2020 13:40:28 CET
 ************************************************************************/

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

#define PI 3.141592653589793


void test01_eigen_basic()
{
    Eigen::Matrix3f m2;
    m2 <<   1, 2, 3,
            4, 5, 6,
            7, 8, 9;
    std::cout << m2 << std::endl;


    std::cout << "A fixed-size array: " << std::endl;
    Eigen::Array33f a1 = Eigen::Array33f::Zero();
    std::cout << a1 << std::endl;

    std::cout << "A one-dimensional dynamic-size array: " << std::endl;
    Eigen::ArrayXf a2 = Eigen::ArrayXf::Zero(3);
    std::cout << a2 << std::endl;

    std::cout << "A two-dimensional dynamic-size array: " << std::endl;
    Eigen::ArrayXXf a3 = Eigen::ArrayXXf::Zero(3, 4);
    std::cout << a3 << std::endl;
}



void test02_quaternion()
{
    // heading, pitch, roll
    double heading = 90.5 /180.0 *PI;
    double pitch = 5.5 /180.0 *PI;
    double roll = -3.6 /180.0 *PI;
    Eigen::Vector3d p0(heading, pitch, roll);

    // R
    Eigen::Matrix3d R;
    R = Eigen::AngleAxisd(p0[0], Eigen::Vector3d::UnitZ()) *
        Eigen::AngleAxisd(p0[1], Eigen::Vector3d::UnitX()) *
        Eigen::AngleAxisd(p0[2], Eigen::Vector3d::UnitY());

    // quaternion
    Eigen::Quaterniond q;
    q = R;
    cout << "quaternion: " << endl;
    cout << q.x() << endl;
    cout << q.y() << endl;
    cout << q.z() << endl;
    cout << q.w() << endl;
    cout << endl;

    // check quaternion
    Eigen::Matrix3d Rx = q.toRotationMatrix();
    Eigen::Vector3d p1 = Rx.eulerAngles(2, 0, 1);

    cout << "RPY after quaternion:" << endl;
    cout << p1/PI*180.0 << endl;

}

void test03_matrix_multi()
{
    Eigen::Matrix4f T;
    T.setZero();
    std::cout << "T: \n" << T << std::endl;

    Eigen::Vector4f p1;
    p1.setZero();
    std::cout << "p1: \n" << p1 << std::endl;


    T << 1, 0, 0, 0,
        1, 0, 0, 0,
        1, 0, 0, 0,
        1, 0, 0, 0;
    p1 << 1, 0, 0, 0;
    std::cout << "T: \n" << T << std::endl;
    std::cout << "p1: \n" << p1 << std::endl;

    std::cout << "p1: \n" << T * p1 << std::endl;


}

int main()
{
    // test01_eigen_basic();
    // test02_quaternion();
    test03_matrix_multi();

    return 0;
}
