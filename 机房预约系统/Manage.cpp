#include"Manage.hpp"
//�޲ι���
Manage::Manage()
{

}
//�вι���--����������ѧ�š�����
Manage::Manage(string name, string code)
{
	this->m_Name = name;
	this->m_Code = code;
	//��ʼ������
	this->InitVector();
}
//ѡ��˵�
void Manage::operMenu()
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼!" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t-------------------------------" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      1�������˻�            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      2������˻�            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      3���鿴������Ϣ        |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      4�����ԤԼ��¼        |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      0��ע���˻�            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t-------------------------------" << endl;
	cout << endl;
}
//����˻�
void Manage::AddPerson()
{
	system("cls");
	cout << "1�����ѧ���˻�" << endl;
	cout << "2�������ʦ�˻�" << endl;
	cout << endl;
	cout << "��ѡ����Ҫ��ӵ��˻����ͣ�" << endl;
	int select;
	cin >> select;
	string fid;
	string filename;
	string fcode;
	string fname;
	if (select == 1)//���ѧ���˻�
	{
		filename = STUDENT_FILE;
		cout << "������ѧ��(-1�˳�)��";
		
	}
	else if (select == 2)//��ӽ�ʦ�˻�
	{
		filename = TEACHER_FILE;
		cout << "������ְ����(-1�˳�)��";
		
	}
	else
	{
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cin >> fid;
	while (true)
	{
		if (fid == "-1") { system("cls"); return; }
		bool ret = this->CheakRepeat(fid, select);
		if (ret)
		{
			cout << "�˻��Ѵ��ڣ�����������" << endl;
			cin >> fid;
		}
		else
		{
			break;
		}
	}
	cout << "�������û�����";
	cin >> fname;
	cout << "���������룺";
	cin >> fcode;
	//��������
	ofstream ofs(filename, ios::out | ios::app);
	ofs << fid << " " << fname << " " << fcode << endl;
	cout << "��ӳɹ���" << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}
//�鿴�˻�
void PrintStudent(Student &s)
{
	cout << "ѧ�ţ�" << s.m_Id << "  ������" << s.m_Name <<"  ���룺"<<s.m_Code<< endl;
}
void PrintTeacher(Teacher &t)
{
	cout << "ְ���ţ�" << t.m_EmpId << "  ������" << t.m_Name << "  ���룺" << t.m_Code << endl;
}
void Manage::SeePerson()
{
	system("cls");
	cout << "ѧ��������" << VStu.size() << endl;
	cout << "��ʦ������" << VTea.size() << endl;
	cout << endl;
	cout << endl;
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;
	cout << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		cout << "ѧ����Ϣ��" << endl;
		for_each(VStu.begin(), VStu.end(), PrintStudent);
	}
	else
	{
		cout << "��ʦ��Ϣ" << endl;
		for_each(VTea.begin(), VTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void PrintComputer(Computer &c)
{
	cout << "����" << c.m_ComId << "  ������" << c.m_Amount << endl;
}
void Manage::ShowComputer()
{
	system("cls");
	cout << "������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), PrintComputer);
	system("pause");
	system("cls");
}
// ���ԤԼ��¼
void Manage::CleanApplication()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	return;
}
//��ʼ������
void Manage::InitVector()
{
	//�������
	this->VStu.clear();
	this->VTea.clear();
	this->vCom.clear();
	//��ѧ���ļ�
	ifstream ifs(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout <<STUDENT_FILE<< "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	//����ѧ���ļ���Ϣ
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Code)
	{
		this->VStu.push_back(s);
	}
	//�ر��ļ�
	ifs.close();
	
	//�򿪽�ʦ�ļ�
	ifstream ifs2(TEACHER_FILE, ios::in);
	if (!ifs2.is_open())
	{
		cout << TEACHER_FILE << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	//���ս�ʦ�ļ���Ϣ
	Teacher t;
	while (ifs2 >> t.m_EmpId && ifs2 >> t.m_Name && ifs2 >> t.m_Code)
	{
		this->VTea.push_back(t);
	}
	//�ر��ļ�
	ifs2.close();

	//�򿪻�����Ϣ�ļ�
	ifstream ifs3(COMPUTER_FILE, ios::in);
	if (!ifs3.is_open())
	{
		cout << COMPUTER_FILE << "�ļ���ʧ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//���ջ�����Ϣ
	Computer c;
	while (ifs3 >> c.m_ComId && ifs3 >> c.m_Amount)
	{
		vCom.push_back(c);
	}
	//�ر��ļ�
	ifs3.close();
}
//����˻��Ƿ��ظ�
bool Manage::CheakRepeat(string id,int type)
{
	//���ѧ���˻�
	if (type == 1)
	{
		for (vector<Student>::iterator it = VStu.begin(); it != VStu.end(); it++)
		{
			if (id == (*it).m_Id)
			{
				cout << (*it).m_Id << endl;
				return true;
			}
			else
			{
				//return false;Ц��
			}
		}
		return false;
	}
	//����ʦ�˻�
	else
	{
		for (vector<Teacher>::iterator it = VTea.begin(); it != VTea.end(); it++)
		{
			if (id == (*it).m_EmpId)
			{
				return true;
			}
			else
			{
				//return false;
			}
		}
		return false;
	}
}