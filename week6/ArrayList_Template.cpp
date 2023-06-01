#include <iostream>
#define MAX_LIST_SIZE 100

using namespace std;

inline void error (char* str) {
    cout << stderr << str << endl;

    exit(1);
}

template <typename T>
class ArrayList
{
private:
    T data[MAX_LIST_SIZE];
    int length;
public:
    ArrayList(void) : length(0) {}
    
    /**
     * @brief 주어진 위치에 새 요소를 삽입함.
     * 
     * @param pos 새 요소를 삽입할 위치.
     * @param e 새 요소.
     */
    void insert(int pos, T e)
    {
        if (isFull())
            return error("리스트가 가득 찼습니다.");
        if (pos < 0 || pos > length)
            return error("잘못된 위치입니다.");

        for (int i = length; i > pos; i--)
        {
            data[i] = data[i-1];
        }
        data[pos] = e;
        length++;
    }

    /**
     * @brief 주어진 위치의 요소를 삭제함.
     * 
     * @param pos 요소를 삭제할 위치.
     */
    void remove(int pos)
    {
        if (isEmpty())
            return error("리스트가 비어 있습니다.");
        
        if (pos < 0 || pos > length)
            return error("잘못된 위치입니다.");
        
        for (int i = pos + 1; i < length; i++)
            data[i-1] = data[i];
        length--;
    }

    /**
     * @brief 주어진 위치의 요소를 반환함.
     * 
     * @param pos 요소의 위치.
     */
    T getEntry(int pos)
    {
        return data[pos];
    }

    /**
     * @brief 현재 리스트가 비어있는지 확인함.
     * 
     * @return true 리스트가 비어 있음.
     * @return false 리스트가 비어 있지 않음.
     */
    bool isEmpty()
    {
        return length == 0;
    }

    /**
     * @brief 현재 리스트가 가득 차 있는지 확인함.
     * 
     * @return true 리스트가 가득 차 있음.
     * @return false 리스트가 가득 차 있지 않음.
     */
    bool isFull()
    {
        return length == MAX_LIST_SIZE;
    }

    /**
     * @brief 주어진 요소가 리스트 내에 존재하는지 검사함.
     * 
     * @param item 검사할 요소.
     * @return true 주어진 요소가 리스트 내부에 존재함.
     * @return false 주어진 요소가 리스트 내부에 존재하지 않음.
     */
    bool find(T item)
    {
        for (T e: data)
            if (e == item)
                return true;
    }

    /**
     * @brief 주어진 위치의 요소를 새 요소로 대체함.
     * 
     * @param pos 대체할 요소의 위치.
     * @param e 새 요소.
     */
    void replace(int pos, T e)
    {
        data[pos] = e;
    }

    /**
     * @brief 리스트의 길이를 반환함.
     * 
     * @return int 리스트의 길이.
     */
    int size()
    {
        return length;
    }

    /**
     * @brief 리스트의 원소를 모두 출력함.
     */
    void display()
    {
        cout << "배열로 구현한 리스트의 전체 항목의 개수 = " << length << endl;
        for (int i = 0; i < length; i++) {
            cout << "[" << data[i] << "] ";
            cout << endl;
        }
    }


    /**
     * @brief 리스트를 초기화함.
     */
    void clear()
    {
        length = 0;
    }
};

int main(void)
{
    ArrayList<int> list;

    list.display();

    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(0, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);

    list.replace(1, 90);
    list.display();

    list.clear();
    list.display();

    return 0;
}