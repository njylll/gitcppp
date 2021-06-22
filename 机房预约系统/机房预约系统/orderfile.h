#pragma once
#include <iostream>
#include"global.h"
#include <map>
#include <fstream>
using namespace std;


class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��ȡ��Ϣ
	pair<string, string> getPair(string &str);

	//��¼������
	map<int, map<string, string>>mOrderData;

	int m_Size = 0;
};