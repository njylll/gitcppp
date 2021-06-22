#include "teacher.h"

Teacher::Teacher()
{

}
//职工号，姓名，密码
Teacher::Teacher(int empId, string name, string passwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Passwd = passwd;
}
//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师" << this->m_Name << "登录！" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        1. 查看所有预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        2. 审核预约                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        0. 注销登录                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请输入你的选择：" << endl;
}
//查看所有预约
void Teacher::showAllOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "没有预约！" << endl;
	}
	for (int i = 0; i < orderFile.m_Size; i++)
	{
		cout << "学生学号：" << orderFile.mOrderData[i]["stuId"] << " " << "学生姓名：" << orderFile.mOrderData[i]["stuName"];
		cout << " 预约日期：周" << orderFile.mOrderData[i]["date"] << " "
			<< "时间段: " << (orderFile.mOrderData[i]["interval"] == " 1" ? "上午" : "下午");
		cout << " 机房号： " << orderFile.mOrderData[i]["roomId"] << " ";
		string status = "状态:";
		int sta = stoi(orderFile.mOrderData[i]["status"]);
		if (sta == 1)
		{
			status += "审核中";
		}
		else if (sta == 2)
		{
			status += "已预约";
		}
		else if (sta == 3)
		{
			status += "预约失败";
		}
		else
		{
			status += "已取消预约";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//审核预约
void Teacher::validOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	map<int, int>m;
	int index = 1;
	cout << "待审核的记录如下：" << endl;
	for (int i = 0; i < orderFile.m_Size; i++)
	{
		if (stoi(orderFile.mOrderData[i]["status"]) == 1)
		{
			cout << index << ". ";
			cout << "学生学号:" << orderFile.mOrderData[i]["stuId"] << " "
				<< "学生姓名：" << orderFile.mOrderData[i]["stuName"] << " "
				<< "预约时间：星期" << orderFile.mOrderData[i]["date"] << " "
				<< "预约时段：" << (orderFile.mOrderData[i]["interval"] == "1" ? "上午" : "下午") << " "
				<< "状态：审核中" << endl;
			m.insert(make_pair(index, i));
			index++;
		}
	}
	int select = 1;
	int ret = 0;
	cout << "请输入选择：" << endl;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			cout << "请选择审核是否通过:" << endl;
			cout << "1.通过" << endl;
			cout << "2.不通过" << endl;
			while (true)
			{
				cin >> ret;
				if (ret == 1)
				{
					orderFile.mOrderData[m[select]]["status"] = "2";
					break;
				}
				else if (ret == 2)
				{
					orderFile.mOrderData[m[select]]["status"] = "3";
					break;
				}
				cout << "输入错误，请重新输入：" << endl;
			
			}
			break;
		}
		cout << "输入错误，重新输入：" << endl;
	}
	cout << "审核成功！" << endl;
	cout << orderFile.mOrderData[m[select]]["status"];
	orderFile.updateOrder();
	system("pause");
	system("cls");
}