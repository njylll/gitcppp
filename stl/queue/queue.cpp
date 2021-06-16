#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name,int age):m_Name(name),m_Age(age){}
    string m_Name;
    int m_Age;
};

void test()
{
    queue<Person>q;
    
    Person p1("唐僧",99);
    Person p2("zhu", 88);
    Person p3("shu",89);
    Person p4("sdas",99);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while(!q.empty())  
    {
        //查看队头元素
        cout << "队头元素为: " <<  q.front().m_Name << " " << q.front().m_Age <<  endl;

        //查看队尾元素
        cout << "队尾元素为：" << q.back().m_Name << " " << q.back().m_Age << endl;

        q.pop();
    }

    cout << "队列大小为" << q.size() << endl;
}

int main()
{

    test();
    system("pause");
    return 0;
}