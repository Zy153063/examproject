#ifndef MIXEDQUEUE_H
#define MINEDQUEUE_H
#include"PersonNode.h"
#include<iostream>
#define MAXSIZE 1000
using namespace std;
class MixedQueue {
protected:
	//  ������ʵ�ֵ����ݳ�Ա:
	PersonNode* front, * rear;				     	// δ����ŶӵĿ�ʼ ����β
	PersonNode* head;                               // ָ�����м�⿪ͷ
public:
	int k;
	int tag = 0;                                     //��־�Ŷ���Ϊ��
	int MixedNumber=0;
	MixedQueue();									// �޲����Ĺ��캯��
	virtual ~MixedQueue();							// ��������
	PersonNode* Find(int TubeCode);                 //���ݴ���������в��ҽ�� 
	PersonNode* FindPerson(int PersonCode);         //���ø��˴���������
	void Clear();									// ���������
	void ShowQueue();	                            // ��������  ���
	void EnQueue(const int e);			            // ��Ӳ���
	void MixedTest();                               // ��ϲ���
	void SetMixedStatus(int TubeCode, int status);  // ����ܺż�������
	void SetBuildContact(int contactbuild);         // �ܽ� �������ݴ���¥�� ����¥������Ϊ�ܽ�
	void SetBuildSecontact(int secontactbuild);       // ���ܽӺ��� ���ݴ���¥�� ����¥������Ϊ���ܽ�
	int  ShowStatus(int status);
	void showtest()
	{
		//PersonNode* p = head;
		for (PersonNode* p = head->next; p != NULL; p = p->next)
		{
			cout << "��Ա���룺" << p->personCode << endl;
			cout << "�Թ��룺" << p->testNumber << endl;
			cout << "״̬��" << p->status << endl;
		}
	}
};
PersonNode* MixedQueue::FindPerson(int PersonCode)
{
	for (PersonNode* p = head;p != NULL;p = p->next)
	{
		if (p->personCode == PersonCode)
		{
			return p;
		}
	}
	return NULL;
}
 int  MixedQueue::ShowStatus(int status)
{
	 int flag = 0;
	 for (PersonNode* p = head->next; p != NULL; p = p->next)
	 {
		 if (p->status == status)
		 {
			 cout << setw(8) << setfill('0') << p->personCode;
			 if (p->testNumber == -1) {
				 cout << "    ����Ա��û���ԣ�" << endl;
				 flag = 0;
			 }
			 else {
				 cout << "    ���Թ���:  " << 0 << setw(4) << setfill('0') << p->testNumber << endl;
				 flag = 0;
			 }
		 }
	 }
	 return flag;
}
void MixedQueue::SetBuildSecontact(int secontactbuild)   
{
	for (PersonNode* p = head;p != NULL;p = p->next)
	{
		if (p->GetBuilding() == secontactbuild && p->status != 1 && p->status != 3) //���ȼ��ж�
		{
			p->status = 4;                           //����Ϊ���ܽ�
		}
	}
}

void MixedQueue::SetMixedStatus(int TubeCode, int status)  //ʮ�˲��Թܲ���
{
	for (PersonNode* p = head;p != NULL;p = p->next)
	{
		if (p->testNumber == TubeCode&&p->status!=1)     //���ȼ�С��ȷ��  ȷ��>����>�ܽ�>���ܽ�
		{
			p->status = 2;
		}
	}
}
void MixedQueue::SetBuildContact(int contactbuild)        //ȷ���ͬһ��¥����Ϊ�ܽ�
{

	for (PersonNode* p = head;p->next != NULL;p = p->next)
	{
		if (p->GetBuilding() == contactbuild && p->status != 1)
		{
			p->status = 3;                             //ͬһ��¥�������Ǵ��ܽ� �������Բ���
		}
	}
}
PersonNode* MixedQueue::Find(int TubeCode)
{
	for (PersonNode* p = head;p != NULL;p = p->next) //��ͷ��ʼ���� ��Ϊhead
	{
		if (p->testNumber == TubeCode)              //��ΪFindPerson ��Ϊp->personCode == personcode�ж�
		{
			return p;
		}
	}
	return NULL;
}

void MixedQueue::MixedTest()                        //��ϲ���
{
	PersonNode* p = front;
	int i = 0;
	while (i < 10)
	{
		front->testNumber = MixedNumber;         //��Ա���� ������и�ֵ
		front->status = WAIT;                    //��Ա״̬���� ���ڵȴ�
		if (front->next != NULL)
		{
			front = front->next;                     //�����һ�����
			front->pre = p;                          //����ǰ���
		}
		else {                                      //����ʮ��ʱ
			tag = 0;                                 //���б��Ϊ��
			if (i != 9)
			{
				cout << "���ֻʣ" << i + 1 << "����ʮ����";  //����˴μ������
				break;
			}
		}
		i++;
	}
	MixedNumber++;                          //���������
}
MixedQueue::MixedQueue()                    
{
	head = rear = new PersonNode(00000000, NULL);	// ����������ͷ���
	front=head->next;
}
void MixedQueue::EnQueue(const int e)      // ��ϼ����Ӻ���
{
	PersonNode* p;
	p = new PersonNode(e, NULL);	         // ����һ���½��
	if (front == NULL)
	{
		front = p;
		rear = p;
		head->next = front;
		front->pre = head;
	}
	else if (p) {
		rear->next = p;	                 // ���½����ڶ�β
		p->pre = rear;
		rear = rear->next;				 // rearָ���¶�β
	}
	tag = 1;                            //������״̬����Ϊ�ǿ�
}
void MixedQueue::ShowQueue()            //չʾ����Ŷӵ��� ������front ����head
{

	if (tag == 0)                             //�ж϶����Ƿ�Ϊ��
		cout << "������Ϊ��" << endl;
	else {
		for (PersonNode* p = front; p != NULL; p = p->next)
		{
			cout <<setw(8)<<setfill('0') << p->personCode << endl;
		}
	}
}

MixedQueue::~MixedQueue()
{
	Clear();
	delete head;
}

void MixedQueue::Clear()
{
	PersonNode* p = head->next;
	while (p != NULL) {	                 //����ɾ�������е�Ԫ�ؽ��
		head->next = p->next;
		delete p;
		p = head->next;
	}
	rear = head;
}



#endif // !MIXEDQUEUE_H

