#pragma once
#include <iostream>
#include <fstream>
#define FILENAME "empFile.txt"
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
using namespace std;

class WorkManager
{
public:
	WorkManager();

	void Show_Menu();
	void ExitSystem();
	void Add_Emp();
	void save();
	int get_EmpNum();
	void init_Emp();//文件导入初始化
	void show_Emp();
	void del_Emp();
	int isExist(int id); 
	void mod_Emp();
	void find_Emp();
	void sort_Emp();
	void clean_File();


	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;


	~WorkManager();

};