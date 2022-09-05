#ifndef SINGLEQUEUE_H
#define SINGLEQUEUE_H
#include"PersonNode.h"
#include"MixedQueue.h"
#include<iostream>
using namespace std;
class SingleQueue {
protected:
	//  链队列实现的数据成员:
	PersonNode* front, * rear;					//未检测排队的开始 最后
	PersonNode* head;                           //指向所有检测开头
public:
	int SingleNumber=0;
	int tag = 0;                                     //标志排队人为空
	SingleQueue();								  	// 无参数的构造函数
	virtual ~SingleQueue();						 	// 析构函数
	void Clear();									// 将队列清空
	void ShowQueue() ;	                            // 遍历队列
	void EnQueue(const int num);			         // 入队操作
	void SingleTest();                               //单人队伍测试
	void SetSingleStatus(const int TubeCode, int status, MixedQueue& m);  //传入测试管号和状态
	PersonNode* Find(const int testNumber);                //根据测试管号来进行找到
	PersonNode* FindPerson(int PersonCode);
	void SetContact(PersonNode* contactor, MixedQueue& m);                //根据确诊确定密接
	void SetBuildContact(int contactbuild);                //根据楼号来确定密接
	void SetBuildSecontact(int secontactbuild);             //根据密接楼号来确定次密接
	int  ShowStatus(int status);
	void showtest()
	{
		//PersonNode* p = head;
		for (PersonNode* p = head->next; p != NULL; p = p->next)
		{
			cout << "人员代码：" << p->personCode << endl;
			cout << "试管码：" << p->testNumber << endl;
			cout << "状态：" << p->status << endl;
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
				cout << "    该人员还没测试！" << endl;
				flag = 1;
			}
			else {
				cout << "    测试管码:  " << 1 << setw(4) << setfill('0') << p->testNumber << endl;
				flag = 1;
			}
		}
	}
	return flag;
}
void SingleQueue::SetSingleStatus(const int testNumber, int status, MixedQueue& m)  //设置检测状态
{
	PersonNode* p = Find(testNumber);                         //先查找
	if (p == NULL)
	{
		cout << "没有该编号，请重新输入！" << endl;
	}
	else {
		p->status = status;
		if (p->status == 1)
		{
			SetContact(p, m);
		}
	}
}
void SingleQueue::SetContact(PersonNode* contactor, MixedQueue& m)         //设置楼的密接
{
	int i = 0;
	
	PersonNode* q = contactor->pre;
	if (q != head) {
		while (i < 9 || q->pre != head)
		{
			cout << "设置了次密接" << endl;
			q->status = 3;                                      //前面十个设置为密接
			SetBuildSecontact(q->GetBuilding());                //前面十个的楼中人设置为次密接（单人队列）
			m.SetBuildSecontact(q->GetBuilding());              //前面十个的楼中人设置为次密接（混检队列）
			i++;
			q = q->pre;
		}
	}
	if (contactor->next != NULL)
	{

		contactor->next->status = 3;                            //后面一个人 的楼设置为次密接
		SetBuildSecontact(contactor->next->GetBuilding());
		m.SetBuildSecontact(q->GetBuilding());                  //混检队列 中的同楼人设置为次密接
	}
	int contactnum = contactor->GetBuilding();
	SetBuildContact(contactnum);
}
void SingleQueue::SetBuildContact(int contactbuild)             //确诊的同一栋楼设置为密接
{

	for (PersonNode* p = head;p->next != NULL;p = p->next)
	{
		if (p->GetBuilding() == contactbuild && p->status != 1)
		{
			p->status = 3;                             //同一栋楼不可能是次密接 这里所以不用
		}
	}
}
void SingleQueue::SetBuildSecontact(int secontactbuild)    //密接的同一栋楼设置为次密接
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
		front = front->next;                     //向后移一个结点
		front->pre = p;                          //关联前结点
	}
	else {
		tag = 0;                                   //将队伍标记为空
	}


}
SingleQueue::SingleQueue()
{
	 rear  =  head = new PersonNode(00000000,NULL);	// 生成链队列头结点
	 front =  head;
}
void SingleQueue::EnQueue(const int e)
{
	PersonNode* p;
	p = new PersonNode(e, NULL);	        // 生成一个新结点
	if (head->next==NULL)
	{
		front = p;
		rear = p;
		head->next = front;
		front->pre = head;
	}
	else  {
		rear->next = p;	                // 将新结点加在队尾
		p->pre = rear;
		rear = rear->next;				// rear指向新队尾
	}
	tag = 1;                           //有人入队，设置为非空
}
void SingleQueue::ShowQueue()  //查询排队的人 所以用front 不用head
{
	if (tag == 0)
		cout << "单管检测队伍为空！" << endl;
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
	while (p != NULL) {	// 依次删除队列中的元素结点
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

