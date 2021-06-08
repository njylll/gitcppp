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

//模板注意事项
//1.自动类型推导，必须推导出一致的数据类型T才可以使用
template<typename T>//typename可以替换成class
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
    //mySwap(a, b);//正确
    //mySwap(a, c);//错误，推导不出一致的类型T
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}

//2.模板必须要确定出T的数据类型，才可以使用


template<typename T>
void func()
{
    cout << "func调用" << endl;

}
void test02()
{
    //func();//未给出数据类型
    func<int>();
}
/*普通函数与函数模板的调用规则
1.如果函数模板和普通函数都可以调用，优先调用普通函数
2.可以通过空模板参数列表，强制调用函数模板
例：myPrint<>(a, b);
3.函数模板可以发生函数重载
4.如果函数模板可以产生更好的匹配，优先调用函数模板
*/

//模板局限性
//对比两个数据是否相等
template<class T>
bool myCompare(T &a, T &b)
{
    if(a == b)
    {
        return true;
    }
    else return false;
}

//利用具体化Person版本实现比较代码，优先调用
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
        cout << "相等" << endl;

    }else cout << "不相等" << endl;

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