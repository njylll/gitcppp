#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Transform
{
public:
    int operator()(int v)
    {
        return v;
    }

};

class MyPrint
{
public:
    void operator()(int v)
    {
        cout << v << " ";
    }

};



void test()
{
    vector<int>v;
    for(int i =0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>v2;
    v2.resize(v.size());//transform前开辟空间
    transform(v.begin(),v.end(),v2.begin(),Transform());
    for_each(v2.begin(), v2.end(), MyPrint());

}

int main()
{

    test();
   // system("pause");
    return 0;
}