#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const int val)
{
    cout << val << " ";
}
void test()
{
    vector<int>v1;
    vector<int>v2;

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 100);
    }
        cout << " before swap:" << endl;
        for_each(v1.begin(),v1.end(),print);
        for_each(v2.begin(),v2.end(),print);
        swap(v1, v2);
         cout << " after swap:" << endl;
        for_each(v1.begin(),v1.end(),print);
        for_each(v2.begin(),v2.end(),print);



}

int main()
{

    test();
    system("pause");
    return 0;
}