#include <iostream>
using namespace std;

class AbstractDrink
{
	public:
	
	virtual void boil()=0;//��ˮ
	virtual void brew()=0;//����
	virtual void pourInCup()=0;//���뱭��
	virtual void putSomething()=0;//���븨��
	
	void makeDrink()
	{
		boil();
		brew();
		pourInCup();
		putSomething();
		
		
	}
};

//��������
class Coffe: public AbstractDrink
{
	public:
	
	virtual void boil()
	{
		cout << "��ˮ" << endl;
	}//��ˮ
	virtual void brew()
	{
		cout << "����coffe" << endl;
	}//����
	virtual void pourInCup()
	{
		cout << "���뱭��" << endl;
	}//���뱭��
	virtual void putSomething(){
		cout << "����ţ��" << endl;
	}
	//���븨��
};

class Tea: public AbstractDrink
{
	public:
	
	virtual void boil()
	{
		cout << "��ˮ" << endl;
	}//��ˮ
	virtual void brew()
	{
		cout << "����tea" << endl;
	}//����
	virtual void pourInCup()
	{
		cout << "���뱭��" << endl;
	}//���뱭��
	virtual void putSomething(){
		cout << "��������" << endl;
	}
	//���븨��
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