#include <iostream>
#include <map>
using namespace std;

void test()
{
    map<int, int>m;
    map<int ,int>m1;
    m.insert(pair<int, int>(10, 10));
    m1.insert(pair<int, int>(20, 20));
    m.size();
    m.empty();
    m.swap(m1);

}

int main()
{

    test();
    system("pause");
    return 0;
}