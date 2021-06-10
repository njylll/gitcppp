#include <iostream>
#include <string>
using namespace std;


void test()
{
    string s1;//默认构造
    const char * str = "Hello World !";
    string s2(str);//使用字符串s初始化
    cout << "s2 = " << s2 << endl;
    string s3(s2);//使用一个string对象初始化另一个string对象
    cout << "s3 = " << s3 << endl;
    string s4(10,'a');//使用n个c字符初始化
     cout << "s4 = " << s4 << endl;
    string s5("bbbbbbbb");
     cout << "s5 = " << s5 << endl;


}

int main()
{

    test();
    system("pause");
    return 0;
}
