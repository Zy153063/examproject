#ifndef MIXEDQUEUE_H
#define MINEDQUEUE_H
#include"PersonNode.h"
#include<iostream>
#define MAXSIZE 1000
using namespace std;
class MixedQueue {
protected:
	//  链队列实现的数据成员:
	PersonNode* front, * rear;				     	// 未检测排队的开始 及结尾
	PersonNode* head;                               // 指向所有检测开头
public:
	int k;
	int tag = 0;                                     //标志排队人为空
	int MixedNumber=0;
	MixedQueue();									// 无参数的构造函数
	virtual ~MixedQueue();							// 析构函数
	PersonNode* Find(int TubeCode);                 //根据传入管来进行查找结点 
	PersonNode* FindPerson(int PersonCode);         //利用个人代码来查找
	void Clear();									// 将队列清空
	void ShowQueue();	                            // 遍历队列  输出
	void EnQueue(const int e);			            // 入队操作
	void MixedTest();                               // 混合测试
	void SetMixedStatus(int TubeCode, int status);  // 传入管号加载数据
	void SetBuildContact(int contactbuild);         // 密接 函数根据传入楼号 将该楼人设置为密接
	void SetBuildSecontact(int secontactbuild);       // 次密接函数 根据传入楼号 将该楼人设置为次密接
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
				 cout << "    该人员还没测试！" << endl;
				 flag = 0;
			 }
			 else {
				 cout << "    测试管码:  " << 0 << setw(4) << setfill('0') << p->testNumber << endl;
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
		if (p->GetBuilding() == secontactbuild && p->status != 1 && p->status != 3) //优先级判断
		{
			p->status = 4;                           //设置为次密接
		}
	}
}

void MixedQueue::SetMixedStatus(int TubeCode, int status)  //十人测试管测试
{
	for (PersonNode* p = head;p != NULL;p = p->next)
	{
		if (p->testNumber == TubeCode&&p->status!=1)     //优先级小于确诊  确诊>可疑>密接>次密接
		{
			p->status = 2;
		}
	}
}
void MixedQueue::SetBuildContact(int contactbuild)        //确诊的同一栋楼设置为密接
{

	for (PersonNode* p = head;p->next != NULL;p = p->next)
	{
		if (p->GetBuilding() == contactbuild && p->status != 1)
		{
			p->status = 3;                             //同一栋楼不可能是次密接 这里所以不用
		}
	}
}
PersonNode* MixedQueue::Find(int TubeCode)
{
	for (PersonNode* p = head;p != NULL;p = p->next) //从头开始查找 故为head
	{
		if (p->testNumber == TubeCode)              //若为FindPerson 则为p->personCode == personcode判断
		{
			return p;
		}
	}
	return NULL;
}

void MixedQueue::MixedTest()                        //混合测试
{
	PersonNode* p = front;
	int i = 0;
	while (i < 10)
	{
		front->testNumber = MixedNumber;         //人员检测管 代码进行赋值
		front->status = WAIT;                    //人员状态更新 ：在等待
		if (front->next != NULL)
		{
			front = front->next;                     //向后移一个结点
			front->pre = p;                          //关联前结点
		}
		else {                                      //不足十人时
			tag = 0;                                 //队列标记为空
			if (i != 9)
			{
				cout << "最后只剩" << i + 1 << "不足十个人";  //输出此次检测人数
				break;
			}
		}
		i++;
	}
	MixedNumber++;                          //检测管码更新
}
MixedQueue::MixedQueue()                    
{
	head = rear = new PersonNode(00000000, NULL);	// 生成链队列头结点
	front=head->next;
}
void MixedQueue::EnQueue(const int e)      // 混合检测入队函数
{
	PersonNode* p;
	p = new PersonNode(e, NULL);	         // 生成一个新结点
	if (front == NULL)
	{
		front = p;
		rear = p;
		head->next = front;
		front->pre = head;
	}
	else if (p) {
		rear->next = p;	                 // 将新结点加在队尾
		p->pre = rear;
		rear = rear->next;				 // rear指向新队尾
	}
	tag = 1;                            //将队伍状态设置为非空
}
void MixedQueue::ShowQueue()            //展示混合排队的人 所以用front 不用head
{

	if (tag == 0)                             //判断队伍是否为空
		cout << "混检队伍为空" << endl;
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
	while (p != NULL) {	                 //依次删除队列中的元素结点
		head->next = p->next;
		delete p;
		p = head->next;
	}
	rear = head;
}



#endif // !MIXEDQUEUE_H

