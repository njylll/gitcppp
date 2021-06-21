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


	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << passwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}
//�鿴�˺�
void Root::showPerson()
{

}
//�鿴������Ϣ
void Root::showComputer()
{

}
//���ԤԼ��¼
void Root::clearFile()
{

}
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
	cout << "ѧ��������" << vStu.size() << endl;
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
	cout << "��ʦ����: " << vTea.size() << endl;

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