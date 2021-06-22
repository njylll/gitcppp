#include "root.h"

Root::Root()
{

}
Root::Root(string name, string passwd)
{
	this->m_Name = name;
	this->m_Passwd = passwd;
	//初始化容器
	this->initVector();
}
void Root::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录!" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        1. 添加账号                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        2. 查看账号                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        3. 查看机房信息             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        4. 清空预约记录             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        0. 注销登录                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请输入你的选择：" << endl;
}
//添加账号
void Root::addPerson()
{
	string fileName;
	string tip;//提示id号
	ofstream ofs;
	int select = 0;
	string errortip;
	while(true)
	{
		cout << "请输入要添加的账号类型：" << endl;
		cout << "1. 添加学生" << endl;
		cout << "2.添加老师" << endl;
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "请输入学生学号：";
			errortip = "学生学号重复，请重新输入：";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号";
			errortip = "教工号重复,请重新输入：";
			break;
		}
		cout << "输入错误,重新输入!" << endl;
		system("pause");
		system("cls");
	}
	string name;
	int id;
	string passwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else break;
	}


	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> passwd;

	addToVector(id,name,passwd,select);
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << passwd << " " << endl;
	cout << "添加成功" << endl;
	cout << "学生人数为：" << vStu.size() << endl;
	system("pause");
	system("cls");
}
//查看账号
void Root::showPerson()
{
	cout << "选择要查看的内容：" << endl;
	cout << "1. 查看所有学生" << endl;
	cout << "2. 查看所有老师" << endl;
	int select;
	cout << "请输入你的选择：" << endl;
	while (true)
	{
		cin >> select;
		if(select == 1)
		{
			cout << endl << "学生账号为：" << endl;
			for (auto i : vStu)
			{
				cout << "学生学号：" << i.m_Id << "\t" << "姓名：" << i.m_Name << "\t" << "密码：" << i.m_Passwd << endl;
			}
			break;
		}
		else if(select == 2)
		{
			cout << "教师账号为：" << endl;
			for (auto i : vTea)
			{
				cout << "教职工号：" << i.m_EmpId << "\t" << "姓名：" << i.m_Name << "\t" << "密码：" << i.m_Passwd << endl;
			}
			break;
			
		}
		else
		{
			cout << "输入错误，请重新输入：" << endl;
		}
	}
	system("pause");
	system("cls");
	
}
//查看机房信息
void Root::showComputer()
{
	for (auto i : vComRoom)
	{
		cout << "机房号：" << i.m_ComId << "\t" << "最大容量: " << i.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Root::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILR, ios::trunc);
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}
//初始化学生，教师，机房信息
void Root::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id >> s.m_Name >> s.m_Passwd)
	{
		vStu.push_back(s);
	}
	//cout << "学生数量：" << vStu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId >> t.m_Name >> t.m_Passwd)
	{
		vTea.push_back(t);
	}
	//cout << "教师数量: " << vTea.size() << endl;
	ifs.close();
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	ComputerRoom computerRoom;
	while (ifs >> computerRoom.m_ComId >> computerRoom.m_MaxNum)
	{
		vComRoom.push_back(computerRoom);
	}
	//cout << "机房数为：" << vComRoom.size() << endl;
	ifs.close();
}

//去重函数
bool Root::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it= vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

//加入容器

void Root::addToVector(int id, string name, string passwd, int type)
{
	//添加学生
	if(type == 1)
	{
		Student stu;
		stu.m_Name = name;
		stu.m_Id = id;
		stu.m_Passwd = passwd;
		vStu.push_back(stu);
	}
	else
	{
		Teacher tea;
		tea.m_EmpId = id;
		tea.m_Name = name;
		tea.m_Passwd = passwd;
		vTea.push_back(tea);
	}
}