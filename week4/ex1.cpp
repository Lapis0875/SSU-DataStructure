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
        this->year = year;
        this->month = month;
        this->day = day;
    }

    void showDate() {
        cout << "오늘은 " << year << " 년 " << month << " 월 " << day << " 일 입니다." << endl;
    }
};


int main(void)
{
    Date day(2023, 3, 24);
    day.showDate();
    return 0;
}