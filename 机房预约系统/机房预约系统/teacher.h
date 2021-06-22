#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include"orderfile.h"

//教师类
class Teacher : public Identity
{
public:
	Teacher();
	//职工号，姓名，密码
	Teacher(int empId, string name, string passwd);
	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
	//职工号
	int m_EmpId;
	OrderFile orderFile;
};