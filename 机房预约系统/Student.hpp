#pragma once
#include"Indentity.hpp"
#include"globalFile.hpp"
#include"Computer.hpp"
#include"OrderFile.hpp"
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
class Student:public Indentity {
public:
	//无参构造
	Student();
	//有参构造--设置姓名、学号、密码
	Student(string id,string name,  string code);
	//选择菜单
	virtual void operMenu();
	//申请预约
	void AplyOrder();
	//查看我的预约
	void ShowMyOrder();
	//查看所有预约
	void ShowAllOrder();
	//取消预约
	void CancelOrder();

	//初始化容器
	void InitVector();

	//学号
	string m_Id;
	//机房容器
	vector<Computer> VCom;
};