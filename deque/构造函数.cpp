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


deque<int>::iterator it = d1.begin();

// cout << *(d1.begin()+1);

deque<int> d2(d1.begin(),d1.begin()+3); 

printDeq(d2);


}

int main()
{
    test();
    //system("pause");
    return 0;
} 