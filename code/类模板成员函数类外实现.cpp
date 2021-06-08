#include <iostream>
#include <string>
using namespace std;


template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    // {
    //     m_Name = name;
    //     m_age = age;
    // }

    void showPerson();
    // {
    //      cout << m_Name << endl << m_age << endl;
    // }

    T1 m_Name;
    T2 m_age;
};
//构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
     m_Name = name;
     m_age = age;
}


//成员函数类外实现
template<class T1, class T2>
 void Person<T1, T2>::showPerson()
 {
     cout << m_Name << endl << m_age << endl;
 }

void test()
{
    Person<string, int> p1("lisi", 45);
    p1.showPerson();
    
}

int main()
{
    test();
    system("pause");
    return 0;
}