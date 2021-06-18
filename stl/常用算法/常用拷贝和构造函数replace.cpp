#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test()

{
    vector<int>v{1,2,3,4,5,6,7,8,10};
    replace(v.begin(), v.end(),10,9);//自定义类型要重载=，==
    for(auto it : v)
    {
        cout << it << " ";
    }
}

int main()

{

    test();

    //system("pause");

    return 0;
}
