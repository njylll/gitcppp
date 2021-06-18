#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Greater30
{
public:
    bool operator()(const int val)
    {
        return val > 5;
    }
};

void test()

{
    vector<int>v{1,2,3,4,5,6,7,8,9};
    replace_if(v.begin(),v.end(),Greater30(),0);
    for(auto it : v)
    {
        cout << it << " ";
    }
}


int main()

{

test();

//system("pause");

return 0;

}

