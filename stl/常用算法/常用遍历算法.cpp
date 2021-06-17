#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


//普通函数
void print01(int val)
{
    cout << val << " ";
}

//仿函数
class Print
{
public:
    void operator()(int v)
    {
        cout << v << " ";

    }

};
void test()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    // for(int i = 0; i < 10; i ++)
    // {
    //     v. push_back(i);
    // }
    for_each(v.begin(),v.end(),print01);
    cout << endl;
    for_each(v.begin(), v.end(),Print());
    // for(auto i : v)
    // {
    //     cout << i << " ";
    //  }
}

int main()
{

    test();
    system("pause");
    return 0;
}
