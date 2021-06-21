#include <iostream>
#include "identity.h"
#include <fstream>
#include "student.h"
#include "global.h"
#include "teacher.h"
#include "root.h"
using namespace std;

//进入管理员子菜单界面
void rootMenu(Identity * &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		Root* root = (Root*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			root->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			root->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			root->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			root->clearFile();
		}
		else
		{
			delete manager;
			manager = NULL;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}

//登录功能
void loginIn(string filename, int type)
{
	Identity* person = NULL;//父类指针，指向子类对象

	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	int id = 0;
	string name;
	string passwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号: " << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名: " << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> passwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中获取的id
		string fName;
		string fPasswd;
		while (ifs >> fId >> fName >> fPasswd)
		{
			if (fId == id && fName == name && fPasswd == passwd)
			{
				cout << "学生验证登陆成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, passwd);
			}
		}

	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;
		string fName;
		string fPasswd;
		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (fId == id && fName == name && fPasswd == passwd)
			{
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, passwd);
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;
		string fPasswd;
		while (ifs >> fName && ifs >> fPasswd)
		{
			if (fName == name && fPasswd == passwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Root(name, passwd);
				rootMenu(person);
				return;
			}
		}


	}

		cout << "验证登陆失败！" << endl;
		system("pause");
		system("cls");
		return;
	

}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "---------------------- 欢迎来到机房预约系统 -----------------------"
			<< endl;
		cout << endl << "请选择你的身份: " << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        1. 学生                 |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        2. 教师                 |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        3. 管理员               |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        0. 退出                 |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t --------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;
		cout << endl;

		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	//Identity *it = new Student();
	//Student *stu = (Student*)it;
	
	//system("pause");
	return 0;
}