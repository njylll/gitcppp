#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include"orderfile.h"

//��ʦ��
class Teacher : public Identity
{
public:
	Teacher();
	//ְ���ţ�����������
	Teacher(int empId, string name, string passwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;
	OrderFile orderFile;
};