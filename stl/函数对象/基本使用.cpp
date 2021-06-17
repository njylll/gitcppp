#include <iostream>
using namespace std;

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }


};


//函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        count++;
    }

    int count;
};


//函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}



void test()
{
    MyAdd myAdd;
    cout << myAdd(10, 20) << endl;
    

    MyPrint myPrint;
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");

    cout << "调用次数：" << myPrint.count << endl;

    MyPrint myprint02;
    doPrint(myprint02,"hello world");
}

int main()
{

    test();
  //  system("pause");
    return 0;
}