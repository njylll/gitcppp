#include <iostream>
#include <string>
using namespace std;

void test()
{
    string str = "hello";
    str.insert(1,"111");//在索引位置为1的字符前插入"111"
    cout << str << endl;//h111elo 

    //删除
    str.erase(1,3);//从索引位置为1的字符起，删除3个字符
    cout << str << endl;
}

int main()
{

    test();
    //system("pause");
    return 0;
}
