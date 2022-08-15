#include<iostream>
#include<fstream>
#include"LinkH.h"
#include"LinkS.h"
#include <string>
#define MAXSIZE 10000            //���ò����������ֵ
using namespace std;
void test01();
void test(string input,string output);
int main()
{
	char c;
	cout << "==================================================" << endl;
	cout << "============��ӭ�����������������ϵͳ============" << endl;
	cout << "==================��ѡ���������==================" << endl;
	cout << "============(a) �����������======================" << endl;
	cout << "============(b) ������ݲ���======================" << endl;
	cout << "============(c) �������֮SSSS�������============" << endl;
	cout << "============(d) �������֮HHHH�������============" << endl;
	cout << "============(e) �������֮��������������========" << endl;
	cout << "============(f) �ֶ����뷽ʽ ���в���=============" << endl;
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
		cout << "û�иù��ܣ�����ȷ����ѡ�� " << endl;
		break;
	}
}
void InsertSVirus(int &k, int num1, int num2, LinkS *s)  //һ����� ��������S�ĺ���
{
	int findone = -1;                                      
	int findtwo = -1;
	if (k == 0)                                    //��S ����Ϊ�� ֱ����ͷ�ڵ���׷��
	{
		s[k].append(num1, num2);
		k++;

	} 
	else {                                         //�������ÿ����Ѱ�ң������
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
		if (findone == -1&&findtwo==-1)             //��û���ҵ������������
		{
			s[k].append(num1, num2);
            k++;
		}
		else if (findone != -1&&findtwo!=-1)            //�������������ܻ���٣����ϲ� ����λ��
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
void InsertNode(int& k,int e, LinkS* s)        //�����������  ����һ�� 
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
void test01()                                 //�ֶ��������
{
	int num;
	int infrom=4;               
	int n = 0;               
	char kind;               //��������
	int num1, num2;
	int k = 0;
	LinkS s[MAXSIZE];
	LinkH h;
	h.head ;
	cout << "�����벡����������:" << endl;
	//in >> num;
	cin >> num;
	cout << "�����벡������Ϣ������"<<endl;
	//in >> infrom;
	cin >> infrom;
	while (n < infrom)
	{
		cout << "�������"<<n+1<<"����������Ϣ������" << endl;
		//in >> kind >> num1 >> num2;
		cin >> kind >> num1 >> num2;
		if (kind == 'S')                        //�ж�Ϊ S ����Ĳ��� 
		{
			InsertSVirus(k, num1, num2, s);   
		}
		else if (kind == 'H')                   // �ж�Ϊ H ����Ĳ���
		{
			if (h.head->next ==NULL)            //h��Ϊ�� ֱ��׷�� �����
			{
				h.append(num1, num2);
				InsertNode(k,num1,s);
				InsertNode(k,num2,s);
			}
			else {
				int num11 = num1;
				int num22 = num2;
				bool findh = h.FindHVirus(num1, num2); //��Ϊ�� ����H����Ѱ�ң�Ȼ�����ô��ݸ���num1,num2 ������S ����
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
			cout << "�������룬����������" << endl;
			break;
		}
		n++;  
		cout <<"��ǰ����������"<< k << endl;
	}
	
cout << "���ղ�����ֲ��Ϊ��" <<k<< endl;
//out<< "������ֲ��Ϊ��" << k << endl;
}
void test(string input,string output)
{
	ifstream in(input);               //����������
	ofstream out(output);
	int num;
	int infrom = 4;
	int n = 0;
	char kind;               //��������
	int num1, num2;
	int k = 0;
	LinkS s[MAXSIZE];
	LinkH h;
	cout << "�����벡����������:" << endl;
	in >> num;
	//cin >> num;
	cout << "�����벡������Ϣ������" << endl;
	in >> infrom;
	//cin >> infrom;
	while (n < infrom)
	{
		cout << "�������" << n + 1 << "����������Ϣ������" << endl;
		in >> kind >> num1 >> num2;
		//cin >> kind >> num1 >> num2;
		if (kind == 'S')                        //�ж�Ϊ S ����Ĳ��� 
		{
			InsertSVirus(k, num1, num2, s);
		}
		else if (kind == 'H')                   // �ж�Ϊ H ����Ĳ���
		{
			if (h.head->next == NULL)            //h��Ϊ�� ֱ��׷�� �����
			{
				h.append(num1, num2);
				InsertNode(k, num1, s);
				InsertNode(k, num2, s);
			}
			else {
				bool findh = h.FindHVirus(num1, num2); //��Ϊ�� ����H����Ѱ�ң�Ȼ�����ô��ݸ���num1,num2 ������S ����
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
			cout << "�������룬����������" << endl;
			out << "�������룬����������" << endl;
			in.close();
			out.close();
			break;
		}
		n++;
	}
	in.close();
	cout << "������ֲ��Ϊ��" << k << endl;
	out<< "������ֲ��Ϊ��" << k << endl;
	out.close();
}
 