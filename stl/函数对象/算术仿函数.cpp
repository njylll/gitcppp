#include <iostream>
#include <functional>
using namespace std;


//算数仿函数
//negaet 一元仿函数 取反仿函数
void test()
{
    negate<int>n;
    cout << n(50) << endl;;

}
/*  二元
    plus 加法
    minus//减
    multiplies//乘
    divides//除
    modulus//模
    negate//取反
*/
void test02()
{
    plus<int>p;
    cout << p(10,20) << endl;

}

int main()
{

    test();
    //system("pause");
    return 0;
}