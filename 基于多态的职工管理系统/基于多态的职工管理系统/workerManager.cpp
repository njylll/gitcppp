#include "workerManager.h"

WorkManager::WorkManager()
{
	//��ʼ��
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "��ţ�" << this->m_EmpArray[i]->m_Id << endl;
	}*/


	
}

void WorkManager::Show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "***********  ��ӭʹ��ְ������ϵͳ�� ***********" << endl;
	cout << "**************  0.�˳�����ϵͳ    *************" << endl;
	cout << "**************  1.����ְ����Ϣ    *************" << endl;
	cout << "**************  2.��ʾְ����Ϣ    *************" << endl;
	cout << "**************  3.ɾ����ְְ��    *************" << endl;
	cout << "**************  4.�޸�ְ����Ϣ    *************" << endl;
	cout << "**************  5.����ְ����Ϣ    *************" << endl;
	cout << "**************  6.���ձ������    *************" << endl;
	cout << "**************  7.��������ĵ�    *************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;

}

void WorkManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}
void WorkManager::Add_Emp()
{
	cout << "���������ְ������:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//���㿪���¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//����
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
			for (int i = 0; i < addNum; i++)
			{
				int id;
				string name;
				int dSelect;
				cout << "�������" << i + 1 << "����Ա���ı��" << endl;
				cin >> id;
				while (this->isExist(id) != -1)
				{
					cout << "ְ������Ѵ���,����������" << endl;
					cin >> id;
				}
				cout << "�������" << i + 1 << "����Ա��������" << endl;
				cin >> name;
				cout << "��ѡ���ְ���ĸ�λ" << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> dSelect;

				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;

				default:
					break;
				}
				//������ְ�������浽������
				newSpace[this->m_EmpNum + i] = worker;

			
			}
			this->m_FileIsEmpty = false;
			delete[] this->m_EmpArray;
			this->m_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			cout << "�ɹ����" << addNum << "����ְ��" << endl;
			this->save();
		
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�  
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();


}

void WorkManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}

		system("pause");
		system("cls");
	}
}
void WorkManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;

	}
	else
	{
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
			if (this->m_EmpNum == 0)this->m_FileIsEmpty = 1;
		}
		else cout << "ְ��������" << endl;
	}
}
int WorkManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ�����������µ�ְ����:" << endl;
			cin >> newId;
			while(this->isExist(newId) != -1)
			{
				cout << "�ñ���Ѵ��ڣ�����������" << endl;
				cin >> newId;
			}
			
			cout << "�������µ�����:" << endl;
			cin >> newName;

			cout << "�������µĸ�λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

	}
	else
	{
		int select = 0;
		cout << "��ѡ����ҷ�ʽ" << endl;
		cout << "1.�����" << endl;
		cout << "2.������" << endl;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ�����" << endl;
			cin >> id;
			int ret = this->isExist(id);
			if (ret!=-1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			bool flag = false;
			string name;
			cout << "��������ҵ�ְ������" << endl;
			cin >> name;
			int ret;
			for (int i = 0; i < m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << "��ְ����Ϣ����" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "���޴���" << endl;
			}
		}
		else {
			cout << "�������" << endl;

		}
	}
	system("pause");
	system("cls");
}
void WorkManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

	}
	else
	{
		cout << "ѡ�������ǽ���" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int select;
		cin >> select;
		int i, j;
		Worker* temp;
		if (select == 1)
		{
			for (i = 0; i < m_EmpNum - 1; i++)
			{
				for (j = 0; j < m_EmpNum - i - 1; j++)
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						temp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = temp;
					}
				}
			}
			cout << "����ɹ�" << endl;
		}
		else if (select == 2)
		{
			for (i = 0; i < m_EmpNum - 1; i++)
			{
				for (j = 0; j < m_EmpNum - i - 1; j++)
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						temp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = temp;
					}
				}
			}
			cout << "����ɹ�" << endl;
			this->save();

		}
		else cout << "�������" << endl;
	}
}
void WorkManager::clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ�� " << endl;
	cout << "2.���� " << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				//ɾ��������ÿ��ְ������
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;


		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}