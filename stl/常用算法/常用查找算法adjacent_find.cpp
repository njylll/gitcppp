#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//查找相邻的重复元素
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(40);
    v.push_back(10);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if(it == v.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "find " << *it << endl;
    }
}

int main()
{

    test();
    system("pause");
    return 0;
}