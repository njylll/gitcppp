#include "root.h"

Root::Root()
{

}
Root::Root(string name, string passwd)
{
	this->m_Name = name;
	this->m_Passwd = passwd;
	//��ʼ������
	this->initVector();
}
void Root::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼!" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        1. ����˺�                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        2. �鿴�˺�                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        3. �鿴������Ϣ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        4. ���ԤԼ��¼             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|        0. ע����¼                 |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "���������ѡ��" << endl;
}
//����˺�
void Root::addPerson()
{
	string fileName;
	string tip;//��ʾid��
	ofstream ofs;
	int select = 0;
	string errortip;
	while(true)
	{
		cout << "������Ҫ��ӵ��˺����ͣ�" << endl;
		cout << "1. ���ѧ��" << endl;
		cout << "2.�����ʦ" << endl;
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "������ѧ��ѧ�ţ�";
			errortip = "ѧ��ѧ���ظ������������룺";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ����";
			errortip = "�̹����ظ�,���������룺";
			break;
		}
		cout << "�������,��������!" << endl;
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


	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> passwd;

	addToVector(id,name,passwd,select);
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << passwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	cout << "ѧ������Ϊ��" << vStu.size() << endl;
	system("pause");
	system("cls");
}
//�鿴�˺�
void Root::showPerson()
{
	cout << "ѡ��Ҫ�鿴�����ݣ�" << endl;
	cout << "1. �鿴����ѧ��" << endl;
	cout << "2. �鿴������ʦ" << endl;
	int select;
	cout << "���������ѡ��" << endl;
	while (true)
	{
		cin >> select;
		if(select == 1)
		{
			cout << endl << "ѧ���˺�Ϊ��" << endl;
			for (auto i : vStu)
			{
				cout << "ѧ��ѧ�ţ�" << i.m_Id << "\t" << "������" << i.m_Name << "\t" << "���룺" << i.m_Passwd << endl;
			}
			break;
		}
		else if(select == 2)
		{
			cout << "��ʦ�˺�Ϊ��" << endl;
			for (auto i : vTea)
			{
				cout << "��ְ���ţ�" << i.m_EmpId << "\t" << "������" << i.m_Name << "\t" << "���룺" << i.m_Passwd << endl;
			}
			break;
			
		}
		else
		{
			cout << "����������������룺" << endl;
		}
	}
	system("pause");
	system("cls");
	
}
//�鿴������Ϣ
void Root::showComputer()
{
	for (auto i : vComRoom)
	{
		cout << "�����ţ�" << i.m_ComId << "\t" << "�������: " << i.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Root::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILR, ios::trunc);
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}
//��ʼ��ѧ������ʦ��������Ϣ
void Root::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id >> s.m_Name >> s.m_Passwd)
	{
		vStu.push_back(s);
	}
	//cout << "ѧ��������" << vStu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId >> t.m_Name >> t.m_Passwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ʦ����: " << vTea.size() << endl;
	ifs.close();
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	ComputerRoom computerRoom;
	while (ifs >> computerRoom.m_ComId >> computerRoom.m_MaxNum)
	{
		vComRoom.push_back(computerRoom);
	}
	//cout << "������Ϊ��" << vComRoom.size() << endl;
	ifs.close();
}

//ȥ�غ���
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

//��������

void Root::addToVector(int id, string name, string passwd, int type)
{
	//���ѧ��
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