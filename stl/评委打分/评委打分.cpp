#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

/*
有什么名选手ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分，取平均分
*/
class Person
{
public:
    Person(string name, int score):m_Name(name),m_Score(score){};

    string m_Name;
    float m_Score;
};

void createPerson(vector<Person> &v)
{
    for(int i = 0; i < 5; i++)
    {
        string nameSeed = "ABCDE";
        string name = "选手";
        name +=  nameSeed[i];

        float score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //将评委分数放入deque容器
        deque<int> d;
        for(int i = 0; i < 10; i++)
        {
            float score = rand() % 41 + 60;//60 ~ 100  rand()%41为随机0 ~40
            d.push_back(score);
        }
            // for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
            // {
        
            //     cout <<  *dit << " ";
            // }
            //cout << endl;

            sort(d.begin(), d.end());
            d.pop_back();
            d.pop_front();

            //取平均分
            float sum = 0;
            for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
            {
                sum += (*dit);
            }
           // cout << "d.size() = " << d.size() << endl;
            float avg = sum/d.size();
            it->m_Score = avg;
    }
}

void showScore(const vector<Person> &p)
{
    for(vector<Person>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " 平均分：" << it->m_Score << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<Person> v;//存放选手的容器
    createPerson(v);
    // for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << (*it).m_Name << " 得分：" << (*it).m_Score << endl;
    // }
    setScore(v);
    showScore(v);
    return 0;
}


