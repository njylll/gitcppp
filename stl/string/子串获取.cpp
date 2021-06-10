#include <iostream>
#include <string>
using namespace std;

void test()
{
    string str = "abcdef";
    string subStr = str.substr(1,3);//bcd
    cout << subStr << endl;


}

void test02()
{
    //截取用户名
    string email = "njylll@sina.com";
    int pos = email.find("@");
    string usrName = email.substr(0,pos);
    cout << usrName <<endl;

}

int main()
{

    //test();
    test02();
    system("pause");
    return 0;
}
