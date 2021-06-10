#include <iostream>
#include <string>
using namespace std;

void test()
{
    string str1 = "abcd";
    string str2 = "xbcd";
    int com = str1.compare(str2);
    if( com == 0)
    {
        cout << "str1 == st2 " << endl;
    }
    else if(com > 0)
    {
        cout << "str1大" << endl;
    }else cout << "str2大" << endl;

}

int main()
{

    test();
   // system("pause");
    return 0;
}
