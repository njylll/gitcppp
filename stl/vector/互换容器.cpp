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


void printVector2(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}


void test()
{
     vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector2(v1);

    vector<int> v2;
     for(int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    //交换后
    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//巧用swap可以收缩内存空间
void test02()
{
    vector<int> v1;
    for(int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
    }
    cout << "v的容量：" << v1.capacity() << endl;
    cout << "v的大小：" << v1.size() << endl;

    v1.resize(3);//重新指定大小
    cout << "v的容量：" << v1.capacity() << endl;
    cout << "v的大小：" << v1.size() << endl;
    //用swap收缩内存
    //vector<int>(v1) --创建匿名对象，用v1初始化，给了3个int空间
    vector<int>(v1).swap(v1);
    cout << "v的容量：" << v1.capacity() << endl;
    cout << "v的大小：" << v1.size() << endl;


}
int main()
{

    //test();
    test02();
  //  system("pause");
    return 0;
}
