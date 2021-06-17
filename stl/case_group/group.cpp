#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
#define CEHUA 1
#define MEISHU 2
#define YANFA 3

class Worker
{
public:

    string m_Name;
    int m_Salary;

};

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDEFGHIJ";
    for(int i =0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;//10000 ~ 19999
        v.push_back(worker);
    }


}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号
        int deptId = rand() % 3 + 1;//1,2,3
        m.insert(make_pair(deptId, *it));
    }

}

void showGroup(multimap<int,Worker>&m)
{
    // for(multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
    // {
    //     cout << "部门：" << it->first << " 员工：" << it->second.m_Name << " " << it->second.m_Salary
    //     << endl;
    // }
    cout << "策划部门：" << endl;
    multimap<int, Worker>::const_iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for(;pos != m.end() && index < count;pos++, index++)
    {
        cout << "姓名:" << pos->second.m_Name << " 薪资：" << pos->second.m_Salary << endl;
    }
    cout << "美术部门：" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for(;pos != m.end() && index < count;pos++,index++)
    {
        cout << "姓名:" << pos->second.m_Name << " 薪资：" << pos->second.m_Salary << endl;
    }

    cout << "研发部门：" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for(;pos != m.end() && index < count;pos++,index++)
    {
        cout << "姓名:" << pos->second.m_Name << " 薪资：" << pos->second.m_Salary << endl;
    }



}


int main()
{
    srand((unsigned int)time(NULL));
    //创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);
    //员工分组
    multimap<int, Worker>mWorker;
    setGroup(vWorker,mWorker);
    showGroup(mWorker);
    return 0;
}