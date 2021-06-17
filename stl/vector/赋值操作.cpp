#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //赋值 operatpr=
    vector<int> v2;
    v2 = v1;
    printVector(v2);
    
    //assign
    vector<int> v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);


    //n个elem方式赋值
    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);
    
    //{}
    vector<int>v5{1,2,3,4,5,6,7};
    for(auto i : v5)
    {
        cout << i << " ";
    }
}

int main()
{

    test();
    system("pause");
    return 0;
}
