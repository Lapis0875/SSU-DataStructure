#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
    char name[50];
public:
    Employee(char* name)
    {
        strcpy(this->name, name);
    }

    void showYourName() const
    {
        cout << "name: " << name << endl;
    }

    int getPay() const;
    void showSalaryInfo() const;
};

class PermanentWorker : public Employee
{
private:
    int salary;
public:
    PermanentWorker(char* name, int money) : Employee(name), salary(money) {}

    int getPay() const
    {
        return salary;
    }

    void showSalaryInfo() const
    {
        showYourName();
        cout << "salary: " << getPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee 
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(char* name, int pay): Employee(name), workTime(0), payPerHour(pay) {}

    void addWorkTime(int time)
    {
        workTime += time;
    }

    int getPay() const
    {
        return workTime * payPerHour;
    }

    int showSalaryInfo() const
    {
        showYourName();
        cout << "salary: " << getPay() << endl << endl;
    }
};

class SalesWorker: public Employee
{
private:
    int salesResult;    // 월 판매실적
    double bonusRatio;  // 상여금 비율
public:
    SalesWorker(char* name, int money, double ratio): Employee(name), salesResult(money), bonusRatio(ratio) {}

    void addSalesResult(int value)
    {
        salesResult += value;
    }

    int getPay() const
    {
        // PermanentWorker의 getPay() 함수 호출.
        return PermanentWorker::getPay() + (int) salesResult * bonusRatio;
    }

    void showSalaryInfo() const
    {
        showYourName();
        cout << "salary: " << getPay() << endl << endl;     // SalesWorker의 getPay() 함수 호출.
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler(): empNum(0) {}

    void addEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }

    void showAllSallaryInfo() const {
        for (int i = 0; i < empNum; i++) {
            empList[i]->showSalaryInfo();
        }
    }

    void showTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++) {
            sum += empList[i]->getPay();
        }
        cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++) {
            delete empList[i];
        }
    }
};

int main(void) {
    EmployeeHandler handler;

    handler.addEmployee(new PermanentWorker("KIM", 1000));
    handler.addEmployee(new TemporaryWorker("LEE", 500));
    handler.addEmployee(new SalesWorker("JUN", 2000, 0.2));

    handler.showAllSallaryInfo();
    handler.showTotalSalary();
    return 0;
}