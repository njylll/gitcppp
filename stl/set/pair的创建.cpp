#include <iostream>
using namespace std;

void test()
{
    //第一种方式
    pair<string, int>p("tom", 30);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

    //第二种方式
    pair<string, int>p2 = make_pair("tom" ,18);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

int main()
{

    test();
    system("pause");
    return 0;
}