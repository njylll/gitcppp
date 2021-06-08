#include <iostream>
#include <string>
using namespace std;
//��ģ��û���Զ������Ƶ�
//��ģ����ģ������б��п�����Ĭ�ϲ���
template<class NameType, class AgeType = int>
class Person
{
public:

    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showInfo()
    {
        cout << "name: " << this->m_Name << endl;
        cout << "age: " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType  m_Age;
};





void test01()
{
    Person<string, int> p1("wangwu", 15);
    p1.showInfo();
}

void test02()
{
    Person<string> p2("lisi", 999);
    p2.showInfo();
}
//��ģ���������������
//1.ָ����������
//2.����ģ�廯
//3.������ģ�廯

template<class T1, class T2>
class Person01
{
public:
    Person01(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name <<" age: " << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

void printPerson1(Person01<string, int>&p)
{
    p.showPerson();
}

template<class T1, class T2>
void printPerson2(Person01<T1, T2>&p)
{
    p.showPerson();
    cout << typeid(T1).name() << endl;
    
}

template<class T>
void printPerson3(T &p)
{
    p.showPerson();
}

void test03()
{
    Person01<string, int> p1("zhangsan", 100);
    printPerson1(p1);
    printPerson2(p1);
    printPerson3(p1);
}

int main()
{

   // test01();
    //test02();
    test03();
    system("pause");
    return 0;
}