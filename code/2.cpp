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

//地址早绑定，已确定调用的是animal的speak
void doSpeak(Animal &animal)
{
    animal.speak();
    

}

void test()
{
    Cat cat;
    doSpeak(cat);

}


int main(){
    
    test();
    system("pause");
    return 0;
}