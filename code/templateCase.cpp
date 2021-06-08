#include <iostream>
using namespace std;

//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char数组，int数组
template<typename T>//声明一个模板，告诉编译器后面的代码紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void mySort(T arr[],int len)
{
    for(int i = 0;i < len;i++)
    {
        int max = i;//认定最大值下标

        for(int j = i+1;j < len; j++)
        {
            if(arr[max] < arr[j])
            max = j;
        }
        if(max != i)
        {
            mySwap(arr[max], arr[i]);
            
        }
    }
}
template<class T>
void printArray(T arr[], int len)

{
    for(int i = 0;i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void test01()
{
    char charArr[] = "badcfe";
    int num = sizeof(charArr)/sizeof(char);
    mySort(charArr, num);
    printArray(charArr,num);

    int intArr[] = {1,23,8,3,7,4,54,89};
    num = sizeof(intArr)/sizeof(int);
    mySort(intArr,num);
    printArray(intArr,num);


}

int main()
{
    test01();
    system("pause");
    return 0;
}