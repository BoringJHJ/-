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
	//�޲ι���
	Student();
	//�вι���--����������ѧ�š�����
	Student(string id,string name,  string code);
	//ѡ��˵�
	virtual void operMenu();
	//����ԤԼ
	void AplyOrder();
	//�鿴�ҵ�ԤԼ
	void ShowMyOrder();
	//�鿴����ԤԼ
	void ShowAllOrder();
	//ȡ��ԤԼ
	void CancelOrder();

	//��ʼ������
	void InitVector();

	//ѧ��
	string m_Id;
	//��������
	vector<Computer> VCom;
};