#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
    T m;
};

class Son:public Base<int>//����֪������T�����ͣ����ܼ̳�
{

};

//��������ָ��������T�����ͣ�����Ҳ��Ҫ����ģ��
template<class T1, class T2>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
        
    }
    T1 obj;
};


void test()
{
    Son s1;
    s1.m = 10;
    cout << s1.m << endl;

    Son2<int, char>S2;

}

int main()
{
    test();
    system("pause");
    return 0;
}