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

    //尾插法
    void Push_Back(const T& val)
    {
        if(this->m_Capacity == this->m_Size)
        {
            cout << "已满" << endl;
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }
    //尾删法:让用户访问不到最后一个元素
    void Pop_Back()
    {
        if(this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    //通过下标访问元素
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    int getCapacity()
    {
        return this->m_Capacity;
    }

    int size()
    {
        return this->m_Size;
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
    arr1.Push_Back(1);
    cout << "arr1[1] = " << arr1[1] << endl;
   // MyArray<int> arr2(arr1);
    //MyArray<int> arr3(100);
    //arr3 = arr1;
}

int main()
{
    test01();
    return 0;
}