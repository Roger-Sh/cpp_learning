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
    m2 << 1, 2, 3,
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
    double heading = 90.5 / 180.0 * PI;
    double pitch = 5.5 / 180.0 * PI;
    double roll = -3.6 / 180.0 * PI;
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
    cout << p1 / PI * 180.0 << endl;
}

void test03_matrix_multi()
{
    Eigen::Matrix4f T;
    T.setZero();
    std::cout << "T: \n"
              << T << std::endl;

    Eigen::Vector4f p1;
    p1.setZero();
    std::cout << "p1: \n"
              << p1 << std::endl;

    T << 1, 0, 0, 0,
        1, 0, 0, 0,
        1, 0, 0, 0,
        1, 0, 0, 0;
    p1 << 1, 0, 0, 0;
    std::cout << "T: \n"
              << T << std::endl;
    std::cout << "p1: \n"
              << p1 << std::endl;

    std::cout << "p1: \n"
              << T * p1 << std::endl;
}

void GetHMatrixMidPose()
{
    Eigen::Matrix4d source2target;
    source2target << -0.998421, -0.0561693, -0.000284159, -1.84279,
        0.05617, -0.998408, -0.00505092, -0.606944,
        0, -0.0050589, 0.999987, 3.84917e-05,
        0, 0, 0, 1;

    std::cout << "source2target: \n"
              << source2target << std::endl;

    Eigen::Vector3d trans_source2target = source2target.block<3, 1>(0, 3);
    std::cout << "trans_source2target: \n"
              << trans_source2target << std::endl;

    Eigen::Matrix3d rot_source2target = source2target.block<3, 3>(0, 0);
    std::cout << "rot_source2target: \n"
              << rot_source2target << std::endl;

    // rot to Matrix4d
    Eigen::Matrix4d rot_source2target_h = Eigen::Matrix4d::Identity();
    rot_source2target_h.block<3, 3>(0, 0) = rot_source2target;
    std::cout << "rot_source2target_h: \n"
              << rot_source2target_h << std::endl;

    // trans to Matrix4d
    Eigen::Matrix4d trans_source2target_h = Eigen::Matrix4d::Identity();
    trans_source2target_h.block<3, 1>(0, 3) = trans_source2target;
    std::cout << "trans_source2target_h: \n"
              << trans_source2target_h << std::endl;

    // test source2target_h
    Eigen::Matrix4d source2target_h = trans_source2target_h * rot_source2target_h;
    std::cout << "source2target_h: \n"
              << source2target_h << std::endl;

    // half rot
    Eigen::Quaterniond q_source2target(rot_source2target);
    Eigen::Quaterniond half_q_source2target = Eigen::Quaterniond::Identity().slerp(0.5, q_source2target);
    Eigen::Matrix3d half_rot_source2target = half_q_source2target.toRotationMatrix();
    Eigen::Matrix4d half_rot_source2target_h = Eigen::Matrix4d::Identity();
    half_rot_source2target_h.block<3, 3>(0, 0) = half_rot_source2target;

    // half trans
    Eigen::Vector3d half_trans_source2target = trans_source2target / 2.0;
    Eigen::Matrix4d half_trans_source2target_h = Eigen::Matrix4d::Identity();
    half_trans_source2target_h.block<3, 1>(0, 3) = half_trans_source2target;

    Eigen::Matrix4d source2target_split = half_trans_source2target_h * half_rot_source2target_h * half_rot_source2target_h.inverse() * half_trans_source2target_h * half_rot_source2target_h * half_rot_source2target_h;
    // Eigen::Matrix4d source2target_split = half_trans_source2target_h * half_trans_source2target_h * half_rot_source2target_h * half_rot_source2target_h;
    std::cout << "source2target_split: \n"
              << source2target_split << std::endl;

    Eigen::Matrix4d h_source2base = half_trans_source2target_h * half_rot_source2target_h;
    Eigen::Matrix4d h_base2source = h_source2base.inverse();
    // Eigen::Matrix4d h_base2target = half_rot_source2target_h.inverse() * half_trans_source2target_h * half_rot_source2target_h * half_rot_source2target_h;
    Eigen::Matrix4d h_base2target = h_base2source * source2target;
    Eigen::Matrix4d h_source2target = h_source2base * h_base2target;

    std::cout << "h_base2source: \n"
              << h_base2source << std::endl;
    std::cout << "h_base2target: \n"
              << h_base2target << std::endl;
    std::cout << "h_source2target: \n"
              << h_source2target << std::endl;
}

int main()
{
    // test01_eigen_basic();
    // test02_quaternion();
    // test03_matrix_multi();

    GetHMatrixMidPose();

    return 0;
}
