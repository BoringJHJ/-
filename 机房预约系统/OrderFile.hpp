#include<iostream>
#include<map>
#include<vector>
#include<fstream>
#include"globalFile.hpp"
using namespace std;
class OrderFile {
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void UpdateOrder();

	//��ʼ������
	void InitMap();
	//ԤԼ��¼����
	map<int, map<string, string>> m_OrderMap;
	//ԤԼ��¼����
	int m_Amount=0;
};