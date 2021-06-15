#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>&l)
{
    for(list<int>::const_iterator it = l.begin(); it != l.end();it++ )
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test()
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    if(l1.empty())
    {
        cout << "l1为空" << endl;
    }
    else{
        cout << "l1不为空" << endl;
        cout << "l1.size = " << l1.size() << endl;
    }

    //重新指定大小
    l1.resize(10,1);
    printList(l1);

    l1.resize(2);//超出部分被删除
    printList(l1);
}

int main()
{

    test();
    system("pause");
    return 0;
}