#include <iostream>
#include <deque>
using namespace std;


void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end();it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

//两端操作
void test()
{
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    //尾删
    d1.pop_front();
    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);

}

//指定位置操作
void test01()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    //insert插入
    d1.insert(d1.begin(),1000);
    d1.insert(d1.begin(),2,1000);
    printDeque(d1);

    //按照区间进行插入
    deque<int> d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_back(30);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}

void test02()
{
      deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);

    //按区间删除
    //d1.erase(d1.begin(), d1.end());
    d1.clear();
}
int main()
{

    //test();
    test02();
   // system("pause");
    return 0;
}