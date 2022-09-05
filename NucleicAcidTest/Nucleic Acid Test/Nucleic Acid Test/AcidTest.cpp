#include<iostream>
#include <iomanip>
#include"SingleQueue.h"
#include<fstream>
using namespace std;
void SetStatus(const int TubeCode, int status, SingleQueue& s, MixedQueue& m);
void EnQueue(SingleQueue& s, MixedQueue& m);                  //ģ��һ���ŶӺ��� ��Ϊ��Ϻ͵���
void DoTest(SingleQueue& s, MixedQueue& m);                   //ģ�������⺯�� ��Ϊ��ϼ��͵��˼��
void ShowLine(SingleQueue& s, MixedQueue& m);                 //ģ�������ֱ�չʾ �Ŷ�
void LoginStatus(SingleQueue& s, MixedQueue& m);              //ģ���ġ��Ǽǽ��
void SearchStatus(SingleQueue& s, MixedQueue& m);             //ģ���塢���ݸ�����Ա��ѯ
void SearchPerson(SingleQueue& s, MixedQueue& m);             //ģ��������ѯ�������
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
		cout << "********��ӭ����Lin������ϵͳ����ѡ���ܣ�*******" << endl;
		cout << "***************(a)�ļ���ȡ��Ӳ����****************" << endl;
		cout << "***************(b)�ֶ������ŶӲ���****************** " << endl;
		cout << "***************(c)�鿴���Ŷ����********************" << endl;
		cout << "***************(d)�Ǽǲ�����Ϣ********************** " << endl;
		cout << "***************(e)������Ա��ѯ********************** " << endl;
		cout << "***************(f)���˲�ѯ************************** " << endl;
		cout << "***************(g)�ֶ�ѡ�������ԣ�ʮ�˻��ˣ�**** " << endl;
		cout << "***************(p)�˳�ϵͳ************************** " << endl;
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
			cout << "������󣡣����������룡" << endl;
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
	cout << "����Ŷӳɹ����Զ��Ŷ�" << mixednum <<"��" << endl;
	while (k < singlenum)
	{
		int code;
		in1 >> code;
		s.EnQueue(code);
		k++;
	}
	cout << "�����Ŷӳɹ����Զ��Ŷ�" << singlenum << "��" << endl;
	int i = 0;
	int a;
	in2 >> a;
	while (i < a)
	{
		m.MixedTest();
		i++;
	}
	cout << "�Զ�ʮ�˻�ϼ��ɹ������" <<a<<"��" << endl;
	i = 0;
	in2 >> a;
	while (i < a)
	{
		s.SingleTest();
		i++;
	}
	cout << "�Զ����ܼ��ɹ������"<< a<<"��" << endl;


}
void LoginStatus(SingleQueue& s, MixedQueue& m)
{
	int i = 0;
	int n;
	int TubeCode;
	int status;
	cout << "������Ҫ�Ǽǵ�������" << endl;
	cin >> n;
	cout << "������Թܵı�ţ��������0��ʾ���ԣ�1��ʾȷ�3��ʾ���ɣ�" << endl;
	cin >> TubeCode >> status;
	while (i < n)
	{
		SetStatus(TubeCode,status,s,m);
		i++;
	}
}
void ShowLine(SingleQueue& s, MixedQueue& m) 
{
	cout << "��ϼ������Ŷ������" << endl;
	m.ShowQueue();
	cout << "���ܼ������Ŷ������" << endl;
	s.ShowQueue();
}
void DoTest(SingleQueue& s, MixedQueue& m) {

	char option;
	int a;
	int i;
	cout << "========��ѡ����Է�ʽ��=========" << endl;
	cout << "=====��a��ʮ��һ���ϼ��=======" << endl;
	cout << "=====��b�����˵��ܸ��˼��=======" << endl;
	cin >> option;
	switch (option)
	{
	case'a':
		i = 0;
		cout << "�������ϼ�����:" << endl;
		cin >> a;
		while (i < a)
		{
			m.MixedTest();
			i++;
		}
		break;
	case 'b':
		i = 0;
		cout << "��������˼������:" << endl;;
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
	cout << "�������ϼ���Ŷӵ�������" << endl;
	cin >> mixednum;
	cout << "�����뵥�ܼ���Ŷӵ�������" << endl;
	cin >> singlenum;
	cout << "�������ϼ���Ŷӵ���Ա��ţ�" << endl;
	while (n < mixednum)
	{
		int code;
		cin >> code;
		m.EnQueue(code);
		n++;
	}
	cout << "��ϲ����Ŷӳɹ���" << endl;
	cout << "�����뵥�ܼ���Ŷӵ���Ա��ţ�" << endl;
	while (k < singlenum)
	{
		int code;
		cin >> code;
		s.EnQueue(code);
		k++;
	}
	cout << "���˲����Ŷӳɹ���" << endl;
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
void SearchStatus(SingleQueue& s, MixedQueue& m)   //����״̬��ѯ��Ա״̬
{
	int status;
	cout << "ѡ��Ҫ��ѯ��״̬��0��ʾ���ԣ�1:ȷ��,2:����,3:�ܽ�,4:���ܽ�,5:�ȴ����,6:���Ŷ�,7:δ��⣩��" << endl;
	cin >> status;
	cout << GetStatus(status) << "����Ա�У�" << endl;
	int a =s.ShowStatus(status);
	int b =m.ShowStatus(status);
	if (a == 0&&b==0)
	{
		cout << "Ŀǰû�и�״̬����!" << endl;
	}
}
void SearchPerson(SingleQueue& s, MixedQueue& m)//��ѯ���˼��״̬
{
	int personcode;
	cout << "�������ѯ�ı�ţ�" << endl;
	cin >> personcode;
	PersonNode*p=s.FindPerson(personcode);
	if (p == NULL)
	{
		p = m.FindPerson(personcode);
	}
	if (p == NULL)
	{
		cout << "����Աδ�Ŷ�" << endl;
	}
	else {
		string a = p->GetStatus();
		cout << "����Ա��״̬Ϊ��" << a<<endl;
	}
}
