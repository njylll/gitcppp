#include "teacher.h"

Teacher::Teacher()
{

}
//ְ���ţ�����������
Teacher::Teacher(int empId, string name, string passwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Passwd = passwd;
}
//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        1. �鿴����ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        2. ���ԤԼ                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        0. ע����¼                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "���������ѡ��" << endl;
}
//�鿴����ԤԼ
void Teacher::showAllOrder()
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
//���ԤԼ
void Teacher::validOrder()
{
	if (orderFile.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	map<int, int>m;
	int index = 1;
	cout << "����˵ļ�¼���£�" << endl;
	for (int i = 0; i < orderFile.m_Size; i++)
	{
		if (stoi(orderFile.mOrderData[i]["status"]) == 1)
		{
			cout << index << ". ";
			cout << "ѧ��ѧ��:" << orderFile.mOrderData[i]["stuId"] << " "
				<< "ѧ��������" << orderFile.mOrderData[i]["stuName"] << " "
				<< "ԤԼʱ�䣺����" << orderFile.mOrderData[i]["date"] << " "
				<< "ԤԼʱ�Σ�" << (orderFile.mOrderData[i]["interval"] == "1" ? "����" : "����") << " "
				<< "״̬�������" << endl;
			m.insert(make_pair(index, i));
			index++;
		}
	}
	int select = 1;
	int ret = 0;
	cout << "������ѡ��" << endl;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			cout << "��ѡ������Ƿ�ͨ��:" << endl;
			cout << "1.ͨ��" << endl;
			cout << "2.��ͨ��" << endl;
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
				cout << "����������������룺" << endl;
			
			}
			break;
		}
		cout << "��������������룺" << endl;
	}
	cout << "��˳ɹ���" << endl;
	cout << orderFile.mOrderData[m[select]]["status"];
	orderFile.updateOrder();
	system("pause");
	system("cls");
}