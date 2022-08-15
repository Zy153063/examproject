#ifndef LINKS_H
#define LINKS_H
#include"HNode.h"
#include"SNode.h"
class LinkS {                            //  同类病毒链
public:									   
	SNode* head;				         // 头结点指				  
	LinkS();							 // 无参数的构造函数
	bool FindVirus(int e);               //查找是否含有病毒
	virtual ~LinkS();				     // 析构函数
	LinkS(int e1, int e2 );              //有参数的构造函数
	void append(const int &e1);           //在尾部追加结点函数
	void append(const int& e1, const int& e2);
	void  mergeLink(SNode* q);             //合并链表
};
void LinkS::append(const int& e1, const int& e2)   //两个元素追加链表
{
	SNode* p, * q1,*q2;
	q1 = new SNode(e1, NULL);    // 生成新结点q
	q2 = new SNode(e2, NULL);
	for (p = head; p->next != NULL; p = p->next);	// p指向表尾结点	
	p->next = q1;                        // 在单链表的表尾位置插入新结点 
	q1->next = q2;
}
 void LinkS::mergeLink(SNode *q)   //合并相同链表
{
	 SNode* p;
	 for (p = head; p->next != NULL; p = p->next);	// p指向表尾结点	
	 p->next = q;
}
bool LinkS::FindVirus(int e)
{
	SNode * p = head->next;
	while (p != NULL)
	{
		if (p->data == e)
			return true;
		p = p->next;
	}
	return false;
}
LinkS::LinkS()
{
	 head = new SNode(0,NULL);		// 构造头结点
}

 LinkS::~LinkS()
 {
 }

LinkS::LinkS(int e1, int e2)
 {
	 SNode* p=head;
	 head->next = new SNode(e1, NULL);
	 p = p->next;
	 p->next=new SNode(e2, NULL);
 }
void LinkS::append(const int &e1)  //追加单个元素为结点
{
	SNode* p, * q;
	q = new SNode(e1, NULL);    // 生成新结点q
	for (p = head; p->next != NULL; p = p->next);	// p指向表尾结点	
	p->next = q;                        // 在单链表的表尾位置插入新结点 
}
#endif // 