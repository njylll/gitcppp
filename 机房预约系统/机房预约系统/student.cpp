#include "Student.h"
//Ĭ�Ϲ���
Student::Student()
{

}
//�вι��� ѧ�ţ�����������
Student::Student(int id, string name, string passwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Passwd = passwd;
	this->initComputerRoom();

}
//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        1. ����ԤԼ                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        2. �鿴����ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        3. �鿴����ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        4. ȡ��ԤԼ                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        0. ע����¼                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "���������ѡ��" << endl;
}
//��ʼ��������Ϣ
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
//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1. ��һ" << endl;
	cout << "2. �ܶ�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
	cout << "5. ����" << endl;

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
		cout << "�������,���������룺" << endl;
	}

	cout << "������ԤԼʱ��Σ�" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "����������������룺" << endl;
	}
	cout << "��ѡ�������" << endl;
	for (auto it : vComputerRoom)
	{
		cout << it.m_ComId << "�Ż�������������ǣ�" << it.m_MaxNum << endl;
	}
	while (true)
	{
		cin >> roomId;
		if (roomId <= vComputerRoom.size() && roomId > 0)
		{
			break;
		}
		cout << "�����������������" << endl;
	}
	cout << "ԤԼ�ɹ�������У�" << endl;
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
// �鿴����ԤԼ
void Student::showMyOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < orderFile.m_Size; i++)
	{

		if (stoi(orderFile.mOrderData[i]["stuId"]) == this->m_Id)
		{
			cout << "ԤԼ���ڣ���" << orderFile.mOrderData[i]["date"] << " "
				<< "ʱ���: " << (orderFile.mOrderData[i]["interval"] == " 1" ? "����" : "����");
			cout << " �����ţ� " << orderFile.mOrderData[i]["roomId"] << " ";
			string status = "״̬:";
			int sta = stoi(orderFile.mOrderData[i]["status"]);
			if (sta == 1)
			{
				status += "�����";
			}
			else if(sta == 2)
			{
				status += "��ԤԼ";
			}
			else if (sta == 3)
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "��ȡ��ԤԼ";
			}
			cout << status << endl;
			
		}
	}
	system("pause");
	system("cls");

}
// �鿴����ԤԼ
void Student::showAllOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "û��ԤԼ��" << endl;
	}
	for (int i = 0; i < orderFile.m_Size; i++)
	{
		cout << "ѧ��ѧ�ţ�" << orderFile.mOrderData[i]["stuId"] << " " << "ѧ��������" << orderFile.mOrderData[i]["stuName"];
		cout << " ԤԼ���ڣ���" << orderFile.mOrderData[i]["date"] << " "
			<< "ʱ���: " << (orderFile.mOrderData[i]["interval"] == " 1" ? "����" : "����");
		cout << " �����ţ� " << orderFile.mOrderData[i]["roomId"] << " ";
		string status = "״̬:";
		int sta = stoi(orderFile.mOrderData[i]["status"]);
		if (sta == 1)
		{
			status += "�����";
		}
		else if (sta == 2)
		{
			status += "��ԤԼ";
		}
		else if (sta == 3)
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "��ȡ��ԤԼ";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
// ȡ��ԤԼ
void Student::cancelOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ��!" << endl;
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
				cout << "ԤԼ���ڣ���" << orderFile.mOrderData[i]["date"] << " "
					<< "ʱ���: " << (orderFile.mOrderData[i]["interval"] == " 1" ? "����" : "����");
				cout << " �����ţ� " << orderFile.mOrderData[i]["roomId"] << " ";
				string status = "״̬:";
				int sta = stoi(orderFile.mOrderData[i]["status"]);
				if (sta == 1)
				{
					status += "�����";
				}
				else if (sta == 2)
				{
					status += "��ԤԼ";
				}
				cout << status << endl;
				m.insert(make_pair(index, i));
				index++;
			}
		}
	}
	cout << "���������ѡ�񣬻�0�˳�:" << endl;
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
				cout << "ȡ��ԤԼ�ɹ���";
				break;
			}
			orderFile.updateOrder();
		}
		cout << "������������������:" << endl;
	}
	system("pause");
	system("cls");

}