#include <iostream>
#include <string>
using namespace std;

//类外实现
template<class T1, class T2>
class Person;


template<class T1, class T2>
void printPerson02(Person<T1, T2> &p)
{
    cout << p.m_Name << p.m_Age << endl;
}
//通过全局函数，打印Person信息
template<class T1, class T2>
class Person
{
    //全局函数类内实现
    friend void printPerson(Person<T1, T2> &p)
    {
        cout << p.m_Name << p.m_Age << endl;
    }
    //全局函数类外实现
    //加空模板参数列表
    //如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson02<>(Person<T1, T2> &p);
   
public:
    Person(T1 name, T2 age):m_Name(name), m_Age(age){}


private:
    T1 m_Name;
    T2 m_Age;
};



void test()
{
    Person<string, int> p("lisi", 18);
    Person<string, int> p2("wangwu", 10);
    printPerson(p);
    printPerson02(p2);


}

int main()
{
    test();
    system("pause");
    return 0;
}