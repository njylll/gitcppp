#include <iostream>
using namespace std;

class AbstractDrink
{
	public:
	
	virtual void boil()=0;//煮水
	virtual void brew()=0;//冲泡
	virtual void pourInCup()=0;//倒入杯中
	virtual void putSomething()=0;//加入辅料
	
	void makeDrink()
	{
		boil();
		brew();
		pourInCup();
		putSomething();
		
		
	}
};

//制作咖啡
class Coffe: public AbstractDrink
{
	public:
	
	virtual void boil()
	{
		cout << "煮水" << endl;
	}//煮水
	virtual void brew()
	{
		cout << "冲泡coffe" << endl;
	}//冲泡
	virtual void pourInCup()
	{
		cout << "倒入杯中" << endl;
	}//倒入杯中
	virtual void putSomething(){
		cout << "加入牛奶" << endl;
	}
	//加入辅料
};

class Tea: public AbstractDrink
{
	public:
	
	virtual void boil()
	{
		cout << "煮水" << endl;
	}//煮水
	virtual void brew()
	{
		cout << "冲泡tea" << endl;
	}//冲泡
	virtual void pourInCup()
	{
		cout << "倒入杯中" << endl;
	}//倒入杯中
	virtual void putSomething(){
		cout << "加入柠檬" << endl;
	}
	//加入辅料
};

void doWork(AbstractDrink *abc)
{
	abc->makeDrink();
	delete abc;
}

void test()
{
	doWork(new Coffe);
	cout << "--------" << endl;
	doWork(new Tea);
	
}


int main(){
	
	
	test();
	system("pause");
	return 0;
}