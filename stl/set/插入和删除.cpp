#include <iostream>
#include <set>
using namespace std;


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
    set<int>s;

    s.insert(10);
    s.insert(20);
    s.insert(50);
    s.insert(30);
    s.insert(40);

    //删除
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    printSet(s);

    //删除重载
    //s.erase(20);
   // printSet(s);

    //清空
   // s.clear();
}

int main()
{

    test();
    system("pause");
    return 0;
}