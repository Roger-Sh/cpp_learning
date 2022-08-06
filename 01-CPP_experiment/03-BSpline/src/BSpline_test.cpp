#include "math.h"
#include "BSpline.h"
#include "fstream"
#include "iomanip"

int main(int argc, char **argv)
{
    // int num_original_points = 8;
    // int num_interpolate_per_curve = 10;
    // double x[num_original_points] = {9.59, 60.81, 105.57, 161.59, 120.5, 100.1, 50.0, 10.0};
    // double y[num_original_points] = {61.97, 107.13, 56.56, 105.27, 120.5, 150.0, 110.0, 180.0};

    int num_original_points = 4;
    int num_interpolate_per_curve = 1000;
    double x[num_original_points] = {100.0, 200.0, 300.0, 300.0};
    double y[num_original_points] = {0, 50.0, -100.0, -200.0};

    // init CPosition
    CPosition *trail_bspline = new CPosition[num_original_points];
    for (int i = 0; i < num_original_points; i++)
    {
        trail_bspline[i] = CPosition(x[i], y[i]);
    }

    // interpolate num for each curve
    int *Intnum = new int[num_original_points - 1];
    for (int i = 0; i < num_original_points - 1; i++)
    {
        Intnum[i] = num_interpolate_per_curve; //
    }

    int num_after_interpolation = num_original_points;
    CBSpline bspline;

    // 二次B样条插值
    // bspline.TwoOrderBSplineInterpolatePt(trail_bspline, num_after_interpolation, Intnum);
    //  二次B样条平滑
    // bspline.TwoOrderBSplineSmooth(trail_bspline, num_after_interpolation);

    // 三次B样条插值
    bspline.ThreeOrderBSplineInterpolatePt(trail_bspline, num_after_interpolation, Intnum);
    // 三次B样条平滑
    // bspline.ThreeOrderBSplineSmooth(trail_bspline, num_after_interpolation);
    delete Intnum;

    // save original points
    std::ofstream file;
    file.open("trailpath_original.txt", std::ios::out);
    for (size_t i = 0; i < num_original_points; i++)
    {
        file << std::setprecision(3) << std::fixed
             << x[i] << " "
             << y[i] << " "
             << -200.0 << "\n";
    }
    file.close();

    // save smooth path
    file.open("trailpath_bspline.txt", std::ios::out);
    for (size_t i = 0; i < num_after_interpolation; i++)
    {
        file << std::setprecision(3) << std::fixed
             << trail_bspline[i].x << " "
             << trail_bspline[i].y << " "
             << -200.0 << "\n";
    }
    file.close();

    return 0;
}