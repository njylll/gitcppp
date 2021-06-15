#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>&l)
{
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2)
{
    //降序
    return v1 > v2;
}
void test()
{
     list<int>l1;
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(30);
    l1.push_back(20);
    printList(l1);

    //反转
    l1.reverse();
    printList(l1);
    //排序，所有不支持随机访问迭代器的容器，不能用标准算法
    //默认升序
    l1.sort(myCompare);
    printList(l1);


}

int main()
{

    test();
   // system("pause");
    return 0;
}