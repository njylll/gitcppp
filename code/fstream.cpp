#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//д����
void test()
{
	ofstream ofs;
	ofs.open("test.txt",ios::out);
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺20" << endl;
	ofs.close();
}



//������
void test01()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if(!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return ;
	}
	char buf[1024] ={0};
	//��һ�ַ�ʽ
	while(ifs >> buf)
	{
		cout << buf <<endl;
	}
	cout <<"-------------" << endl;
	//�ڶ��ַ�ʽ
	while(ifs.getline(&buf[500],sizeof(buf)))
	{
		cout << &buf[500] << endl;
	}
	//�����ַ�ʽ
	// string buf;
	// while(getline(ifs,buf))
	// {
		// cout << buf << endl;
	// }
	//�����ַ���
	// char c;
	// while((c=ifs.get()) != EOF)
	// {
		// cout << c;
	// }
	ifs.close();
}


int main()
{
	test01();
	system("pause");
	return 0;
}