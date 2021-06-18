#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test()

{
    vector<int>v1{1,2,3,4,5,6,7,8,};

    vector<int>v2;
    //提起开辟空间
    v2.resize(v1.size());
    copy(v1.begin(),v1.end()-3,v2.begin());
    for(auto it : v2)
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
