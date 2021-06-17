#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//统计内置数据类型
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    int num = count(v.begin(), v.end(), 20);
    cout << num << endl;

}


//统计自定义数据类型
class Person
{
public:
 Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    bool operator==(const Person &p)
    {
        return this->m_Age == p.m_Age;
    }

public:
    string m_Name;
    int m_Age;
};
void test02()
{
    vector<Person>v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 20);
    Person p5("e", 20);
    v.push_back(p1);
     v.push_back(p2);
      v.push_back(p3);
       v.push_back(p4);
        v.push_back(p5);
    int num = count(v.begin(), v.end(),Person("f",10));
    cout << num << endl;
}
int main()
{

   // test();
    test02();
   // system("pause");
    return 0;
}