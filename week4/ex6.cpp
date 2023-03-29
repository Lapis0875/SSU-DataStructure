#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Girl;

class Boy {
private:
    int height;
    friend class Girl;
public:
    Boy(int height) : height(height) {}

    void showYourFriendInfo(Girl &frn);
};

class Girl {
private:
    char phNum[20];
public:
    Girl(const char* num) {
        strcpy(this->phNum, num);
    }

    void showYourFriendInfo(Boy &frn);
    friend class Boy;
};

void Boy::showYourFriendInfo(Girl &frn) {
    cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::showYourFriendInfo(Boy &frn) {
    cout << "His height: " << frn.height << endl;
}


int main(void)
{
    Boy boy(170);
    Girl girl = Girl("010-1234-5678");
    boy.showYourFriendInfo(girl);
    girl.showYourFriendInfo(boy);
    return 0;
}