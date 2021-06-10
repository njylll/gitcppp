#include <iostream>
#include <string>
using namespace std;


void test()
{
    string str = "hello";
    cout << str << endl;
    //通过[]访问单个字符
    for(int i = 0;i < str.size(); i++)
    {
        cout << str[i] << " " ;
    }
    //通过访问at方式访问单个字符
    cout << endl;
    for(int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " " ;
    }
    cout << endl;

    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;

}

int main()
{

    test();
    system("pause");
    return 0;
}
