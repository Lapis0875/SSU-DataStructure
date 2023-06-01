#include <iostream>
#include <string>

using namespace std;

template <typename T>
class DynamicArray
{
private:
    T *arr;
    int size;
public:
    DynamicArray(int size): size(size)
    {
        arr = new T[size];
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void setValue(int index, T value)
    {
        arr[index] = value;
    }

    T getValue(int index)
    {
        return arr[index];
    }
};

template <typename T>
class Vector
{
private:
    T* arr;
    int size;
    int capacity;
public:
    Vector(int capacity): size(0), capacity(capacity)
    {
        arr = new T[capacity];
    }

    ~Vector()
    {
        delete[] arr;
    }

    void grow(int amount)
    {
        capacity += amount;
        cout << capacity << size << endl;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void push(T value)
    {
        if (size == capacity)
            grow(3);
        arr[size++] = value;
    }

    void pop()
    {
        return arr[--size];
    }

    void insert(int index, T value)
    {
        if (size + 1 >= capacity)
            grow(3);
        
        for (int i = index + 1; i < size; i++)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
        size++;
    }

    T get(int index)
    {
        return arr[index];
    }

    // for~each iteration support
    typedef T* iterator;
    typedef const T* const_iterator;
    iterator begin()
    {
        return &arr[0];
    }

    const_iterator begin() const
    {
        return &arr[0];
    }

    // for~each iteration support
    iterator end()
    {
        return &arr[size];
    }

    const_iterator end() const
    {
        return &arr[size];
    }
};

int main(void)
{
    DynamicArray<int> intArray(5);

    intArray.setValue(0, 10);
    intArray.setValue(1, 20);
    cout << "Value at index 0: " << intArray.getValue(0) << endl;
    cout << "Value at index 1: " << intArray.getValue(1) << endl;

    DynamicArray<double> doubleArray(3);

    doubleArray.setValue(0, 3.14);
    doubleArray.setValue(1, 2.71);
    cout << "Value at index 0: " << doubleArray.getValue(0) << endl;
    cout << "Value at index 1: " << doubleArray.getValue(1) << endl;

    Vector<int> vec(3);

    vec.push(10);
    vec.push(20);
    vec.push(30);

    for(int i: vec)
    {
        cout << i << endl;
    }

    vec.push(40);

    for(int i: vec)
    {
        cout << i << endl;
    }

    return 0;
}