#ifndef HNODE_H
#define HNODE_H
//template<class ElemType>
struct HNode {                 //H克制病毒的结点

	int twoNumber[2];         // 数据域为数组存放两个互相克制的病毒 
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

