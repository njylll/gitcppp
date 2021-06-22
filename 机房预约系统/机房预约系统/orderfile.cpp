#include "orderfile.h"


//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILR, ios::in);
	string date;
	string interval;
	string stuName;
	string stuId;
	string status;
	string roomId;

	this->m_Size = 0;

	while (ifs >> date >> interval >> stuId >> stuName >> roomId >> status)
	{
		map<string, string>m;
		m.insert(getPair(date));
		m.insert(getPair(interval));
		m.insert(getPair(stuId));
		m.insert(getPair(stuName));
		m.insert(getPair(roomId));
		m.insert(getPair(status));

		mOrderData.insert(make_pair(m_Size, m));
		m_Size++;
	}
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (m_Size == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILR, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << mOrderData[i]["date"] << " ";
		ofs << "interval:" << mOrderData[i]["interval"] << " ";
		ofs << "stuId:" << mOrderData[i]["stuId"] << " ";
		ofs << "stuName:" << mOrderData[i]["stuName"] << " ";
		ofs << "roomId:" << mOrderData[i]["roomId"] << " ";
		ofs << "status:" << mOrderData[i]["status"] << endl;

	}
	ofs.close();
}

//截取信息
pair<string, string> OrderFile::getPair(string &str)
{
	int pos;
	string key;
	string value;
	pos = str.find(":");
	if (pos != -1)
	{
		key = str.substr(0, pos);
		value = str.substr(pos + 1, str.size() - pos-1);
	}
	//cout << "value:" << value;
	pair<string, string>p(key, value);
	return p;

}