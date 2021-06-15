#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
}

void test()
{
    deque<int> d;

d.push_back(10);

d.push_back(20);

d.push_back(30);

d.push_front(100);
printDeque(d);

//排序 默认排序规则 从小到大 升序
//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
//vector容器也可以用sort排序
sort(d.begin(),d.end());
printDeque(d);


}


int main()
{

    test();
    //system("pause");
    return 0;
}

