#include"Manage.hpp"
//无参构造
Manage::Manage()
{

}
//有参构造--设置姓名、学号、密码
Manage::Manage(string name, string code)
{
	this->m_Name = name;
	this->m_Code = code;
	//初始化容器
	this->InitVector();
}
//选择菜单
void Manage::operMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录!" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t-------------------------------" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      1、查找账户            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      2、添加账户            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      3、查看机房信息        |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      4、清空预约记录        |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      0、注销账户            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t-------------------------------" << endl;
	cout << endl;
}
//添加账户
void Manage::AddPerson()
{
	system("cls");
	cout << "1、添加学生账户" << endl;
	cout << "2、添加老师账户" << endl;
	cout << endl;
	cout << "请选择您要添加的账户类型：" << endl;
	int select;
	cin >> select;
	string fid;
	string filename;
	string fcode;
	string fname;
	if (select == 1)//添加学生账户
	{
		filename = STUDENT_FILE;
		cout << "请设置学号(-1退出)：";
		
	}
	else if (select == 2)//添加教师账户
	{
		filename = TEACHER_FILE;
		cout << "请设置职工号(-1退出)：";
		
	}
	else
	{
		cout << "输入错误！" << endl;
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
			cout << "账户已存在！请重新输入" << endl;
			cin >> fid;
		}
		else
		{
			break;
		}
	}
	cout << "请设置用户名：";
	cin >> fname;
	cout << "请设置密码：";
	cin >> fcode;
	//保存数据
	ofstream ofs(filename, ios::out | ios::app);
	ofs << fid << " " << fname << " " << fcode << endl;
	cout << "添加成功！" << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}
//查看账户
void PrintStudent(Student &s)
{
	cout << "学号：" << s.m_Id << "  姓名：" << s.m_Name <<"  密码："<<s.m_Code<< endl;
}
void PrintTeacher(Teacher &t)
{
	cout << "职工号：" << t.m_EmpId << "  姓名：" << t.m_Name << "  密码：" << t.m_Code << endl;
}
void Manage::SeePerson()
{
	system("cls");
	cout << "学生数量：" << VStu.size() << endl;
	cout << "教师数量：" << VTea.size() << endl;
	cout << endl;
	cout << endl;
	cout << "请选择查看内容" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;
	cout << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		cout << "学生信息：" << endl;
		for_each(VStu.begin(), VStu.end(), PrintStudent);
	}
	else
	{
		cout << "教师信息" << endl;
		for_each(VTea.begin(), VTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void PrintComputer(Computer &c)
{
	cout << "机房" << c.m_ComId << "  总数：" << c.m_Amount << endl;
}
void Manage::ShowComputer()
{
	system("cls");
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), PrintComputer);
	system("pause");
	system("cls");
}
// 清空预约记录
void Manage::CleanApplication()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "清理成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	return;
}
//初始化容器
void Manage::InitVector()
{
	//清空容器
	this->VStu.clear();
	this->VTea.clear();
	this->vCom.clear();
	//打开学生文件
	ifstream ifs(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout <<STUDENT_FILE<< "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//接收学生文件信息
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Code)
	{
		this->VStu.push_back(s);
	}
	//关闭文件
	ifs.close();
	
	//打开教师文件
	ifstream ifs2(TEACHER_FILE, ios::in);
	if (!ifs2.is_open())
	{
		cout << TEACHER_FILE << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//接收教师文件信息
	Teacher t;
	while (ifs2 >> t.m_EmpId && ifs2 >> t.m_Name && ifs2 >> t.m_Code)
	{
		this->VTea.push_back(t);
	}
	//关闭文件
	ifs2.close();

	//打开机房信息文件
	ifstream ifs3(COMPUTER_FILE, ios::in);
	if (!ifs3.is_open())
	{
		cout << COMPUTER_FILE << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//接收机房信息
	Computer c;
	while (ifs3 >> c.m_ComId && ifs3 >> c.m_Amount)
	{
		vCom.push_back(c);
	}
	//关闭文件
	ifs3.close();
}
//检测账户是否重复
bool Manage::CheakRepeat(string id,int type)
{
	//检测学生账户
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
				//return false;笑死
			}
		}
		return false;
	}
	//检测教师账户
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