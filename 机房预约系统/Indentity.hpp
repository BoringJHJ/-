#pragma once
#include<iostream>
using namespace std;
class Indentity {
public:
	//操作菜单
	virtual void operMenu()=0;
	//用户名
	string m_Name;
	//密码
	string m_Code;
};