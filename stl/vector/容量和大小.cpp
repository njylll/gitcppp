#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    vector<int> v1;
    for(int i = 0;i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else 
    {
        cout << "不为空" << endl;
        cout << "v1的容量为：" << v1.capacity() << endl;
        cout << "v1的大小为：" << v1.size() << endl;
    }

    //v1.resize(15);//重新指定比原来长，默认用0填充
    v1.resize(15,100);//可指定默认填充值
    v1.resize(5);//重新指定的短，超出的部分被删除
    printVector(v1);

}

int main()
{

    test();
    //system("pause");
    return 0;
}
