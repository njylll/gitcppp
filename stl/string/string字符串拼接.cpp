#include <iostream>
#include <string>
using namespace std;

void test()
{
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1 = " << str1 << endl;
    str1 += ':';
    cout << "str1 = " << str1 << endl;
    string str2 = "lol DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << "str3 = " << str3 << endl;
    str3.append("game abd", 4);//取前四个字符
    cout << "str3 = " << str3 << endl;
    str3.append(str2,0,3);//从第0个开始，截取三个字符
    cout << "str3 = " << str3 << endl;
    str3.append(str2,4,3);//从第4个开始，截取三个字符
    cout << "str3 = " << str3 << endl;



}

int main()
{

    test();
    //system("pause");
    return 0;
}
