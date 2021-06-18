#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//合并两个容器  两个容器必须有序

void test()
{
    vector<int>v{1,3,5,6,7,9,10};
    vector<int>v2{10,8,6,4,3,2};
    vector<int>tV;
    tV.resize(v.size() + v2.size());
    merge(v.begin(),v.end(),v2.begin(),v2.end(),tV.begin());
    for(auto it : tV)
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

