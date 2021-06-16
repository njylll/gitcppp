#include <iostream>
#include <set>
using namespace std;

class Person
{
public:
    Person(string name, int age):m_Name(name),m_Age(age){}
    string m_Name;
    int m_Age;
};

class myCompare
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        //按年龄降序
        return p1.m_Age > p2.m_Age;
    }
};

void test()
{
    set<Person, myCompare>s;

    Person p1("刘备", 24);
    Person p2("关羽", 66);
    Person p3("张飞", 56);
    Person p4("赵云", 69);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);


    for(set<Person, myCompare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
    }



}

int main()
{

    test();
    system("pause");
    return 0;
}