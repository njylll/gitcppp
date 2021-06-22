#pragma once
#include <iostream>
#include"global.h"
#include <map>
#include <fstream>
using namespace std;


class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//截取信息
	pair<string, string> getPair(string &str);

	//记录的容器
	map<int, map<string, string>>mOrderData;

	int m_Size = 0;
};