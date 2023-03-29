#include <iostream>

using namespace std;

class FruitSeller {
private:
    // 멤버 변수
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    // 멤버 함수
    int sellApples(int money) {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void initMembers(int price, int num, int money) {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    void showSalesResult() {
        cout << "남은 사과 : " << numOfApples << endl;
        cout << "판매 수익 : " << myMoney << endl;
    }
};

class FruitBuyer {
    int myMoney;
    int numOfApples;

public:
    void initMembers(int money) {
        myMoney = money;
        numOfApples = 0;
    }

    void buyApples(FruitSeller &seller, int money) {
        numOfApples += seller.sellApples(money);
        myMoney -= money;
    }

    void showBuyResult() {
        cout << "현재 잔액 : " << myMoney << endl;
        cout << "사과 개수 : " << numOfApples << endl;
    }
};

int main(void)
{
    FruitSeller seller;                     // 일반적인 변수 선언 방식의 객체 생성
    seller.initMembers(1000, 20, 0);

    FruitBuyer* buyer = new FruitBuyer;     // 동적 할당 방식의 객체 생성
    buyer->initMembers(5000);

    buyer->buyApples(seller, 2000);

    cout << "과일 판매자의 현황:" << endl;
    seller.showSalesResult();

    cout << "과일 구매자의 현황:" << endl;
    buyer->showBuyResult();

    return 0;
}