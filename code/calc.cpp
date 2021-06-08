#include <iostream>
using namespace std;



//普通写法

class Calculater
{
public:
	
	int getResult(string oper)
	{
		if(oper == "+")
		{
			return num1+num2;
			
		}
		else if(oper == "-")
		{
			return num1-num2;
		}
		else if (oper == "*")
		{
			return num1*num2;
		}
		
	}

	int num1;
	int num2;
	
};
//多态写法
//实现计算器的抽象类

class AbstractCalculator
{
	public:
	
	virtual int getResult()=0;//纯虚函数
	
	
	
	int num2;
	int num1;
};

class AddCalculator : public AbstractCalculator
{
	
	public:
	
	 int getResult()
	{
			return num1 + num2;
	}
	
};

class SubCalculator : public AbstractCalculator
{
	
	public:
	
	 int getResult()
	{
			return num1 - num2;
	}
	
};

class MulCalculator : public AbstractCalculator
{
	
	public:
	
	 int getResult()
	{
			return num1 * num2;
	}
	
};

void test02()
{
	//加法
	AbstractCalculator *abc = new AddCalculator;
	abc->num1 = 10;
	abc->num2 = 20;
	
	cout << abc->num1 << "+" << abc->num2 << "=" << abc->getResult() << endl;
	delete abc;
	
	abc = new SubCalculator;
	abc->num1 = 20;
	abc->num2 = 29;
	cout << abc->num1 << "-" << abc->num2 << "=" << abc->getResult() << endl;
	
}

int main()
{
	// Calculater c;
	// c.num1 = 10;
	// c.num2 = 20;
	
	// cout << c.num1 << "+" << c.num2  << "=" << c.getResult("+") << endl;
	test02();
	
	system("pause");
	
	return 0;
}