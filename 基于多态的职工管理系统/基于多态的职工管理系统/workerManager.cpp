#include "workerManager.h"

WorkManager::WorkManager()
{
	//初始化
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "编号：" << this->m_EmpArray[i]->m_Id << endl;
	}*/


	
}

void WorkManager::Show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "***********  欢迎使用职工管理系统！ ***********" << endl;
	cout << "**************  0.退出管理系统    *************" << endl;
	cout << "**************  1.增加职工信息    *************" << endl;
	cout << "**************  2.显示职工信息    *************" << endl;
	cout << "**************  3.删除离职职工    *************" << endl;
	cout << "**************  4.修改职工信息    *************" << endl;
	cout << "**************  5.查找职工信息    *************" << endl;
	cout << "**************  6.按照编号排序    *************" << endl;
	cout << "**************  7.清空所有文档    *************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;

}

void WorkManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}
void WorkManager::Add_Emp()
{
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算开辟新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//拷贝
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
				cout << "请输入第" << i + 1 << "个新员工的编号" << endl;
				cin >> id;
				while (this->isExist(id) != -1)
				{
					cout << "职工编号已存在,请重新输入" << endl;
					cin >> id;
				}
				cout << "请输入第" << i + 1 << "个新员工的姓名" << endl;
				cin >> name;
				cout << "请选择该职工的岗位" << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
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
				//将创建职工，保存到数组中
				newSpace[this->m_EmpNum + i] = worker;

			
			}
			this->m_FileIsEmpty = false;
			delete[] this->m_EmpArray;
			this->m_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			cout << "成功添加" << addNum << "名新职工" << endl;
			this->save();
		
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件  
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
	ifs.open(FILENAME, ios::in);//读文件
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
		cout << "文件不存在或记录为空!" << endl;

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
		cout << "文件不存在或记录为空!" << endl;

	}
	else
	{
		cout << "请输入想要删除的职工编号" << endl;
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
			cout << "删除成功" << endl;
			if (this->m_EmpNum == 0)this->m_FileIsEmpty = 1;
		}
		else cout << "职工不存在" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新的职工号:" << endl;
			cin >> newId;
			while(this->isExist(newId) != -1)
			{
				cout << "该编号已存在，请重新输入" << endl;
				cin >> newId;
			}
			
			cout << "请输入新的姓名:" << endl;
			cin >> newName;

			cout << "请输入新的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

	}
	else
	{
		int select = 0;
		cout << "请选择查找方式" << endl;
		cout << "1.按编号" << endl;
		cout << "2.按姓名" << endl;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			int ret = this->isExist(id);
			if (ret!=-1)
			{
				cout << "查找成功，该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			bool flag = false;
			string name;
			cout << "请输入查找的职工姓名" << endl;
			cin >> name;
			int ret;
			for (int i = 0; i < m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id << "号职工信息如下" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "输入错误" << endl;

		}
	}
	system("pause");
	system("cls");
}
void WorkManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

	}
	else
	{
		cout << "选择升序还是降序" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
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
			cout << "排序成功" << endl;
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
			cout << "排序成功" << endl;
			this->save();

		}
		else cout << "输入错误" << endl;
	}
}
void WorkManager::clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1.确定 " << endl;
	cout << "2.返回 " << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				//删除堆区的每个职工对象
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;


		}
		cout << "清空成功" << endl;
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