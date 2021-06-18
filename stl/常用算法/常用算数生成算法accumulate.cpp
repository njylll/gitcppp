#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void test()
{
    vector<int>v;

    for( int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }

    int sum = accumulate(v.begin(),v.end(),0);//0 起始累加值
    cout << sum << endl;

}

int main()
{

    test();
    system("pause");
    return 0;
}