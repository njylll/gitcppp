#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//查找内置数据类型
void test()
{
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if(it != v.end())
    {
        cout << "找到" << *it << endl;
    }else cout << "没找到" << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    //重载 == ，让find知道如何对比
    bool operator==(const Person&p)//必须const
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
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

    vector<Person>::iterator it = find(v.begin(), v.end(), Person("b",30));
    if(it == v.end())
    {
        cout << "没找到" << endl;
    }
    else{
        cout << "找到" << it->m_Name << " " << it->m_Age << endl;
    }
}



//查找自定义数据类型
int main()
{

    test();
    test02();
    system("pause");
    return 0;
}