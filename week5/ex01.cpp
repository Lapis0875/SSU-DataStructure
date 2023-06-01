#include <iostream>
#include <cstring>

using namespace std;

class Computer {
private:
    char owner[50];

public:
    Computer(char* name) {
        strcpy(owner, name);
    }

    void calculate() {
        cout << "요청 내용을 계산합니다." << endl;
    }
};

class NotebookComp : public Computer {
private:
    int battery;
public:
    NotebookComp(char* name, int initChag) : Computer(name), battery(initChag) {}

    void charge() {
        battery += 5;
    }

    void useBattery() {
        battery -= 1;
    }

    void movingCal() {
        if (getBatteryInfo() < 1) {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        cout << "이동하면서 ";
        calculate();
        useBattery();
    }

    int getBatteryInfo() {
        return battery;
    }

};

class TabletNotebook : public NotebookComp {
private:
    char regstPenModel[50];
public:
    // sleepy
    TabletNotebook(char* name, int initChag, char* pen) : NotebookComp(name, initChag) {
        strcpy(regstPenModel, pen);
    }

    void write(char* peninfo) {
        if (getBatteryInfo() < 1) {
            cout << "충전이 필요합니다." << endl;
            return;
        }

        if (strcmp(regstPenModel, peninfo)) {
            cout << "등록된 펜이 아닙니다." << endl;
            return;
        }

        cout << "필기 내용을 처리합니다." << endl;
        useBattery();
    }
};

int main(void) {
    NotebookComp nc("이수종", 5);
    TabletNotebook tn("이수종", 5, "ISE-241-242");

    nc.movingCal();
    tn.write("ISE-241-242");
    return 0;
}