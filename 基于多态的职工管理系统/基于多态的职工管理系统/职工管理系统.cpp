#include <iostream>
#include "workerManager.h"
#include "employee.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
using namespace std;

int main()
{
	/*Worker* worker = NULL;
	worker = new Employee(100, "lihua", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "lisu", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(1, "njy", 3);
	worker->showInfo();
	delete worker;*/

	
	WorkManager wm;
	int choice = 0;
	
	while (true)
	{
		wm.Show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ £º " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.del_Emp();
			break;
		case 4:
			wm.mod_Emp();
			break;
		case 5:
			wm.find_Emp();
			break;
		case 6:
			wm.sort_Emp();
			break;
		case 7:
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}