#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void myPrint(const int &val)
{
    cout << val << " ";
}

// class myPrint02
// {
// public:
//     void operator()(int val)
//     {
//         cout << val << " ";
//     }
// };

void test()
{
    vector<int>v{1,9,36,6,8,3,6,90,4};
    //sort升序
    sort(v.begin(),v.end());
    for_each(v.begin(), v.end(),myPrint);
    //sort降序
    sort(v.begin(), v.end(), greater<int>());
}


int main()
{
    test();
    //system("pause");
    return 0;

}

