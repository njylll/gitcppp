#include <iostream>
using namespace std;

//多态


class Animal
{
    public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }	

    


};


class Cat :public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
    int a;
};

//Animal::speak不加virtual，地址早绑定，已确定调用的是animal的speak
//Animal::speak加virtual,地址晚绑定，调用传入对象的重写函数(函数返回值类型，函数名，形参列表完全相同)
//参数为父类的引用，实际指向子类对象
void doSpeak(Animal &animal)

{
    animal.speak();
    

}

void test()
{
    Cat cat;
    doSpeak(cat);

}
void test02()
{
	cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
	
}


int main(){
    
   // test();
	test02();
    system("pause");
    return 0;
}