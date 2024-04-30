#include<iostream>
#include<map>
#include<vector>
#include<fstream>
#include"globalFile.hpp"
using namespace std;
class OrderFile {
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void UpdateOrder();

	//初始化容器
	void InitMap();
	//预约记录容器
	map<int, map<string, string>> m_OrderMap;
	//预约记录条数
	int m_Amount=0;
};