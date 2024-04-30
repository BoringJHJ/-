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
	//�޲ι���
	Manage();
	//�вι���--����������ѧ�š�����
	Manage(string name, string code);
	//ѡ��˵�
	virtual void operMenu();
	//����˻�
	void AddPerson();
	//�鿴�˻�
	void SeePerson();
	//�鿴������Ϣ
	void ShowComputer();
	// ���ԤԼ��¼
	void CleanApplication();

	//��ʼ������
	void InitVector();
	//����˻��Ƿ��ظ�
	bool CheakRepeat(string id,int type);
	
	//ѧ������
	vector<Student> VStu;

	//��ʦ����
	vector<Teacher> VTea;

	//��������
	vector<Computer> vCom;
};