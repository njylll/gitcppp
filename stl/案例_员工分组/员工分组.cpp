#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Worker
{
public:

    string m_Name;
    int m_Salary;

};

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCEDEFGHI";
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

void showGroup(const multimap<int,Worker>&m)
{
    for(multimap<int, Worker>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "部门：" << it->first << " 员工：" << it->second.m_Name << " " << it->second.m_Salary
        << endl;

    }


}


int main()
{
    //创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);
    //员工分组
    multimap<int, Worker>mWorker;
    setGroup(vWorker,mWorker);
    showGroup(mWorker);
    return 0;
}