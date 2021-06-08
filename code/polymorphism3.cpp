#include <iostream>
using namespace std; 
class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU *cpu,VideoCard *vc,Memory *mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//工作函数
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
private:
	
	CPU *m_cpu;
	VideoCard *m_vc;
	Memory *m_mem;
};


class IntelCpu : public CPU
{
public:
	void calculate()
	{
		cout << "IntelCpu运行" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "IntelVideoCard运行" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	void storage()
	{
		cout << "IntelMemory" << endl;
	}
};
class LenovoCpu : public CPU
{
public:
	void calculate()
	{
		cout << "LenovoCpu" << endl;
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "LenovoVideoCard" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	void storage()
	{
		cout << "LenovoMemory" << endl;
	}
};

void test01(){
	
	CPU *intelCpu = new IntelCpu;
	VideoCard *intelCard = new IntelVideoCard;
	Memory *intelMemory = new IntelMemory;
	
	Computer *computer01 = new Computer(intelCpu,intelCard,intelMemory);
	computer01->work();
	delete computer01;
	
}

int main()
{
	test01();
	system("pause");
	return 0;
}
