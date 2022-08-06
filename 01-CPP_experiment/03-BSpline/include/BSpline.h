#pragma once

#include <iostream>
#include <stdlib.h>

//#include "position.h"

/**
 * @brief 点的数据结构, 提供相等的比较
 * 
 */
typedef struct tagPosition
{
    double x;
    double y;

    // 构造器
    tagPosition(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    tagPosition(){};

    // 相等比较
    bool operator==(const tagPosition &pt) 
    { 
        return (x == pt.x && y == pt.y); 
    }
} CPosition;


/**
 * @brief B样条类, 
 * 二次B样条平滑, 插值
 * 三次B样条平滑, 插值
 * 
 */
class CBSpline
{
public:
    CBSpline(void);
    ~CBSpline(void);

    /**
     * @brief 二次B样条平滑
     * 
     * @param pt 
     * @param Num 
     */
    void TwoOrderBSplineSmooth(CPosition *pt, int Num);
    
    /**
     * @brief 二次B样条插值
     * 
     * @param pt 
     * @param Num 
     * @param InsertNum 
     */
    void TwoOrderBSplineInterpolatePt(CPosition *&pt, int &Num, int *InsertNum);
   
    /**
    * @brief 二次B样条基函数
    * 
    * @param t 
    * @return double 
    */
    double F02(double t);   
    double F12(double t);   
    double F22(double t);   

    /**
     * @brief 三次B样条平滑
     * 
     * @param pt 
     * @param Num 
     */
    void ThreeOrderBSplineSmooth(CPosition *pt, int Num);
    
    /**
     * @brief 三次B样条插值
     * 
     * @param pt 
     * @param Num 
     * @param InsertNum 
     */
    void ThreeOrderBSplineInterpolatePt(CPosition *&pt, int &Num, int *InsertNum);
    
    /**
     * @brief 三次B样条基函数
     * 
     * @param t 
     * @return double 
     */
    double F03(double t);
    double F13(double t);
    double F23(double t);
    double F33(double t);
};


