#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"

//ѧ����
class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι��� ѧ�ţ�����������
	Student(int id, string name, string passwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	// �鿴����ԤԼ
	void showMyOrder();
	// �鿴����ԤԼ
	void showAllOrder();
	// ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;
};