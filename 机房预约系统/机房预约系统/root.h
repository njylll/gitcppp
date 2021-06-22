#pragma
#include <iostream>
using namespace std;
#include "identity.h"
#include "global.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <vector>

class Root : public Identity
{
public:
	Root();
	Root(string name, string passwd);
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void clearFile();
	//初始化容器
	void initVector();
	//去重函数
	bool checkRepeat(int id, int type);
	//加入容器
	void addToVector(int id, string name,string passwd,int type);//参数为选择加入哪个容器

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vComRoom;
};