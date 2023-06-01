#include <iostream>

using std::cout;
using std::endl;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    
    void showPosition() const       // Q1. 함수 뒤 const의 의미?
    {
        // When you add the const keyword to a method the this pointer will essentially become a pointer to const object,
        // and you cannot therefore change any member data.
        cout << '[' << xpos << ',' << ypos << ']' << endl;
    }

    Point operator+(const Point &ref)
    {
        Point pos = Point(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
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
};

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
    // (10 * p1).showPosition();
    (p2 / 5).showPosition();
    return 0;
}