#ifndef LINKH_H
#define LINKH_H
#include"HNode.h"
#include<iostream>
using namespace std;
class LinkH {                                   //  ���ಡ������
public:
	HNode* head;			                 	// ͷ���ָ��
	LinkH();						 	        // �޲����Ĺ��캯��
	bool FindHVirus(int &e1, int &e2);          //�����Ƿ���Ʋ��� ������������ ���Բ������ô��ݲ���
	virtual ~LinkH();				            // ��������
	void append(int e1, int e2);                //H��׷������
};
LinkH::LinkH()
{ 
	head = new HNode;		              // ����ͷ���
}
bool LinkH::FindHVirus(int &e1, int &e2)  //���ҿ��Ʋ��� ���޸�
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
	q = new HNode(e1, e2,NULL);                     // �����½��q
	for (p = head; p->next != NULL; p = p->next);	// pָ���β���	
	p->next = q;                                    // �ڵ�����ı�βλ�ò����½�� 


}
#endif // !LINKS_H
