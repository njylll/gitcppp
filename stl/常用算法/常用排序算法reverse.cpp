#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const int &val)
{
    cout << val << " ";
}

void test()
{
    vector<int> v1{1,7,2,3,5,8,9,};
    for_each(v1.begin(), v1.end(),print);
    cout << endl;
    reverse(v1.begin(),v1.end());
    for(auto it : v1)
    {
        cout << it << " ";
    }
    cout << endl;
}


int main()
{
    test();
    //system("pause");
    return 0;
}

