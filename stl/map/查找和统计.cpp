#include <iostream>
#include <map>
using namespace std;

void test()
{
    map<int, int>m;
    m.insert(make_pair(1,20));
     m.insert(make_pair(2,30));
      m.insert(make_pair(3,20));
       m.insert(make_pair(5,60));
        m.insert(make_pair(4,70));
    //查找,key,返回迭代器
    map<int, int>::iterator pos = m.find(3);

    if(pos != m.end())
    {
        cout << pos->first << " " << pos->second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    //统计,key
    int num = m.count(3);
    cout << num << endl;

}

int main()
{

    test();
    //system("pause");
    return 0;
}