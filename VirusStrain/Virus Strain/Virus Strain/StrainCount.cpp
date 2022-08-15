#include<iostream>
#include<fstream>
#include"LinkH.h"
#include"LinkS.h"
#include <string>
#define MAXSIZE 10000            //设置病毒种类最大值
using namespace std;
void test01();
void test(string input,string output);
int main()
{
	char c;
	cout << "==================================================" << endl;
	cout << "============欢迎来到病毒株种类分类系统============" << endl;
	cout << "==================请选择测试数据==================" << endl;
	cout << "============(a) 案例测试输出======================" << endl;
	cout << "============(b) 多个数据测试======================" << endl;
	cout << "============(c) 特殊情况之SSSS测试输出============" << endl;
	cout << "============(d) 特殊情况之HHHH测试输出============" << endl;
	cout << "============(e) 特殊情况之错误输入测试输出========" << endl;
	cout << "============(f) 手动输入方式 进行测试=============" << endl;
	cout << "==================================================" << endl;
	cin >> c;
	switch (c)
	{
	case 'a':
			test("virus1.in", "virus1.out");
			break;
	case 'b':
		  test("virus5.in", "virus5.out");
		  break;
	case 'c':
		test("virus2.in", "virus2.out");
		break;
	case 'd':
		test("virus3.in", "virus3.out");
		break;
	case 'e':
		test("virus4.in", "virus4.out");
		break;
	case 'f':
		test01();
		break;
	default:
		cout << "没有该功能，请正确输入选择！ " << endl;
		break;
	}
}
void InsertSVirus(int &k, int num1, int num2, LinkS *s)  //一般情况 插入两个S的函数
{
	int findone = -1;                                      
	int findtwo = -1;
	if (k == 0)                                    //若S 链表为空 直接在头节点下追加
	{
		s[k].append(num1, num2);
		k++;

	} 
	else {                                         //否则遍历每条链寻找，并添加
		for (int i = 0;i < k;i++)
		{
			bool find1 = s[i].FindVirus(num1);
			bool find2 = s[i].FindVirus(num2);
			if (find1)
			{
				s[i].append(num2);
				findone = i;
			}
			else if (find2)
			{
				s[i].append(num2);
				findtwo = i;
			}
		}
		if (findone == -1&&findtwo==-1)             //都没有找到考虑特殊情况
		{
			s[k].append(num1, num2);
            k++;
		}
		else if (findone != -1&&findtwo!=-1)            //最复杂情况，链可能会减少，链合并 数组位移
		{
			int min = findone < findtwo ? findone : findtwo;
			int max = findone > findtwo ? findone : findtwo;
			s[min].mergeLink(s[max].head->next);
			for (int i = max;i < k;i++)
			{
				s[i] = s[i + 1];
			}
			k--;
		}
	}
}
void InsertNode(int& k,int e, LinkS* s)        //考虑特殊情况  插入一个 
{
	int findflag = 0;
	if (k == 0)
	{
		s[k].append(e);
		k++;
	}
	else {
		for (int i = 0;i < k;i++)
		{
			bool find = s[i].FindVirus(e);
			if (find)
			{
				findflag = 1;
			}
		}
		if (findflag == 0)
		{
			s[k].append(e);
             k++;
		}
	}
}
void test01()                                 //手动输入测试
{
	int num;
	int infrom=4;               
	int n = 0;               
	char kind;               //病毒种类
	int num1, num2;
	int k = 0;
	LinkS s[MAXSIZE];
	LinkH h;
	h.head ;
	cout << "请输入病毒的种类数:" << endl;
	//in >> num;
	cin >> num;
	cout << "请输入病毒的信息条数："<<endl;
	//in >> infrom;
	cin >> infrom;
	while (n < infrom)
	{
		cout << "请输入第"<<n+1<<"条病毒的信息条数：" << endl;
		//in >> kind >> num1 >> num2;
		cin >> kind >> num1 >> num2;
		if (kind == 'S')                        //判断为 S 输入的操作 
		{
			InsertSVirus(k, num1, num2, s);   
		}
		else if (kind == 'H')                   // 判断为 H 输入的操作
		{
			if (h.head->next ==NULL)            //h链为空 直接追加 并添加
			{
				h.append(num1, num2);
				InsertNode(k,num1,s);
				InsertNode(k,num2,s);
			}
			else {
				int num11 = num1;
				int num22 = num2;
				bool findh = h.FindHVirus(num1, num2); //不为空 现在H链中寻找，然后引用传递更换num1,num2 在利用S 插入
				if (findh)
				{
					
					InsertSVirus(k,num1, num2,s);
				}
				else {
					h.append(num1, num2);
					InsertNode(k, num1, s);
					InsertNode(k, num2, s);
				}
			}
		}
		else {
			cout << "错误输入，请重新输入" << endl;
			break;
		}
		n++;  
		cout <<"当前病毒株树："<< k << endl;
	}
	
cout << "最终病毒的植树为：" <<k<< endl;
//out<< "病毒的植树为：" << k << endl;
}
void test(string input,string output)
{
	ifstream in(input);               //关联流函数
	ofstream out(output);
	int num;
	int infrom = 4;
	int n = 0;
	char kind;               //病毒种类
	int num1, num2;
	int k = 0;
	LinkS s[MAXSIZE];
	LinkH h;
	cout << "请输入病毒的种类数:" << endl;
	in >> num;
	//cin >> num;
	cout << "请输入病毒的信息条数：" << endl;
	in >> infrom;
	//cin >> infrom;
	while (n < infrom)
	{
		cout << "请输入第" << n + 1 << "条病毒的信息条数：" << endl;
		in >> kind >> num1 >> num2;
		//cin >> kind >> num1 >> num2;
		if (kind == 'S')                        //判断为 S 输入的操作 
		{
			InsertSVirus(k, num1, num2, s);
		}
		else if (kind == 'H')                   // 判断为 H 输入的操作
		{
			if (h.head->next == NULL)            //h链为空 直接追加 并添加
			{
				h.append(num1, num2);
				InsertNode(k, num1, s);
				InsertNode(k, num2, s);
			}
			else {
				bool findh = h.FindHVirus(num1, num2); //不为空 现在H链中寻找，然后引用传递更换num1,num2 在利用S 插入
				if (findh)
				{

					InsertSVirus(k, num1, num2, s);
				}
				else {
					h.append(num1, num2);
					InsertNode(k, num1, s);
					InsertNode(k, num2, s);
				}
			}
		}
		else {
			cout << "错误输入，请重新输入" << endl;
			out << "错误输入，请重新输入" << endl;
			in.close();
			out.close();
			break;
		}
		n++;
	}
	in.close();
	cout << "病毒的植树为：" << k << endl;
	out<< "病毒的植树为：" << k << endl;
	out.close();
}
 