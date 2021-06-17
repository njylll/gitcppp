#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//内置数据类型
class GreaterFive
{
public:
    bool operator()(const int &val)
    {
        return val > 2;

    }
};

void test()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int num = count_if(v.begin(), v.end(), GreaterFive());
    cout << num << endl;

}

//自定义数据类型
 class Person
 {
public:
    Person(string name, int age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }
    string m_Name;
    int m_Age;
 };


 class MyCountIf
 {
public:
    bool operator()(const Person&p)
    {
        return p.m_Age < 30;
    }

 };

 void test02()
 {
     vector<Person>v;
     Person p1("a", 10);
     Person p2("b", 20);
     Person p3("c", 30);
     Person p4("d", 40);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    int num = count_if(v.begin(), v.end(), MyCountIf());
    cout << num << endl;
 }

int main()
{

    test();
    test02();
   // system("pause");
    return 0;
}