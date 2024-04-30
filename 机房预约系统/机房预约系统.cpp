#include<iostream>
#include<fstream>
using namespace std;
#include"Indentity.hpp"
#include"globalFile.hpp"
#include"Student.hpp"
#include"Teacher.hpp"
#include"Manage.hpp"

//����Ա�˵�
void ManageMenu(Indentity*&manage)
{
	while (true)
	{
		//����Ա�˵�
		manage->operMenu();
		//������ָ��ת��Ϊ����ָ�룬�������ര��
		Manage* man = (Manage*)manage;

		//�����û�ѡ��
		cout << "��������ѡ��";
		int select;
		cin >> select;
		if (select == 1)//�鿴�˻�
		{
			man->SeePerson();
		}
		else if (select == 2)//����˻�
		{
			man->AddPerson();
		}
		else if (select == 3)//�鿴������Ϣ
		{
			man->ShowComputer();
		}
		else if(select==4)//���ԤԼ��¼
		{
			man->CleanApplication();
		}
		else if(select==0) //ע���˻�
		{
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�������" << endl;
			system("pause");
			system("cls");
		}
	}
}
//ѧ���˵�
void StudentMenu(Indentity*& student)
{
	Student* s = (Student*)student;

	while (true)
	{
		//�˵�����
		s->operMenu();

		cout << "��ѡ����һ������" << endl;
		//�˵��ӿ�
		int select;
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			s->AplyOrder();
		}
		else if (select == 2)//�鿴�ҵ�ԤԼ
		{
			s->ShowMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			s->ShowAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			s->CancelOrder();
		}
		else if (select == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}
	}
}
//��ʦ�˵�
void TeacherMenu(Indentity*& ttudent)
{
	Teacher* t = (Teacher*)ttudent;

	while (true)
	{
		//�˵�����
		t->operMenu();

		cout << "��ѡ����һ������" << endl;
		//�˵��ӿ�
		int select;
		cin >> select;
		if (select == 1)//�鿴����ԤԼ
		{
			t->ShowAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			t->JudgeOrder();
		}
		else if (select == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}
	}
}
//��¼����
void LoginIn(string filename, int type)
{
	Indentity* person = NULL;
	//���ļ�
	ifstream ifs(filename, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	//׼�������û���Ϣ
	string id;
	string name;
	string code;

	if (type == 1)
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "������ְ����:" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> code;
	//��֤���
	switch (type)
	{
	case 1://��֤ѧ�����
	{
		//cout << 1;
		string fid;
		string fname;
		string fcode;
		while (ifs >> fid && ifs >> fname && ifs >> fcode)
		{
			
			if (fid == id && fname == name && fcode == code)
			{
				cout << "ѧ����¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, code);
				StudentMenu(person);
				return;
			}
		}
		break;
	}
	case 2://��֤��ʦ���
	{
		//cout << 1;
		string fid;
		string fname;
		string fcode;
		while (ifs >> fid && ifs >> fname && ifs >> fcode)
		{

			if (fid == id && fname == name && fcode == code)
			{
				cout << "��ʦ��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, code);
				TeacherMenu(person);
				return;
			}
		}
	}
		break;
	case 3://��֤����Ա���
	{
		string fname;
		string fcode;
		while ( ifs >> fname && ifs >> fcode)
		{

			if (fname == name && fcode == code)
			{
				cout << "����Ա��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manage(name, code);
				//����Ա�˵�
				ManageMenu(person);
				return;
			}
		}
	}
		break;
	default:
		break;
	}
	cout << "��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	while (true)
	{
		cout << "��ӭʹ�üͺ�������ԤԼϵͳ" << endl;
		cout << endl;
		cout << endl;
		cout << "\t------------------------------" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        1��ѧ����¼         |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        2����ʦ��¼         |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        3������Ա��¼       |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        0��ע����¼         |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t------------------------------" << endl;
		cout << endl;
		cout << "���������ѡ��";
		int select;
		cin >> select;
		switch (select)
		{
		case 1://ѧ����¼
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ��¼
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա��¼
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}