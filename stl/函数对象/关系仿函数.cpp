#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


void printVector(const vector<int>&v)
{
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

//大于 greater
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    printVector(v);
    sort(v.begin(), v.end(),greater<int>());
    printVector(v);
}

int main()
{

    test();
    system("pause");
    return 0;
}