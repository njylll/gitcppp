#pragma once
#include <iostream>
#include <vector>
#include "computerRoom.h"
using namespace std;
#include "Identity.h"
#include "global.h"
#include "orderfile.h"

//学生类
class Student : public Identity
{
public:
	//默认构造
	Student();
	//有参构造 学号，姓名，密码
	Student(int id, string name, string passwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	// 查看自身预约
	void showMyOrder();
	// 查看所有预约
	void showAllOrder();
	// 取消预约
	void cancelOrder();
	//初始化机房信息
	void initComputerRoom();
	//学生学号
	int m_Id = 0;
	vector<ComputerRoom>vComputerRoom;
	OrderFile orderFile;
};