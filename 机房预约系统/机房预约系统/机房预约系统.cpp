#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "student.h"
#include "global.h"
#include "teacher.h"
#include "root.h"


//�������Ա�Ӳ˵�����
void rootMenu(Identity * &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		Root* root = (Root*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����˺�:" << endl << endl;
			root->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�:" << endl << endl;
			root->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl << endl;
			root->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl << endl;
			root->clearFile();
		}
		else
		{
			delete manager;
			manager = NULL;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}

//����ѧ���Ӳ˵�
void studentMenu(Identity * &student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����ԤԼ��" << endl << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "��ʾ�ҵ�ԤԼ:" << endl << endl;
			stu->showMyOrder();
			break;
		case 3:
			cout << "��ʾ����ԤԼ��" << endl << endl;
			stu->showAllOrder();
			break;
		case 4:
			cout << "ȡ��ԤԼ��" << endl << endl;
			stu->cancelOrder();
			break;
		default:
			delete student;
			student = NULL;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		
		}
	}
}

//�����ʦ�Ӳ˵�
void teacherMenu(Teacher* teacher)
{
	while (true)
	{
		teacher->operMenu();
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "�鿴����ԤԼ��" << endl << endl;
			teacher->showAllOrder();
		}
		else if (select == 2)
		{
			cout << "���ԤԼ��" << endl << endl;
			teacher->validOrder();
		}
		else
		{
			delete teacher;
			teacher = NULL;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����
void loginIn(string filename, int type)
{
	Identity* person = NULL;//����ָ�룬ָ���������

	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string passwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ��: " << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û���: " << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> passwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��л�ȡ��id
		string fName;
		string fPasswd;
		while (ifs >> fId >> fName >> fPasswd)
		{
			if (fId == id && fName == name && fPasswd == passwd)
			{
				cout << "ѧ����֤��½�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, passwd);
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPasswd;
		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (fId == id && fName == name && fPasswd == passwd)
			{
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				Teacher *teacher = new Teacher(id, name, passwd);
				teacherMenu(teacher);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;
		string fPasswd;
		while (ifs >> fName && ifs >> fPasswd)
		{
			if (fName == name && fPasswd == passwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Root(name, passwd);
				rootMenu(person);
				return;
			}
		}


	}

		cout << "��֤��½ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	

}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "---------------------- ��ӭ��������ԤԼϵͳ -----------------------"
			<< endl;
		cout << endl << "��ѡ��������: " << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        1. ѧ��                 |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        2. ��ʦ                 |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        3. ����Ա               |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|        0. �˳�                 |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t --------------------------------\n";
		cout << "����������ѡ��";
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "�����������������" << endl;
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