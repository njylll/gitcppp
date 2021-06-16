#include <iostream>
#include <set>
using namespace std;

void test()
{
    set<int>s;
    s.insert(10);
    //set进行重复插入检测,返回一个迭代器和布尔值
    pair<set<int>::iterator ,bool>ret = s.insert(10);

    if(ret.second)
    {
        cout << "插入成功" << endl;
    }
    else cout << "插入失败" << endl;

    //multiset不进行重复插入检测
    multiset<int>ms;
    ms.insert(10);
    ms.insert(10);
    
}

int main()
{

    test();
    //system("pause");
    return 0;
} 