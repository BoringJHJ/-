#pragma once
#include"Indentity.hpp"
#include<iostream>
#include"globalFile.hpp"
#include"Student.hpp"
#include"Teacher.hpp"
#include"Computer.hpp"
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
class Manage :public Indentity {
public:
	//无参构造
	Manage();
	//有参构造--设置姓名、学号、密码
	Manage(string name, string code);
	//选择菜单
	virtual void operMenu();
	//添加账户
	void AddPerson();
	//查看账户
	void SeePerson();
	//查看机房信息
	void ShowComputer();
	// 清空预约记录
	void CleanApplication();

	//初始化容器
	void InitVector();
	//检测账户是否重复
	bool CheakRepeat(string id,int type);
	
	//学生容器
	vector<Student> VStu;

	//教师容器
	vector<Teacher> VTea;

	//机房容器
	vector<Computer> vCom;
};