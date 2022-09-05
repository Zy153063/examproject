#ifndef SINGLEQUEUE_H
#define SINGLEQUEUE_H
#include"PersonNode.h"
#include"MixedQueue.h"
#include<iostream>
using namespace std;
class SingleQueue {
protected:
	//  ������ʵ�ֵ����ݳ�Ա:
	PersonNode* front, * rear;					//δ����ŶӵĿ�ʼ ���
	PersonNode* head;                           //ָ�����м�⿪ͷ
public:
	int SingleNumber=0;
	int tag = 0;                                     //��־�Ŷ���Ϊ��
	SingleQueue();								  	// �޲����Ĺ��캯��
	virtual ~SingleQueue();						 	// ��������
	void Clear();									// ���������
	void ShowQueue() ;	                            // ��������
	void EnQueue(const int num);			         // ��Ӳ���
	void SingleTest();                               //���˶������
	void SetSingleStatus(const int TubeCode, int status, MixedQueue& m);  //������Թܺź�״̬
	PersonNode* Find(const int testNumber);                //���ݲ��Թܺ��������ҵ�
	PersonNode* FindPerson(int PersonCode);
	void SetContact(PersonNode* contactor, MixedQueue& m);                //����ȷ��ȷ���ܽ�
	void SetBuildContact(int contactbuild);                //����¥����ȷ���ܽ�
	void SetBuildSecontact(int secontactbuild);             //�����ܽ�¥����ȷ�����ܽ�
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

PersonNode* SingleQueue::FindPerson(int PersonCode)
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
int SingleQueue::ShowStatus(int status)
{
	int flag = 0;
	for (PersonNode* p = head->next; p != NULL; p = p->next)
	{
		if (p->status == status)
		{
			cout << setw(8) << setfill('0') << p->personCode;
			if (p->testNumber == -1) {
				cout << "    ����Ա��û���ԣ�" << endl;
				flag = 1;
			}
			else {
				cout << "    ���Թ���:  " << 1 << setw(4) << setfill('0') << p->testNumber << endl;
				flag = 1;
			}
		}
	}
	return flag;
}
void SingleQueue::SetSingleStatus(const int testNumber, int status, MixedQueue& m)  //���ü��״̬
{
	PersonNode* p = Find(testNumber);                         //�Ȳ���
	if (p == NULL)
	{
		cout << "û�иñ�ţ����������룡" << endl;
	}
	else {
		p->status = status;
		if (p->status == 1)
		{
			SetContact(p, m);
		}
	}
}
void SingleQueue::SetContact(PersonNode* contactor, MixedQueue& m)         //����¥���ܽ�
{
	int i = 0;
	
	PersonNode* q = contactor->pre;
	if (q != head) {
		while (i < 9 || q->pre != head)
		{
			cout << "�����˴��ܽ�" << endl;
			q->status = 3;                                      //ǰ��ʮ������Ϊ�ܽ�
			SetBuildSecontact(q->GetBuilding());                //ǰ��ʮ����¥��������Ϊ���ܽӣ����˶��У�
			m.SetBuildSecontact(q->GetBuilding());              //ǰ��ʮ����¥��������Ϊ���ܽӣ������У�
			i++;
			q = q->pre;
		}
	}
	if (contactor->next != NULL)
	{

		contactor->next->status = 3;                            //����һ���� ��¥����Ϊ���ܽ�
		SetBuildSecontact(contactor->next->GetBuilding());
		m.SetBuildSecontact(q->GetBuilding());                  //������ �е�ͬ¥������Ϊ���ܽ�
	}
	int contactnum = contactor->GetBuilding();
	SetBuildContact(contactnum);
}
void SingleQueue::SetBuildContact(int contactbuild)             //ȷ���ͬһ��¥����Ϊ�ܽ�
{

	for (PersonNode* p = head;p->next != NULL;p = p->next)
	{
		if (p->GetBuilding() == contactbuild && p->status != 1)
		{
			p->status = 3;                             //ͬһ��¥�������Ǵ��ܽ� �������Բ���
		}
	}
}
void SingleQueue::SetBuildSecontact(int secontactbuild)    //�ܽӵ�ͬһ��¥����Ϊ���ܽ�
{
	for (PersonNode* p = head;p!= NULL;p = p->next)
	{
		if (p->GetBuilding() == secontactbuild && p->status != 1&&p->status!=3)
		{
			p->status = 4;
		}
	}
}
PersonNode* SingleQueue::Find(const int testNumber)
{
	 for (PersonNode* p = head;p != NULL;p = p->next)
	 {
		 if (p->testNumber == testNumber)
		 {
			 return p;
		 }
	 }
	return NULL ;
}


void SingleQueue::SingleQueue::SingleTest()        
{

PersonNode* p = front;
	front->testNumber = SingleNumber;
	front->status = WAIT;
	SingleNumber++;
	if (front->next != NULL)
	{
		front = front->next;                     //�����һ�����
		front->pre = p;                          //����ǰ���
	}
	else {
		tag = 0;                                   //��������Ϊ��
	}


}
SingleQueue::SingleQueue()
{
	 rear  =  head = new PersonNode(00000000,NULL);	// ����������ͷ���
	 front =  head;
}
void SingleQueue::EnQueue(const int e)
{
	PersonNode* p;
	p = new PersonNode(e, NULL);	        // ����һ���½��
	if (head->next==NULL)
	{
		front = p;
		rear = p;
		head->next = front;
		front->pre = head;
	}
	else  {
		rear->next = p;	                // ���½����ڶ�β
		p->pre = rear;
		rear = rear->next;				// rearָ���¶�β
	}
	tag = 1;                           //������ӣ�����Ϊ�ǿ�
}
void SingleQueue::ShowQueue()  //��ѯ�Ŷӵ��� ������front ����head
{
	if (tag == 0)
		cout << "���ܼ�����Ϊ�գ�" << endl;
	else {
		for (PersonNode* p = front; p != NULL; p = p->next)
		{
			cout << setw(8) << setfill('0') << p->personCode << endl;
		}
	}
}


void SingleQueue::Clear()
{
	PersonNode* p = head->next;
	while (p != NULL) {	// ����ɾ�������е�Ԫ�ؽ��
		head->next = p->next;
		delete p;
		p = head->next;
	}
	rear = head;
}
SingleQueue::~SingleQueue()
{
	Clear();
	delete head;
}


#endif // !SINGLEQUEUE_H

