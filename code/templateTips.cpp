#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    int m_age;
    string m_name;
};

//ģ��ע������
//1.�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
template<typename T>//typename�����滻��class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


void test()
{
    int a = 10;
    int b =20;
    char c = 'c';
    //mySwap(a, b);//��ȷ
    //mySwap(a, c);//�����Ƶ�����һ�µ�����T
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}

//2.ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��


template<typename T>
void func()
{
    cout << "func����" << endl;

}
void test02()
{
    //func();//δ������������
    func<int>();
}
/*��ͨ�����뺯��ģ��ĵ��ù���
1.�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
2.����ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
����myPrint<>(a, b);
3.����ģ����Է�����������
4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
*/

//ģ�������
//�Ա����������Ƿ����
template<class T>
bool myCompare(T &a, T &b)
{
    if(a == b)
    {
        return true;
    }
    else return false;
}

//���þ��廯Person�汾ʵ�ֱȽϴ��룬���ȵ���
template<> bool myCompare(Person &p1, Person &p2)
{
    if(p1.m_name == p2.m_name && p1.m_age == p2.m_age)
    {
        return true;
    }
    else return false;
}

void test03()
{
    int a = 10;
    int b = 20;
    bool result = myCompare(a, b);
    if(result)
    {
        cout << "���" << endl;

    }else cout << "�����" << endl;

}
void test04()
{
    Person p1 = {"tom", 10};
    Person p2 ={"tom", 10};
    bool result = myCompare(p1, p2);
     if(result)
    {
        cout << "p1 == p2" << endl;

    }else cout << "p1 != p2" << endl;

}


int main()
{
   // test02();
    //test();
    test03();
    test04();
    system("pause");
    return 0;
}