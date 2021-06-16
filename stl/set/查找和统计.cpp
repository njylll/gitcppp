#include <iostream>
#include <set>
using namespace std;

void test()
{
    set<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(50);
    s.insert(30);
    s.insert(40);
    //查找
    set<int>::iterator pos = s.find(30);
    if(pos != s.end())
    {
        cout << *pos << endl;
    }else{
        cout << "未找到！" << endl;
    }
    //统计
    int num = s.count(10);
    //对于set而言，统计的值是0或1，因为不允许插入重复值
    cout << "num = " << num << endl;
}

int main()
{

    test();
    system("pause");
    return 0;
}