#include"Student.hpp"
//using namespace std;
//无参构造
Student::Student()
{

}
//有参构造--设置姓名、学号、密码
Student::Student(string id, string name, string code)
{
	this->m_Code = code;
	this->m_Id = id;
	this->m_Name = name;
	//初始化容器
	this->InitVector();
}
//选择菜单
 void Student::operMenu()
{
	 cout << endl;
	 cout << endl;
	 cout << endl;
	 cout << "\t-------------------------------" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      1、申请预约            |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      2、查看我的预约        |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      3、查看所有预约        |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      4、取消预约            |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t|      0、注销账户            |" << endl;
	 cout << "\t|                             |" << endl;
	 cout << "\t-------------------------------" << endl;
	 cout << endl;
}
//申请预约
 void PrintComputer2(Computer&c)
 {
	 cout << c.m_ComId << "号机房     总数：" << c.m_Amount << endl;
 }
void Student::AplyOrder()
{
	system("cls");
	int room;
	int date;
	int timing;

	//选择机房
	cout << "机房信息如下：" << endl;
	for_each(VCom.begin(), VCom.end(), PrintComputer2);
	cout << "\n请选择机房：" ;
	cin >> room;
	cout <<"-----------------------------------------"<< endl;
	//选择日期
	cout << "1、星期一" << endl;
	cout << "2、星期二" << endl;
	cout << "3、星期三" << endl;
	cout << "4、星期四" << endl;
	cout << "5、星期五" << endl;
	cout << "\n请选择日期：";
	cin >> date;
	cout <<"-----------------------------------------"<< endl;
	//选择时间
	cout <<"1、上午"<< endl;
	cout <<"2、下午"<< endl;
	cout << "\n请选择时间：";
	cin >> timing;

	//保存数据
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << ORDER_FILE << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofs << "机房:" << room <<" 学号:"<<this->m_Id<<" 姓名:"<<this->m_Name<< " 日期:" << date 
		<< " 时间:" << timing <<" 预约状态:"<<"1" << endl;
	cout << "申请成功！" << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//查看我的预约
void Student::ShowMyOrder()
{
	system("cls");
	OrderFile o;
	//更新数据
	o.UpdateOrder();
	cout << "------------------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < o.m_Amount; i++)
	{
		string status="状态：";
		if (o.m_OrderMap[i + 1]["学号:"] == this->m_Id)
		{
			//转换输出文件内容
			cout << o.m_OrderMap[i + 1]["机房:"] << "号机房" << "   ";
			cout << "周" << o.m_OrderMap[i + 1]["日期:"] << "   ";
			cout << "时间：" << (o.m_OrderMap[i + 1]["时间:"]=="1"?"上午":"下午") << "   ";
			//0-取消预约  1-正在审核  2-预约成功  3-预约失败
			if (o.m_OrderMap[i + 1]["预约状态:"] == "1")
			{
				status += "正在审核";
			}
			else if (o.m_OrderMap[i + 1]["预约状态:"] == "2")
			{
				status += "预约成功";
			}
			else if(o.m_OrderMap[i + 1]["预约状态:"] == "3")
			{
				status += "预约失败";
			}
			else if (o.m_OrderMap[i + 1]["预约状态:"] == "0")
			{
				status += "已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}
//查看所有预约
void Student::ShowAllOrder()
{
	system("cls");
	OrderFile o;
	//更新数据
	o.UpdateOrder();
	cout << "------------------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < o.m_Amount; i++)
	{
		string status = "状态：";
		cout << "机房:" << o.m_OrderMap[i + 1]["机房:"] << "   ";
		cout << "学号:" << o.m_OrderMap[i + 1]["学号:"] << "   ";
		cout << "姓名:" << o.m_OrderMap[i + 1]["姓名:"] << "   ";
		cout << "周" << o.m_OrderMap[i + 1]["日期:"] << "   ";
		cout << "时间：" << (o.m_OrderMap[i + 1]["时间:"] == "1" ? "上午" : "下午") << "   ";
		//0-取消预约  1-正在审核  2-预约成功  3-预约失败
		if (o.m_OrderMap[i + 1]["预约状态:"] == "1")
		{
			status += "正在审核";
		}
		else if (o.m_OrderMap[i + 1]["预约状态:"] == "2")
		{
			status += "预约成功";
		}
		else if (o.m_OrderMap[i + 1]["预约状态:"] == "3")
		{
			status += "预约失败";
		}
		else if (o.m_OrderMap[i + 1]["预约状态:"] == "0")
		{
			status += "已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
	return;
}
//取消预约
int index=1;
void Student::CancelOrder()
{
	system("cls");
	OrderFile o;
	vector<int>v;
	//通过容器找到本人预约
	for (int i = 0; i < o.m_Amount; i++)
	{
		if (o.m_OrderMap[i + 1]["学号:"] == this->m_Id)
		{
			//0-取消预约  1-正在审核  2-预约成功  3-预约失败
			if (o.m_OrderMap[i + 1]["预约状态:"] == "1" || o.m_OrderMap[i + 1]["预约状态:"] == "2")
			{
				string status = "状态：";
				v.push_back(i+1);//巧妙，不过变得复杂了
				//转换输出文件内容
				cout << index<<"、";
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
		
	}
	//取消预约
	int select;
	cout << "请输入想取消的预约编号（-1返回）" << endl;
	while (true)
	{
		cin >> select;
		if (select == -1)
		{
			system("cls");
			return;
		}
		else if (select > 0 && select <= v.size())
		{
			//select-1即是条数对应容器的编号，解得在文件中的真实位置条数---  |1->0|2->1....
			o.m_OrderMap[v[select - 1]]["预约状态:"] = "0";
			cout << "取消成功!" << endl;
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
void Student::InitVector()
{
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "文件打开失败!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//接收机房信息
	Computer c;
	while (ifs >> c.m_ComId && ifs >> c.m_Amount)
	{
		VCom.push_back(c);
	}
	//关闭文件
	ifs.close();
}