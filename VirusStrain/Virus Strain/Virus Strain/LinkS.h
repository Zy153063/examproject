#ifndef LINKS_H
#define LINKS_H
#include"HNode.h"
#include"SNode.h"
class LinkS {                            //  ͬ�ಡ����
public:									   
	SNode* head;				         // ͷ���ָ				  
	LinkS();							 // �޲����Ĺ��캯��
	bool FindVirus(int e);               //�����Ƿ��в���
	virtual ~LinkS();				     // ��������
	LinkS(int e1, int e2 );              //�в����Ĺ��캯��
	void append(const int &e1);           //��β��׷�ӽ�㺯��
	void append(const int& e1, const int& e2);
	void  mergeLink(SNode* q);             //�ϲ�����
};
void LinkS::append(const int& e1, const int& e2)   //����Ԫ��׷������
{
	SNode* p, * q1,*q2;
	q1 = new SNode(e1, NULL);    // �����½��q
	q2 = new SNode(e2, NULL);
	for (p = head; p->next != NULL; p = p->next);	// pָ���β���	
	p->next = q1;                        // �ڵ�����ı�βλ�ò����½�� 
	q1->next = q2;
}
 void LinkS::mergeLink(SNode *q)   //�ϲ���ͬ����
{
	 SNode* p;
	 for (p = head; p->next != NULL; p = p->next);	// pָ���β���	
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
	 head = new SNode(0,NULL);		// ����ͷ���
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
void LinkS::append(const int &e1)  //׷�ӵ���Ԫ��Ϊ���
{
	SNode* p, * q;
	q = new SNode(e1, NULL);    // �����½��q
	for (p = head; p->next != NULL; p = p->next);	// pָ���β���	
	p->next = q;                        // �ڵ�����ı�βλ�ò����½�� 
}
#endif // 