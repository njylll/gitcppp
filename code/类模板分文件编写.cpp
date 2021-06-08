#include <iostream>
#include <string>
#include "person.cpp"
using namespace std;

//类模板分文件问题以及解决

// template<class T1,class T2>
// class Person
// {
// public:

//     Person(T1 name, T2 age);
//     void showPerson();

//     T1 m_Name;
//     T2 m_Age;
// };


// template<class T1, class T2>
//  Person<T1, T2>::Person(T1 name, T2 age)
//  {
//      this->m_Name = name;
//      this->m_Age = age;
//  }

//  template<class T1, class T2>
// void Person<T1, T2>::showPerson()
// {
//     cout << this->m_Name << endl << this->m_Age << endl;
// }

void test()
{
    Person<string, int>p1("lisi", 25);
    p1.showPerson();
}

int main()
{
    test();
    system("pause");
    return 0;
}