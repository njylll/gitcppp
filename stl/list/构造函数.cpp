#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>&l)
{
    for(list<int>::const_iterator it = l.begin(); it!= l.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl;
}

void test()
{
    list<int>l1;

    //添加数据
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    //区间赋值
    list<int>l2(l1.begin(), l1.end());
    printList(l2);

    //拷贝构造
    list<int>l3(l2);
    printList(l3);

    //n个elem
    list<int>l4(10,1);
    printList(l4);
}

int main()
{

    test();
    system("pause");
    return 0;
}