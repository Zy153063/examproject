#ifndef HNODE_H
#define HNODE_H
//template<class ElemType>
struct HNode {                 //H���Ʋ����Ľ��

	int twoNumber[2];         // ������Ϊ����������������ƵĲ��� 
	HNode* next;        
	HNode()
	{
		next = NULL;
	}
	HNode(int e1, int e2, HNode *link)
	{
		twoNumber[0] = e1;
		twoNumber[1] = e2;
		next = link;
	}
};
#endif // !HNODE_H

