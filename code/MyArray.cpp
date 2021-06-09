#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:

    MyArray(int capacity)
    {
        cout << "有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    //防止浅拷贝，写拷贝构造函数
    MyArray(const MyArray &arr)
    {
        cout << "拷贝构造函数调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];
        //将arr中的数据拷贝过来
        for(int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    //operator=，防止浅拷贝
    MyArray& operator=(const MyArray& arr)
    {
        cout << "operator调用" << endl;
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0;i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    ~MyArray()
    {
        cout << "析构函数调用" << endl; 
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
private:
    T *pAddress;
    int m_Capacity;
    int m_Size;
};

void test01()
{
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;
}

int main()
{
    test01();
    return 0;
}