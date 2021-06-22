#pragma
#include <iostream>
using namespace std;
#include "identity.h"
#include "global.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <vector>

class Root : public Identity
{
public:
	Root();
	Root(string name, string passwd);
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void clearFile();
	//��ʼ������
	void initVector();
	//ȥ�غ���
	bool checkRepeat(int id, int type);
	//��������
	void addToVector(int id, string name,string passwd,int type);//����Ϊѡ������ĸ�����

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vComRoom;
};