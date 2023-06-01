#include <iostream>

using std::cout;
using std::endl;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    
    void showPosition() const
    {
        cout << '[' << xpos << ',' << ypos << ']' << endl;
    }

    Point operator-(const Point &ref)
    {
        Point pos = Point(xpos - ref.xpos, ypos - ref.ypos);
        return pos;
    }

    Point operator*(const int &ref)
    {
        Point pos = Point(xpos * ref, ypos * ref);
        return pos;
    }

    Point operator/(const int &ref)
    {
        Point pos = Point(xpos / ref, ypos / ref);
        return pos;
    }

    friend Point operator+(const Point &pos1, const Point &pos2);
    friend Point operator*(const int &scala, const Point &pos);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point res = Point(pos1.xpos * pos2.xpos, pos1.ypos * pos2.ypos);
    return res;
}

/**
 * @brief int * Point 연산을 지원함
 * 
 * @param scala 좌표의 정수배에 쓰일 스칼라 값.
 * @param pos 좌표 객체
 * @return 계산된 새 Point 객체
 */
Point operator*(const int &scala, const Point &pos)
{
    Point res = Point(scala * pos.xpos, scala * pos.ypos);
    return res;
}

int main(void)
{
    Point p1 = Point(3, 4);
    Point p2 = Point(10, 20);
    Point p3 = p1 + p2;
    Point p4 = p1 - p2;
    
    p1.showPosition();
    p2.showPosition();
    p3.showPosition();
    p4.showPosition();

    (p1 * 3).showPosition();
    (10 * p1).showPosition();
    (p2 / 5).showPosition();
    return 0;
}