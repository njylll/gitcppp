#include <iostream>
#include <list>
using namespace std;

void test()
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    list<int>::iterator it = l1.begin();
    l1.insert(it, 100);

    l1.remove(10);//删除值为10的节点
    
}

int main()
{

    test();
    system("pause");
    return 0;
}