#include "Student.h"
//默认构造
Student::Student()
{

}
//有参构造 学号，姓名，密码
Student::Student(int id, string name, string passwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Passwd = passwd;
	this->initComputerRoom();

}
//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生" << this->m_Name << "登录！" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        1. 申请预约                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        2. 查看自身预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        3. 查看所有预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        4. 取消预约                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        0. 注销登录                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请输入你的选择：" << endl;
}
//初始化机房信息
void Student::initComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom comRoom;
	while (ifs >> comRoom.m_ComId >> comRoom.m_MaxNum)
	{
		vComputerRoom.push_back(comRoom);
	}
	ifs.close();
}
//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1. 周一" << endl;
	cout << "2. 周二" << endl;
	cout << "3. 周三" << endl;
	cout << "4. 周四" << endl;
	cout << "5. 周五" << endl;

	int date = 0;
	int interval = 0;
	int roomId = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入错误,请重新输入：" << endl;
	}

	cout << "请输入预约时间段：" << endl;
	cout << "1. 上午" << endl;
	cout << "2. 下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "输入错误，请重新输入：" << endl;
	}
	cout << "请选择机房：" << endl;
	for (auto it : vComputerRoom)
	{
		cout << it.m_ComId << "号机房的最大容量是：" << it.m_MaxNum << endl;
	}
	while (true)
	{
		cin >> roomId;
		if (roomId <= vComputerRoom.size() && roomId > 0)
		{
			break;
		}
		cout << "输入错误。请重新输入" << endl;
	}
	cout << "预约成功！审核中！" << endl;
	/*ofstream ofs(ORDER_FILR, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << roomId << " ";
	ofs << "status:" << "1" << endl;
	ofs.close();*/
	map<string, string>m;
	m.insert(make_pair("date", to_string(date)));
	m.insert(make_pair("interval", to_string(interval)));
	m.insert(make_pair("stuId", to_string(this->m_Id)));
	m.insert(make_pair("stuName", this->m_Name));
	m.insert(make_pair("roomId", to_string(roomId)));
	m.insert(make_pair("status", to_string(1)));

	orderFile.mOrderData.insert(make_pair(orderFile.m_Size, m));
	orderFile.m_Size++;
	orderFile.updateOrder();
	//cout << orderFile.m_Size << endl;
	//cout << orderFile.mOrderData[orderFile.m_Size]["stuId"] << endl;
	system("pause");
	system("cls");
}
// 查看自身预约
void Student::showMyOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < orderFile.m_Size; i++)
	{

		if (stoi(orderFile.mOrderData[i]["stuId"]) == this->m_Id)
		{
			cout << "预约日期：周" << orderFile.mOrderData[i]["date"] << " "
				<< "时间段: " << (orderFile.mOrderData[i]["interval"] == " 1" ? "上午" : "下午");
			cout << " 机房号： " << orderFile.mOrderData[i]["roomId"] << " ";
			string status = "状态:";
			int sta = stoi(orderFile.mOrderData[i]["status"]);
			if (sta == 1)
			{
				status += "审核中";
			}
			else if(sta == 2)
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
	}
	system("pause");
	system("cls");

}
// 查看所有预约
void Student::showAllOrder()
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
// 取消预约
void Student::cancelOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消!" << endl;
	int index = 1;
	int select = 0;
	map<int, int>m;
	for (int i = 0; i < orderFile.m_Size; i++)
	{
		if (stoi(orderFile.mOrderData[i]["stuId"]) == this->m_Id)
		{
			if (stoi(orderFile.mOrderData[i]["status"]) == 1 || stoi(orderFile.mOrderData[i]["status"]) == 2)
			{
				cout << index << ".";
				cout << "预约日期：周" << orderFile.mOrderData[i]["date"] << " "
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
				cout << status << endl;
				m.insert(make_pair(index, i));
				index++;
			}
		}
	}
	cout << "请输入你的选择，或按0退出:" << endl;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			if (select == 0)
			{
				system("pause");
				system("cls");
				return;
			}
			else
			{
				orderFile.mOrderData[m[select]]["status"] = "0";
				orderFile.updateOrder();
				cout << "取消预约成功！";
				break;
			}
			orderFile.updateOrder();
		}
		cout << "输入有误，请重新输入:" << endl;
	}
	system("pause");
	system("cls");

}