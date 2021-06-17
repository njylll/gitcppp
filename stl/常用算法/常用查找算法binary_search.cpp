#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//二分查找法 返回true or false 在无序序列中不可用
void test()
{
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    bool ret = binary_search(v.begin(),v.end(),9);
    if(ret)
    {
        cout << "找到" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

int main()
{

    test();
    system("pause");
    return 0;
}