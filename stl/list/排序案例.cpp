#include <iostream>
using namespace std;
#include <string>
#include <list>

class Person
{
public:
    Person(string name,int age,int height):m_Name(name),m_Age(age),m_Height(height){}

    string m_Name;
    int m_Age;
    int m_Height;

};


void printList(const list<Person>&p)
{
    for(list<Person>::const_iterator it = p.begin(); it != p.end();it++)
    {
        cout << "姓名为：" << it->m_Name << " 年龄为：" << it->m_Age << " 身高为:" << it->m_Height;
        cout << endl;
    }
    
}

//指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    //按照年龄 升序

    if(p1.m_Age == p2.m_Age)
    {
        //年龄相同，身高降序
        return p1.m_Height > p2.m_Height;
    }
    else return p1.m_Age < p2.m_Age;

}
void test()
{
    list<Person>l;
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    printList(l);

    cout << "------------排序后-------------" << endl;
    l.sort(comparePerson);
    printList(l);
}

int main()
{

    test();
    //system("pause");
    return 0;
}