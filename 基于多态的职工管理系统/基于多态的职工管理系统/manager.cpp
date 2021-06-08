#include "Manager.h"



Manager::Manager(int id, string name, int did)
{
	this->m_DeptId = did;
	this->m_Id = id;
	this->m_Name = name;
}
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责 ： 完成老板任务" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}