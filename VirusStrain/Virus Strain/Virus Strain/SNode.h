#ifndef SNODE_H
#define SNODE_H
// 结点类
struct SNode            //同类病毒结点
{
	// 数据成员:
	int data;				// 数据域
	SNode* next;		   // 指针域

// 构造函数:
	SNode();						// 无参数的构造函数
	SNode(int e, SNode* link = NULL);	// 已知数数据元素值和指针建立结构
};
// 结点类的实现部分

SNode::SNode()
// 默认构造
{
	data = 0;
	next = NULL;
}

SNode::SNode(int e, SNode* link)
//有参构造
{
	data = e;
	next = link;
}


#endif // !1


