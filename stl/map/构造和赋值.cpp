#include <iostream>
#include <map>
using namespace std;

//map中所有元素都是pair，第一个元素是key，第二个元素为value
//所有元素根据key自动排序
//map不允许重复key，multimap允许重复key

void printMap(const map<int, int> &m)
{
    for(map<int,int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << " value = " << it->second << endl;

    }

}


void test()
{
    map<int, int>m;
    //插入要使用pair对组数据类型
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(5, 50));

    printMap(m);

    //拷贝构造
    map<int, int>m2(m);
    printMap(m2);
    //赋值
    map<int, int>m3;
    m3 = m2;
    printMap(m3);
}

int main()
{

    test();
    //system("pause");
    return 0;
}