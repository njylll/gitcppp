#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};




void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    sort(v.begin(), v.end());
    printVector(v);

    //使用函数对象 改变算法策略，变为降序
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);
}

int main()
{

    test();
    system("pause");
    return 0;
}