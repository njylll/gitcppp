#include <iostream>
using namespace std;

//ʵ��ͨ�� �������������ĺ���
//���� �Ӵ�С
//�㷨 ѡ��
//���� char���飬int����
template<typename T>//����һ��ģ�壬���߱���������Ĵ�������ŵ�T��Ҫ����T��һ��ͨ����������
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
        int max = i;//�϶����ֵ�±�

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