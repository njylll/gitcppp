#include <iostream>
#include <deque>
using namespace std;

 void printDeq(const deque<int> &deq)
{
    for(deque<int>::const_iterator it = deq.begin();it != deq.end(); it++)//const_iteratot只读迭代器
    { 
        cout << *(it) << " ";
    }
    cout << endl;
}

void test()
{
deque<int> d1;

for(int i = 0;i < 10;i++)

{
    d1.push_back(i);
}

deque<int> d2(4,100);
printDeq(d2);

deque<int> d3(d2);
printDeq(d3);

deque<int> d4(d1.begin(),d1.begin()+3);//0 1 2 

printDeq(d4);

}

int main()
{
    test();
    //system("pause");
    return 0;
} 