#include"Teacher.hpp"
//无参构造
Teacher::Teacher()
{

}
//有参构造--设置姓名、学号、密码
Teacher::Teacher(string empid, string name, string code)
{
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Code = code;

}
//选择菜单
void Teacher::operMenu()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t-------------------------------" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      1、查看所有预约        |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      2、审核预约            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t|      0、注销账户            |" << endl;
	cout << "\t|                             |" << endl;
	cout << "\t-------------------------------" << endl;
	cout << endl;
}
//查看所有预约
void Teacher::ShowAllOrder()
{
	Student s;
	s.ShowAllOrder();
}
//审核预约
void Teacher::JudgeOrder()
{
	system("cls");
	OrderFile o;
	vector<int>v;
	//通过容器找到本人预约
	int index = 1;
	for (int i = 0; i < o.m_Amount; i++)
	{
		
		//0-取消预约  1-正在审核  2-预约成功  3-预约失败
		if (o.m_OrderMap[i + 1]["预约状态:"] == "1")
		{
			v.push_back(i + 1);
			string status = "状态：";
			//转换输出文件内容
			cout << index<< "、";
			cout << o.m_OrderMap[i + 1]["机房:"] << "号机房" << "   ";
			cout << "周" << o.m_OrderMap[i + 1]["日期:"] << "   ";
			cout << "时间：" << (o.m_OrderMap[i + 1]["时间:"] == "1" ? "上午" : "下午") << "   ";
			if (o.m_OrderMap[i + 1]["预约状态:"] == "1")
			{
				status += "正在审核";
			}
			else if (o.m_OrderMap[i + 1]["预约状态:"] == "2")
			{
				status += "预约成功";
			}
			cout << status << endl;
			index++;
		}
	}


	//取消预约
	int select;
	cout << "请输入想通过的预约编号（-1返回）" << endl;
	while (true)
	{
		cin >> select;
		if (select == -1)
		{
			system("cls");
			return;
		}
		else if (select > 0 && select <= o.m_Amount)
		{
			o.m_OrderMap[v[select-1]]["预约状态:"] = "2";
			cout << "预约成功!" << endl;
			break;
		}
		else
		{
			cout << "输入错误!请重新输入" << endl;
		}
	}
	//更新容器
	o.UpdateOrder();

	system("pause");
	system("cls");
}
//初始化容器
//void Teacher::InitVector()
//{
//
//}