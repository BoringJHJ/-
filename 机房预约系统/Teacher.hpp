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
	//�޲ι���
	Teacher();
	//�вι���--����������ѧ�š�����
	Teacher(string empid, string name, string code);
	//ѡ��˵�
	virtual void operMenu();
	//�鿴����ԤԼ
	void ShowAllOrder();
	//���ԤԼ
	void JudgeOrder();

	//��ʼ������
	//void InitVector();
	//ѧ��
	string m_EmpId;
	//��ʦ����
	//vector<Teacher>t;
};