#include <iostream>
#include <string>
using namespace std;

void test()
{
    string str1;
    str1 = "Hello World" ;//char*字符串赋值
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;//字符串赋值
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = "a";//可以把字符赋给字符串
    //str3.append(str1);
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hello c++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello c++",5);//将字符串的前n个字符赋给当前字符串
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5,3,1);//索引位置3开始的1个字符赋值给str6
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(5,'a');
    cout << "str7 = " << str7 << endl;

}

int main()
{

    test();
    system("pause");
    return 0;
}
