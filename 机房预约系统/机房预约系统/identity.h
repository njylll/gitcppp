#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Identity
{
public:
	//操作菜单
	virtual void operMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Passwd;

};