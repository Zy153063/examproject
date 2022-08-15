#ifndef LINKH_H
#define LINKH_H
#include"HNode.h"
#include<iostream>
using namespace std;
class LinkH {                                   //  异类病毒链表
public:
	HNode* head;			                 	// 头结点指针
	LinkH();						 	        // 无参数的构造函数
	bool FindHVirus(int &e1, int &e2);          //查找是否克制病毒 如果发现则更改 所以采用引用传递参数
	virtual ~LinkH();				            // 析构函数
	void append(int e1, int e2);                //H表追加数据
};
LinkH::LinkH()
{ 
	head = new HNode;		              // 构造头结点
}
bool LinkH::FindHVirus(int &e1, int &e2)  //查找克制病毒 并修改
{
	HNode* p = head->next;
	 while (p != NULL)
	 {
		 for (int i = 0;i < 2;i++)
		 {
			 if (p->twoNumber[i] == e1)
			 {
				 if (i == 0)
					 e1 = p->twoNumber[1];
				 else
					 e1= p->twoNumber[0];
				 return true;
			 }
			 else if (p->twoNumber[i] == e2)
			 {
				 if (i == 0)
					 e2 = p->twoNumber[1];
				 else
					 e2 = p->twoNumber[0];
				 return true;
			 }
		 }
		 p = p->next;
	 }
	 return false;
}
LinkH::~LinkH()
{
}

void LinkH::append(int e1, int e2)
{
	HNode* p, * q;
	q = new HNode(e1, e2,NULL);                     // 生成新结点q
	for (p = head; p->next != NULL; p = p->next);	// p指向表尾结点	
	p->next = q;                                    // 在单链表的表尾位置插入新结点 


}
#endif // !LINKS_H
