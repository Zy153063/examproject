#ifndef PERSONNODE_H
#define PERSONNODE_H
#include <string>
using namespace std;
string GetStatus(int status);                             //获取状态
enum status {
	                     NEVAGATIVE, CONFIRMED, SUSPICIOUS, CONTACT,SECONTACT, WAIT,  INLINE,  UNTEST
};  //标记核酸检测状态 分别为 阴性，   确诊，      可疑，    密接，   次密接,等待结果, 在排队,未检测
struct PersonNode     //人员结点
{
	PersonNode* pre;                    //指向人前一个的指针
	int status;                         //状态 
	int personCode;                     //人员代码
	//int testTube;                     //检测管
	PersonNode*next;                    //后指针  指向下一位
	int testNumber;                     //测试数字 检测管
	int GetBuilding();                  //获取楼号 用于判断检测
	string GetStatus();                 //获取人的 状态
//相关函数：
	PersonNode()
	{
		personCode = -10000000;   //设置为负不会与随机值重复
		pre = NULL;
		status = UNTEST;
		next = NULL;
		testNumber = -1;
	}
	PersonNode(int code, PersonNode*link);

};
string PersonNode::GetStatus()
{
	string a[10] = { "阴性","确诊","可疑", "密接", "次密接", "等待结果", "在排队", "未检测" };

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
	string a[10] = { "阴性","确诊","可疑", "密接", "次密接", "等待结果", "在排队", "未检测" };
	return a[status];
}
#endif // !PERSONNODE_H

