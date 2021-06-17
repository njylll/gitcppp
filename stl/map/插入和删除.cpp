#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int, int>&m)
{
    for(map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;

    }

}
void test()
{
    map<int, int>m;
    //1.
    m.insert(pair<int, int>(1, 10));

    //2.
    m.insert(make_pair(2, 10));

    //3.
    m.insert(map<int, int>::value_type(3,30));

    //4.不建议插入使用[]，但可以利用[]访问value
   // m[4] = 40;

    printMap(m);
    //cout << m[5] << endl;

    //删除
    m.erase(m.begin());
    m.erase(1);//删除key=1的元素
    printMap(m);


    m.erase(m.begin(), m.end());
    m.clear();
}

int main()
{

    test();
    system("pause");
    return 0;
}