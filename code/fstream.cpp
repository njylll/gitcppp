#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//写操作
void test()
{
	ofstream ofs;
	ofs.open("test.txt",ios::out);
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：20" << endl;
	ofs.close();
}



//读操作
void test01()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if(!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return ;
	}
	char buf[1024] ={0};
	//第一种方式
	while(ifs >> buf)
	{
		cout << buf <<endl;
	}
	cout <<"-------------" << endl;
	//第二种方式
	while(ifs.getline(&buf[500],sizeof(buf)))
	{
		cout << &buf[500] << endl;
	}
	//第三种方式
	// string buf;
	// while(getline(ifs,buf))
	// {
		// cout << buf << endl;
	// }
	//第四种方法
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