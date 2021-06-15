#include <iostream>
#include <deque>
using namespace std;

 void printDeq( deque<int> deq)
{
    for(deque<int>::iterator it = deq.begin();it != deq.end(); it++)
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


deque<int> d3(d1.begin(),d1.begin()+3); 

printDeq(d3);

}

int main()
{
    test();
    //system("pause");
    return 0;
} 