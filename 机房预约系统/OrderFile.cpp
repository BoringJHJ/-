#include"OrderFile.hpp"
//构造函数
OrderFile::OrderFile()
{
	this->InitMap();
}

//更新预约记录
void OrderFile::UpdateOrder()
{
	if (this->m_Amount == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofstream ofs(ORDER_FILE, ios::trunc | ios::out );
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->m_Amount; i++)
	{
		//第一个冒号不是英文的，与ApplyOrder()中的不一样，所以无法重复
		//找的我好苦啊
		ofs << "机房:" << this->m_OrderMap[i + 1]["机房:"] << " ";
		ofs << "学号:" << this->m_OrderMap[i + 1]["学号:"] << " ";
		ofs << "姓名:" << this->m_OrderMap[i + 1]["姓名:"] << " ";
		ofs << "日期:" << this->m_OrderMap[i + 1]["日期:"] << " ";
		ofs << "时间:" << this->m_OrderMap[i + 1]["时间:"] << " ";
		ofs << "预约状态:" << this->m_OrderMap[i + 1]["预约状态:"] <<endl;
	}
	ofs.close();
	/*for (int i = 0; i < this->m_Amount; i++)
	{
		cout << "机房：" << this->m_OrderMap[i + 1]["机房:"] << " "
			<< "学号：" << this->m_OrderMap[i + 1]["学号:"] << " "
			<< "姓名：" << this->m_OrderMap[i + 1]["姓名:"] << " "
			<< "日期：" << this->m_OrderMap[i + 1]["日期:"] << " "
			<< "时间：" << this->m_OrderMap[i + 1]["时间:"] << " "
			<< "预约状态：" << this->m_OrderMap[i + 1]["预约状态:"] << endl;
	}*/
}
//初始化容器
void OrderFile::InitMap()
{
	this->m_OrderMap.clear();
	m_Amount = 0;
	string room;
	string id;
	string name;
	string date;
	string timing;
	string status;

	//接收数据
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << ORDER_FILE << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//转换数据
	int pos=0;
	string key;
	string value;
	while (ifs >> room && ifs >> id && ifs >> name && ifs >> date && ifs >> timing && ifs >> status)
	{
		map<string, string>m;
		/*cout << room << endl;
		cout << id << endl;
		cout << name << endl;
		cout << date << endl;
		cout << timing << endl;
		cout << status << endl;*/
		//机房
		pos = room.find(":");
		//cout <<"pos=" << pos << endl;
		if (pos != -1)
		{
			key =room.substr(0, pos+1 );
			value= room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//学号
		pos = id.find(":");
		if (pos != -1)
		{
			key = id.substr(0, pos+1);
			value = id.substr(pos + 1, id.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//姓名
		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(0, pos+1);
			value = name.substr(pos + 1, name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//日期
		pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos+1);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//时间
		pos = timing.find(":");
		if (pos != -1)
		{
			key = timing.substr(0, pos+1);
			value = timing.substr(pos + 1, timing.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//预约状态
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos+1);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		/*for (map<string, string>::iterator mit2 = m.begin(); mit2 != m.end(); mit2++)
		{
			cout << "abc";
			cout << (*mit2).first << (*mit2).second << endl;
		}*/
		//保存数据
		this->m_Amount++;
		this->m_OrderMap.insert(make_pair(this->m_Amount,m));
		
	}
	ifs.close();
	//测试
	/*for (map<int, map<string, string>>::iterator it = this->m_OrderMap.begin(); it != m_OrderMap.end(); it++)
	{
		cout  << (*it).first << endl;
		cout << "b";
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		{
			cout << "c";
			cout << (*mit).first << (*mit).second << endl;
		}
	}*/
	
}
