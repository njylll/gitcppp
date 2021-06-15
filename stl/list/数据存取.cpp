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

    cout << l1.front() << endl;//第一个元素
    cout << l1.back() << endl;//最后一个元素、

    list<int>::iterator it = l1.begin();
    it++;//支持双向
    it--;
    //it = it + 1;//不支持随机访问
}

int main()
{

    test();
    system("pause");
    return 0;
}