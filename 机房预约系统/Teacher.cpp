#include"Teacher.hpp"
//�޲ι���
Teacher::Teacher()
{

}
//�вι���--����������ѧ�š�����
Teacher::Teacher(string empid, string name, string code)
{
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Code = code;

}
//ѡ��˵�
void Teacher::operMenu()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t-------------------------------" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      1���鿴����ԤԼ        |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      2�����ԤԼ            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      0��ע���˻�            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t-------------------------------" << endl;
	cout << endl;
}
//�鿴����ԤԼ
void Teacher::ShowAllOrder()
{
	Student s;
	s.ShowAllOrder();
}
//���ԤԼ
void Teacher::JudgeOrder()
{
	system("cls");
	OrderFile o;
	vector<int>v;
	//ͨ�������ҵ�����ԤԼ
	int index = 1;
	for (int i = 0; i < o.m_Amount; i++)
	{
		
		//0-ȡ��ԤԼ  1-�������  2-ԤԼ�ɹ�  3-ԤԼʧ��
		if (o.m_OrderMap[i + 1]["ԤԼ״̬:"] == "1")
		{
			v.push_back(i + 1);
			string status = "״̬��";
			//ת������ļ�����
			cout << index<< "��";
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


	//ȡ��ԤԼ
	int select;
	cout << "��������ͨ����ԤԼ��ţ�-1���أ�" << endl;
	while (true)
	{
		cin >> select;
		if (select == -1)
		{
			system("cls");
			return;
		}
		else if (select > 0 && select <= o.m_Amount)
		{
			o.m_OrderMap[v[select-1]]["ԤԼ״̬:"] = "2";
			cout << "ԤԼ�ɹ�!" << endl;
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
//void Teacher::InitVector()
//{
//
//}