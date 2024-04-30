#include"Student.hpp"
//using namespace std;
//�޲ι���
Student::Student()
{

}
//�вι���--����������ѧ�š�����
Student::Student(string id, string name, string code)
{
	this->m_Code = code;
	this->m_Id = id;
	this->m_Name = name;
	//��ʼ������
	this->InitVector();
}
//ѡ��˵�
 void Student::operMenu()
{
	 cout << endl;
	 cout << endl;
	 cout << endl;
	 cout << "\t-------------------------------" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      1������ԤԼ            |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      2���鿴�ҵ�ԤԼ        |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      3���鿴����ԤԼ        |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      4��ȡ��ԤԼ            |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      0��ע���˻�            |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t-------------------------------" << endl;
	 cout << endl;
}
//����ԤԼ
 void PrintComputer2(Computer&c)
 {
	 cout << c.m_ComId << "�Ż���     ������" << c.m_Amount << endl;
 }
void Student::AplyOrder()
{
	system("cls");
	int room;
	int date;
	int timing;

	//ѡ�����
	cout << "������Ϣ���£�" << endl;
	for_each(VCom.begin(), VCom.end(), PrintComputer2);
	cout << "\n��ѡ�������" ;
	cin >> room;
	cout <<"-----------------------------------------"<< endl;
	//ѡ������
	cout << "1������һ" << endl;
	cout << "2�����ڶ�" << endl;
	cout << "3��������" << endl;
	cout << "4��������" << endl;
	cout << "5��������" << endl;
	cout << "\n��ѡ�����ڣ�";
	cin >> date;
	cout <<"-----------------------------------------"<< endl;
	//ѡ��ʱ��
	cout <<"1������"<< endl;
	cout <<"2������"<< endl;
	cout << "\n��ѡ��ʱ�䣺";
	cin >> timing;

	//��������
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofs << "����:" << room <<" ѧ��:"<<this->m_Id<<" ����:"<<this->m_Name<< " ����:" << date 
		<< " ʱ��:" << timing <<" ԤԼ״̬:"<<"1" << endl;
	cout << "����ɹ���" << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//�鿴�ҵ�ԤԼ
void Student::ShowMyOrder()
{
	system("cls");
	OrderFile o;
	//��������
	o.UpdateOrder();
	cout << "------------------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < o.m_Amount; i++)
	{
		string status="״̬��";
		if (o.m_OrderMap[i + 1]["ѧ��:"] == this->m_Id)
		{
			//ת������ļ�����
			cout << o.m_OrderMap[i + 1]["����:"] << "�Ż���" << "   ";
			cout << "��" << o.m_OrderMap[i + 1]["����:"] << "   ";
			cout << "ʱ�䣺" << (o.m_OrderMap[i + 1]["ʱ��:"]=="1"?"����":"����") << "   ";
			//0-ȡ��ԤԼ  1-�������  2-ԤԼ�ɹ�  3-ԤԼʧ��
			if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "1")
			{
				status += "�������";
			}
			else if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if(o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "3")
			{
				status += "ԤԼʧ��";
			}
			else if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "0")
			{
				status += "��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}
//�鿴����ԤԼ
void Student::ShowAllOrder()
{
	system("cls");
	OrderFile o;
	//��������
	o.UpdateOrder();
	cout << "------------------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < o.m_Amount; i++)
	{
		string status = "״̬��";
		cout << "����:" << o.m_OrderMap[i + 1]["����:"] << "   ";
		cout << "ѧ��:" << o.m_OrderMap[i + 1]["ѧ��:"] << "   ";
		cout << "����:" << o.m_OrderMap[i + 1]["����:"] << "   ";
		cout << "��" << o.m_OrderMap[i + 1]["����:"] << "   ";
		cout << "ʱ�䣺" << (o.m_OrderMap[i + 1]["ʱ��:"] == "1" ? "����" : "����") << "   ";
		//0-ȡ��ԤԼ  1-�������  2-ԤԼ�ɹ�  3-ԤԼʧ��
		if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "1")
		{
			status += "�������";
		}
		else if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "3")
		{
			status += "ԤԼʧ��";
		}
		else if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "0")
		{
			status += "��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
	return;
}
//ȡ��ԤԼ
int index=1;
void Student::CancelOrder()
{
	system("cls");
	OrderFile o;
	vector<int>v;
	//ͨ�������ҵ�����ԤԼ
	for (int i = 0; i < o.m_Amount; i++)
	{
		if (o.m_OrderMap[i + 1]["ѧ��:"] == this->m_Id)
		{
			//0-ȡ��ԤԼ  1-�������  2-ԤԼ�ɹ�  3-ԤԼʧ��
			if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "1" || o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "2")
			{
				string status = "״̬��";
				v.push_back(i+1);//���������ø�����
				//ת������ļ�����
				cout << index<<"��";
				cout << o.m_OrderMap[i + 1]["����:"] << "�Ż���" << "   ";
				cout << "��" << o.m_OrderMap[i + 1]["����:"] << "   ";
				cout << "ʱ�䣺" << (o.m_OrderMap[i + 1]["ʱ��:"] == "1" ? "����" : "����") << "   ";
				if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "1")
				{
					status += "�������";
				}
				else if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
				index++;
			}
		}
		
	}
	//ȡ��ԤԼ
	int select;
	cout << "��������ȡ����ԤԼ��ţ�-1���أ�" << endl;
	while (true)
	{
		cin >> select;
		if (select == -1)
		{
			system("cls");
			return;
		}
		else if (select > 0 && select <= v.size())
		{
			//select-1����������Ӧ�����ı�ţ�������ļ��е���ʵλ������---  |1->0|2->1....
			o.m_OrderMap[v[select - 1]]["ԤԼ״̬:"] = "0";
			cout << "ȡ���ɹ�!" << endl;
			break;
		}
		else
		{
			cout << "�������!����������" << endl;
		}
	}
	//��������
	o.UpdateOrder();

	system("pause");
	system("cls");
}

//��ʼ������
void Student::InitVector()
{
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//���ջ�����Ϣ
	Computer c;
	while (ifs >> c.m_ComId && ifs >> c.m_Amount)
	{
		VCom.push_back(c);
	}
	//�ر��ļ�
	ifs.close();
}