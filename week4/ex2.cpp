#include <iostream>

using std::cout;
using std::endl;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day) {
        cout << "인자가 3개인 개인 생성자 호출" << endl;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    Date() {
        cout << "기본 생성자 호출" << endl;
        this->year = 2023;
        this->month = 3;
        this->day = 24;
    }

    void showDate();
};

void Date::showDate() {
    cout << "오늘은 " << year << " 년 " << month << " 월 " << day << " 일 입니다." << endl;
}


int main(void)
{
    Date day(2023, 3, 23);
    Date day2 = Date();
    day.showDate();
    day2.showDate();
    return 0;
}