#include <iostream>
#include <map>
using namespace std;


class myCompare
{
public:
    bool operator()(const int &v1, const int &v2)
    {
        return v1 > v2;
    }


};

void test()
{
    map<int, int, myCompare>m;
    m.insert(make_pair(1,20));
    m.insert(make_pair(2,30));
    m.insert(make_pair(3,40));
    m.insert(make_pair(4,50));
    m.insert(make_pair(5,70));


    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }

    
}

int main()
{

    test();
    //system("pause");
    return 0;
}