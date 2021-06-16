#include <iostream>
#include <set>
using namespace std;
//set 二叉树方式   自动排序
void printSet(const set<int>&s)
{
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    set<int>s1;
    //插入数据 只有insert方式 set容器不允许插入重复值
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    
    printSet(s1);

    //拷贝构造
    set<int>s2(s1);
    printSet(s2);

    //赋值
    set<int>s3;
    s3 = s2;
    printSet(s3);
}


int main()
{
    test();
    //system("pause");
    return 0;
}

