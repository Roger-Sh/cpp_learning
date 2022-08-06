#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <Eigen/Dense>

/**
 * @brief get 3d-points vector, interpolate points between them, save as txt file
 * 
 */
void trail_generate(std::vector<Eigen::Vector3f> init_points)
{
    float vec_inter_rate = 1/8.0;

    // check init points
    std::cout << "check init_points" << std::endl;
    for (size_t i = 0; i < init_points.size(); i++)
    {
        std::cout << i << ": \n" << init_points[i] << std::endl; 
    }

    // init trail
    std::vector<Eigen::Vector3f> trail;
    trail.push_back(init_points[0]);

    // interpolate
    for (size_t i = 0; i < init_points.size()-1; i++)
    {
        Eigen::Vector3f segment_start = init_points[i];
        Eigen::Vector3f segment_end = init_points[i+1];

        Eigen::Vector3f vec_segment = segment_end - segment_start;
        Eigen::Vector3f vec_unit = vec_segment/vec_segment.norm();

        std::cout << "segment_start: \n" << segment_start << std::endl;
        std::cout << "segment_end: \n" << segment_end << std::endl;
        std::cout << "vec_segment: \n" << vec_segment << std::endl;
        std::cout << "vec_unit: \n" << vec_unit << std::endl;

        while(true)
        {
            Eigen::Vector3f point_next = trail.back() + vec_unit*vec_inter_rate;
            std::cout << "point_next: \n" << point_next << std::endl;
            
            // check goal point
            Eigen::Vector3f vec_next = point_next - segment_start;
            std::cout << "vec_next: \n" << vec_next << std::endl;

            if (vec_next.norm() > vec_segment.norm())
            {
                std::cout << "reach segment end" << std::endl;
                break;
            }
            
            trail.push_back(point_next);
        }
    }
    
    // save
    std::ofstream file;
    file.open("./trailpath_seg.txt", std::ios::out);

    for (size_t i = 0; i < trail.size(); i++)
    {
        file << std::setprecision(3) << std::fixed
            << trail[i](0) << " "
            << trail[i](1) << " "
            << trail[i](2) << "\n";
    }
    file.close();
}

int main(int argc, char** argv)
{
    Eigen::Vector3f p1;
    p1 << 100, 0, -200;

    Eigen::Vector3f p2;
    p2 << 200, 50, -200;

    Eigen::Vector3f p3;
    p3 << 300, -100, -200;

    Eigen::Vector3f p4;
    p4 << 300, -200, -200;

    std::vector<Eigen::Vector3f> init_points;
    init_points.push_back(p1);
    init_points.push_back(p2);
    init_points.push_back(p3);
    init_points.push_back(p4);

    trail_generate(init_points);

    return 0;
}
