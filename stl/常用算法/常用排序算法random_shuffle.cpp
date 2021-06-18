#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;




void test()
{
    vector<int>v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int a[]{1,5,3,2,6,7,84,3,2};
    //利用random_shuffle打乱数组顺序
    random_shuffle(a,a+(sizeof(a)/sizeof(int)));
   // cout << sizeof(a) << endl;
    for(int it : a)
    {
        cout << it << " " ;
    }
    cout << endl;

}


int main()
{
    srand((unsigned int)time(NULL));
    test();
    //system("pause");
    return 0;

}

