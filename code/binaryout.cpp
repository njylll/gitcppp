#include <fstream>
#include <iostream>

using namespace std;

class Person
{
public:
	
	char m_Name[64];
	int m_Age;
};


void test()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"����",18};
	ofs.write((const char*)&p,sizeof(Person));
	ofs.close();
}

void test01()
{
	ifstream ifs;
	ifs.open("person.txt",ios::in | ios::binary);
	if(!ifs.is_open())
	{
			cout << "��ʧ��" << endl;
			return;
	}
	Person p;
	ifs.read((char *)&p,sizeof(Person));
	cout << "������" << p.m_Name << endl << "���䣺"  << p.m_Age << endl;
	
	
	ifs.close();
}

int main()
{
test01();
return 0;
}