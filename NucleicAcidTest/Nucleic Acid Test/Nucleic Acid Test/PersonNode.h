#ifndef PERSONNODE_H
#define PERSONNODE_H
#include <string>
using namespace std;
string GetStatus(int status);                             //��ȡ״̬
enum status {
	                     NEVAGATIVE, CONFIRMED, SUSPICIOUS, CONTACT,SECONTACT, WAIT,  INLINE,  UNTEST
};  //��Ǻ�����״̬ �ֱ�Ϊ ���ԣ�   ȷ�      ���ɣ�    �ܽӣ�   ���ܽ�,�ȴ����, ���Ŷ�,δ���
struct PersonNode     //��Ա���
{
	PersonNode* pre;                    //ָ����ǰһ����ָ��
	int status;                         //״̬ 
	int personCode;                     //��Ա����
	//int testTube;                     //����
	PersonNode*next;                    //��ָ��  ָ����һλ
	int testNumber;                     //�������� ����
	int GetBuilding();                  //��ȡ¥�� �����жϼ��
	string GetStatus();                 //��ȡ�˵� ״̬
//��غ�����
	PersonNode()
	{
		personCode = -10000000;   //����Ϊ�����������ֵ�ظ�
		pre = NULL;
		status = UNTEST;
		next = NULL;
		testNumber = -1;
	}
	PersonNode(int code, PersonNode*link);

};
string PersonNode::GetStatus()
{
	string a[10] = { "����","ȷ��","����", "�ܽ�", "���ܽ�", "�ȴ����", "���Ŷ�", "δ���" };

	return a[status];
}
int PersonNode::GetBuilding()           
{
	return personCode / 100000;
}
PersonNode::PersonNode(int code, PersonNode*link)
{
	pre = NULL;
	personCode = code;
	status = UNTEST;
	testNumber = -1;
	next = link;
}
string GetStatus(int status)
{
	string a[10] = { "����","ȷ��","����", "�ܽ�", "���ܽ�", "�ȴ����", "���Ŷ�", "δ���" };
	return a[status];
}
#endif // !PERSONNODE_H

