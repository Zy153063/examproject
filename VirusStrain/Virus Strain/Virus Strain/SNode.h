#ifndef SNODE_H
#define SNODE_H
// �����
struct SNode            //ͬ�ಡ�����
{
	// ���ݳ�Ա:
	int data;				// ������
	SNode* next;		   // ָ����

// ���캯��:
	SNode();						// �޲����Ĺ��캯��
	SNode(int e, SNode* link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};
// ������ʵ�ֲ���

SNode::SNode()
// Ĭ�Ϲ���
{
	data = 0;
	next = NULL;
}

SNode::SNode(int e, SNode* link)
//�вι���
{
	data = e;
	next = link;
}


#endif // !1


