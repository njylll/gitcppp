#pragma once
#include <iostream>
#include <vector>
#include "computerRoom.h"
using namespace std;
#include "Identity.h"
#include "global.h"
#include "orderfile.h"

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
	//��ʼ��������Ϣ
	void initComputerRoom();
	//ѧ��ѧ��
	int m_Id = 0;
	vector<ComputerRoom>vComputerRoom;
	OrderFile orderFile;
};