#include<iostream>
#include <iomanip>
#include"SingleQueue.h"
#include<fstream>
using namespace std;
void SetStatus(const int TubeCode, int status, SingleQueue& s, MixedQueue& m);
void EnQueue(SingleQueue& s, MixedQueue& m);                  //模块一、排队函数 分为混合和单人
void DoTest(SingleQueue& s, MixedQueue& m);                   //模块二、检测函数 分为混合检测和单人检测
void ShowLine(SingleQueue& s, MixedQueue& m);                 //模块三、分别展示 排队
void LoginStatus(SingleQueue& s, MixedQueue& m);              //模块四、登记结果
void SearchStatus(SingleQueue& s, MixedQueue& m);             //模块五、根据各类人员查询
void SearchPerson(SingleQueue& s, MixedQueue& m);             //模块六、查询个人情况
void TestFile(SingleQueue& s, MixedQueue& m);
int main()
{
	SingleQueue s;
	MixedQueue m;
	char c;
	int flag = 1;

	while (flag)
	{
		cout << "****************************************************" << endl;
		cout << "********欢迎来到Lin核酸检测系统，请选择功能：*******" << endl;
		cout << "***************(a)文件读取入队并检测****************" << endl;
		cout << "***************(b)手动进行排队测试****************** " << endl;
		cout << "***************(c)查看在排队情况********************" << endl;
		cout << "***************(d)登记测试信息********************** " << endl;
		cout << "***************(e)各类人员查询********************** " << endl;
		cout << "***************(f)个人查询************************** " << endl;
		cout << "***************(g)手动选择核酸测试（十人或单人）**** " << endl;
		cout << "***************(p)退出系统************************** " << endl;
		cout << "**************************************************** " << endl;
		cin >> c;
		switch (c)
		{
		case 'a':
			TestFile(s, m);
			break;
		case 'b':
			EnQueue(s, m);
			break;
		case 'c':
			ShowLine(s, m);
			break;
		case 'd':
			LoginStatus(s, m);
			break;
		case 'e':
			SearchStatus(s, m);
			break;
		case 'f':
			SearchPerson(s, m);
			break;
		case 'g':
			DoTest(s, m);
			break;
		case 'p':
			flag = 0;
			break;
		default:
			cout << "输入错误！，请重新输入！" << endl;
			break;
		}
	}
	
}
void TestFile(SingleQueue& s, MixedQueue& m)
{
	ifstream in1("line_up.in");
	ifstream in2("nucleic_acid_test.in");
	int singlenum;
	int k = 0;
	int mixednum;
	int n = 0;
	in1 >> mixednum;
	in1 >> singlenum;
	while (n < mixednum)
	{
		int code;
		in1>> code;
		m.EnQueue(code);
		n++;
	}
	cout << "混合排队成功！自动排队" << mixednum <<"人" << endl;
	while (k < singlenum)
	{
		int code;
		in1 >> code;
		s.EnQueue(code);
		k++;
	}
	cout << "单管排队成功！自动排队" << singlenum << "人" << endl;
	int i = 0;
	int a;
	in2 >> a;
	while (i < a)
	{
		m.MixedTest();
		i++;
	}
	cout << "自动十人混合检测成功！检测" <<a<<"次" << endl;
	i = 0;
	in2 >> a;
	while (i < a)
	{
		s.SingleTest();
		i++;
	}
	cout << "自动单管检测成功！检测"<< a<<"人" << endl;


}
void LoginStatus(SingleQueue& s, MixedQueue& m)
{
	int i = 0;
	int n;
	int TubeCode;
	int status;
	cout << "请输入要登记的数量：" << endl;
	cin >> n;
	cout << "输入测试管的编号：及结果（0表示阴性，1表示确诊，3表示可疑）" << endl;
	cin >> TubeCode >> status;
	while (i < n)
	{
		SetStatus(TubeCode,status,s,m);
		i++;
	}
}
void ShowLine(SingleQueue& s, MixedQueue& m) 
{
	cout << "混合检测队伍排队情况：" << endl;
	m.ShowQueue();
	cout << "单管检测队伍排队情况：" << endl;
	s.ShowQueue();
}
void DoTest(SingleQueue& s, MixedQueue& m) {

	char option;
	int a;
	int i;
	cout << "========请选择测试方式：=========" << endl;
	cout << "=====（a）十人一组混合检测=======" << endl;
	cout << "=====（b）单人单管个人检测=======" << endl;
	cin >> option;
	switch (option)
	{
	case'a':
		i = 0;
		cout << "请输入混合检测次数:" << endl;
		cin >> a;
		while (i < a)
		{
			m.MixedTest();
			i++;
		}
		break;
	case 'b':
		i = 0;
		cout << "请输入个人检测人数:" << endl;;
		cin >> a;
		while (i < a)
		{
			s.SingleTest();
			i++;
		}
		break;
	default:
		break;
	}

}
void EnQueue(SingleQueue& s, MixedQueue& m) {
	int singlenum;
	int k=0;  
	int mixednum;
	int n=0;
	cout << "请输入混合检测排队的人数：" << endl;
	cin >> mixednum;
	cout << "请输入单管检测排队的人数：" << endl;
	cin >> singlenum;
	cout << "请输入混合检测排队的人员编号：" << endl;
	while (n < mixednum)
	{
		int code;
		cin >> code;
		m.EnQueue(code);
		n++;
	}
	cout << "混合测试排队成功！" << endl;
	cout << "请输入单管检测排队的人员编号：" << endl;
	while (k < singlenum)
	{
		int code;
		cin >> code;
		s.EnQueue(code);
		k++;
	}
	cout << "单人测试排队成功！" << endl;
}
void SetStatus(const int TubeCode, int status,SingleQueue &s,MixedQueue &m) 
{
	int kind = TubeCode / 10000;
	if (kind == 1)
	{
		int tubecode = TubeCode % 10000;
		s.SetSingleStatus(tubecode,  status,  m);
	}
	else {
		m.SetMixedStatus(TubeCode,status);
	}
}
void SearchStatus(SingleQueue& s, MixedQueue& m)   //根据状态查询人员状态
{
	int status;
	cout << "选择要查询的状态（0表示阴性，1:确诊,2:可疑,3:密接,4:次密接,5:等待结果,6:在排队,7:未检测）：" << endl;
	cin >> status;
	cout << GetStatus(status) << "的人员有：" << endl;
	int a =s.ShowStatus(status);
	int b =m.ShowStatus(status);
	if (a == 0&&b==0)
	{
		cout << "目前没有该状态的人!" << endl;
	}
}
void SearchPerson(SingleQueue& s, MixedQueue& m)//查询个人检测状态
{
	int personcode;
	cout << "请输入查询的编号：" << endl;
	cin >> personcode;
	PersonNode*p=s.FindPerson(personcode);
	if (p == NULL)
	{
		p = m.FindPerson(personcode);
	}
	if (p == NULL)
	{
		cout << "该人员未排队" << endl;
	}
	else {
		string a = p->GetStatus();
		cout << "该人员的状态为：" << a<<endl;
	}
}
