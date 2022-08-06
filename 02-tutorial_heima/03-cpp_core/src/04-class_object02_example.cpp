#include <iostream>

using namespace std;


class Cube
{
public:
    int m_L;
    int m_H;
    int m_W;

public:
    bool compareCube(class Cube c1)
    {
        if (c1.m_H*c1.m_L*c1.m_W == m_L*m_H*m_W)
        {
            if (c1.m_H == m_H )
            {
                if (c1.m_L == m_L || c1.m_L == m_W)
                {
                    return 1;
                }
            }
            else if(c1.m_H == m_L)
            {
                if (c1.m_L == m_H || c1.m_L == m_W )
                {
                    return 1;
                }
            }
            else if(c1.m_H == m_W)
            {
                if (c1.m_L == m_H || c1.m_L == m_L)
                {
                    return 1;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

        return 0;
    }

};



class Point
{
public:
    int m_x;
    int m_y;
};


class Circle
{
public:
    int m_x;
    int m_y;
    int m_r;

public:
    
    void chechPointinCircle(Point p)
    {
        int d2 = (p.m_x - m_x)*(p.m_x - m_x) + 
                 (p.m_y - m_y)*(p.m_y - m_y);

        if (d2 < m_r*m_r)
        {
            cout << "Point is in the circle" << endl;
        }
        else if (d2 > m_r*m_r)
        { 
            cout << "Point is outside the circle" << endl;
        }
        else{
            cout << "Point is on the circle" << endl;
        }
    }

};


int main()
{
    // 判断两个立方体是否相等
    Cube c1;
    c1.m_H = 1;
    c1.m_L = 3;
    c1.m_W = 4;

    Cube c2;
    c2.m_H = 3;
    c2.m_L = 1;
    c2.m_W = 4;
    
    cout << c1.compareCube(c2) << endl;


    // 判断点和圆的关系
    Circle c3;
    c3.m_x = 2;
    c3.m_y = 5;
    c3.m_r = 10;

    Point p1;
    p1.m_x = 5;
    p1.m_y = 6;

    c3.chechPointinCircle(p1);


    return 0;
}