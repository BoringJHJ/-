#include<iostream>
#include<fstream>
using namespace std;
#include"Indentity.hpp"
#include"globalFile.hpp"
#include"Student.hpp"
#include"Teacher.hpp"
#include"Manage.hpp"

//管理员菜单
void ManageMenu(Indentity*&manage)
{
	while (true)
	{
		//管理员菜单
		manage->operMenu();
		//将父类指针转换为子类指针，调用子类窗口
		Manage* man = (Manage*)manage;

		//接收用户选择
		cout << "输入您的选择：";
		int select;
		cin >> select;
		if (select == 1)//查看账户
		{
			man->SeePerson();
		}
		else if (select == 2)//添加账户
		{
			man->AddPerson();
		}
		else if (select == 3)//查看机房信息
		{
			man->ShowComputer();
		}
		else if(select==4)//清空预约记录
		{
			man->CleanApplication();
		}
		else if(select==0) //注销账户
		{
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
		}
	}
}
//学生菜单
void StudentMenu(Indentity*& student)
{
	Student* s = (Student*)student;

	while (true)
	{
		//菜单界面
		s->operMenu();

		cout << "请选择下一步操作" << endl;
		//菜单接口
		int select;
		cin >> select;
		if (select == 1)//申请预约
		{
			s->AplyOrder();
		}
		else if (select == 2)//查看我的预约
		{
			s->ShowMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			s->ShowAllOrder();
		}
		else if (select == 4)//取消预约
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
			cout << "输入错误！请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}
//教师菜单
void TeacherMenu(Indentity*& ttudent)
{
	Teacher* t = (Teacher*)ttudent;

	while (true)
	{
		//菜单界面
		t->operMenu();

		cout << "请选择下一步操作" << endl;
		//菜单接口
		int select;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			t->ShowAllOrder();
		}
		else if (select == 2)//审核预约
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
			cout << "输入错误！请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}
//登录功能
void LoginIn(string filename, int type)
{
	Indentity* person = NULL;
	//读文件
	ifstream ifs(filename, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	//准备接收用户信息
	string id;
	string name;
	string code;

	if (type == 1)
	{
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> code;
	//验证身份
	switch (type)
	{
	case 1://验证学生身份
	{
		//cout << 1;
		string fid;
		string fname;
		string fcode;
		while (ifs >> fid && ifs >> fname && ifs >> fcode)
		{
			
			if (fid == id && fname == name && fcode == code)
			{
				cout << "学生登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, code);
				StudentMenu(person);
				return;
			}
		}
		break;
	}
	case 2://验证教师身份
	{
		//cout << 1;
		string fid;
		string fname;
		string fcode;
		while (ifs >> fid && ifs >> fname && ifs >> fcode)
		{

			if (fid == id && fname == name && fcode == code)
			{
				cout << "教师登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, code);
				TeacherMenu(person);
				return;
			}
		}
	}
		break;
	case 3://验证管理员身份
	{
		string fname;
		string fcode;
		while ( ifs >> fname && ifs >> fcode)
		{

			if (fname == name && fcode == code)
			{
				cout << "管理员登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manage(name, code);
				//管理员菜单
				ManageMenu(person);
				return;
			}
		}
	}
		break;
	default:
		break;
	}
	cout << "验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	while (true)
	{
		cout << "欢迎使用纪海俊机房预约系统" << endl;
		cout << endl;
		cout << endl;
		cout << "\t------------------------------" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        1、学生登录         |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        2、教师登录         |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        3、管理员登录       |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t|        0、注销登录         |" << endl;
		cout << "\t|                            |" << endl;
		cout << "\t------------------------------" << endl;
		cout << endl;
		cout << "请输入你的选择：";
		int select;
		cin >> select;
		switch (select)
		{
		case 1://学生登录
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://教师登录
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员登录
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入错误！请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}