#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//仿函数 返回值类型是bool数据类型，称为谓词
class GreaterFive
{
public:
    bool operator()(int val)
    {

        return val > 5;
    }


};




void test()
{
    vector<int>v;
    for(int i =  0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找容器 有没有大于5的数字
    //GreaterFive()， 匿名函数对象
    //返回一个迭代器
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if(pos != v.end())
    {
        cout << "找到" << *pos << endl;
    }else cout << "未找到" << endl;
}

int main()
{

    test();
    system("pause");
    return 0;
}