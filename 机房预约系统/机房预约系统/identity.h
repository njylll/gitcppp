#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Identity
{
public:
	//�����˵�
	virtual void operMenu() = 0;

	//�û���
	string m_Name;
	//����
	string m_Passwd;

};