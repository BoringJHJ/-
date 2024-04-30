#pragma once
#include"Indentity.hpp"
#include<iostream>
#include<vector>
#include"globalFile.hpp"
#include"Student.hpp"
//#include"OrderFile.hpp"
using namespace std;
class Teacher :public Indentity {
public:
	//无参构造
	Teacher();
	//有参构造--设置姓名、学号、密码
	Teacher(string empid, string name, string code);
	//选择菜单
	virtual void operMenu();
	//查看所有预约
	void ShowAllOrder();
	//审核预约
	void JudgeOrder();

	//初始化容器
	//void InitVector();
	//学号
	string m_EmpId;
	//教师容器
	//vector<Teacher>t;
};