#include"OrderFile.hpp"
//���캯��
OrderFile::OrderFile()
{
	this->InitMap();
}

//����ԤԼ��¼
void OrderFile::UpdateOrder()
{
	if (this->m_Amount == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofstream ofs(ORDER_FILE, ios::trunc | ios::out );
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < this->m_Amount; i++)
	{
		//��һ��ð�Ų���Ӣ�ĵģ���ApplyOrder()�еĲ�һ���������޷��ظ�
		//�ҵ��Һÿడ
		ofs << "����:" << this->m_OrderMap[i + 1]["����:"] << " ";
		ofs << "ѧ��:" << this->m_OrderMap[i + 1]["ѧ��:"] << " ";
		ofs << "����:" << this->m_OrderMap[i + 1]["����:"] << " ";
		ofs << "����:" << this->m_OrderMap[i + 1]["����:"] << " ";
		ofs << "ʱ��:" << this->m_OrderMap[i + 1]["ʱ��:"] << " ";
		ofs << "ԤԼ״̬:" << this->m_OrderMap[i + 1]["ԤԼ״̬:"] <<endl;
	}
	ofs.close();
	/*for (int i = 0; i < this->m_Amount; i++)
	{
		cout << "������" << this->m_OrderMap[i + 1]["����:"] << " "
			<< "ѧ�ţ�" << this->m_OrderMap[i + 1]["ѧ��:"] << " "
			<< "������" << this->m_OrderMap[i + 1]["����:"] << " "
			<< "���ڣ�" << this->m_OrderMap[i + 1]["����:"] << " "
			<< "ʱ�䣺" << this->m_OrderMap[i + 1]["ʱ��:"] << " "
			<< "ԤԼ״̬��" << this->m_OrderMap[i + 1]["ԤԼ״̬:"] << endl;
	}*/
}
//��ʼ������
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

	//��������
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << ORDER_FILE << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	//ת������
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
		//����
		pos = room.find(":");
		//cout <<"pos=" << pos << endl;
		if (pos != -1)
		{
			key =room.substr(0, pos+1 );
			value= room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//ѧ��
		pos = id.find(":");
		if (pos != -1)
		{
			key = id.substr(0, pos+1);
			value = id.substr(pos + 1, id.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//����
		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(0, pos+1);
			value = name.substr(pos + 1, name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//����
		pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos+1);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//ʱ��
		pos = timing.find(":");
		if (pos != -1)
		{
			key = timing.substr(0, pos+1);
			value = timing.substr(pos + 1, timing.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//ԤԼ״̬
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
		//��������
		this->m_Amount++;
		this->m_OrderMap.insert(make_pair(this->m_Amount,m));
		
	}
	ifs.close();
	//����
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
