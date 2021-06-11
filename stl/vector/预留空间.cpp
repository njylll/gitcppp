#include <iostream>
#include <vector>
using namespace std;

void test()
{
    vector<int> v1;
    //利用reserve预留空间
    v1.reserve(100000);

    int num = 0;//统计新开辟次数
    int *p = NULL;
    for(int i = 0; i < 100000; i++)
    {
        v1.push_back(i);

        if(p != &v1[0])
        {
            p = &v1[0];
            num++;
        }

    }
    cout << "num = " << num << endl;
}

int main()
{

    test();
    system("pause");
    return 0;
}
