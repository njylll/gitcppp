#include <iostream>
using namespace std;

//查找
void test()
{
    string str1 = "abscdsvcd";
    int pos = str1.find("cd",1);//从第n个索引位置开始找，找到返回索引位置，找不到返回-1
    if(pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    cout << "pos = " << pos << endl;

    //rfind和find的区别
    //rfind从右往左查找 find从左往右查找
    pos = str1.rfind("cd");
    cout << "pos = " << pos << endl;

}

//替换
void test02()
{
    string str2 = "abvcdvv";
    str2.replace(1,3,"1111");//从第1个索引位置起的3个字符替换为"s1111"
    cout << str2 << endl;

}

int main()
{

    test();
    test02();
    system("pause");
    return 0;
}
