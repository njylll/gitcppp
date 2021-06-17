#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//内置数据类型
class GreatFive
{
public:
    bool operator()(const int val)
    {
        return val > 5;
    }
};

void test()
{
vector<int>v;
for(int i = 0; i < 10; i++)
{
    v.push_back(i);
}

vector<int>::iterator it = find_if(v.begin(),v.end(), GreatFive());
if(it == v.end())
{
    cout << "没找到" << endl;
}
else 
{
    cout << "找到：" << *it << endl;
}
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

public:
    string m_Name;
    int m_Age;
};

class myFindIf
{
public:
    myFindIf(int age)
    {
        this->age = age;
    }
    bool operator()(const Person &p)
    {
        return p.m_Age == age;
    }
    int age;
};


void test02()
{
    vector<Person>v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);
    Person p5("e", 50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    cout << "请输入要查找的年龄：" ;
    int age;
    cin >> age;
    vector<Person>::iterator it = find_if(v.begin(), v.end(),myFindIf(age));
    if(it == v.end())
    {
        cout << "没找到" << endl;
    }
    else 
    {
        cout << "找到：" << it->m_Name << " " << it->m_Age;
    }

}
int main()
{

    test();
    test02();
    //system("pause");
    return 0;
}