#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include "BiTree.h"
class BiTNode;
using namespace std;
typedef int ElemType;
class mylist
{
public:
	ElemType data;
	mylist* next;
	BiTNode* pdata;
	int lenth;
	mylist();
	mylist(ElemType data);
	mylist(ElemType data,BiTNode* pdata);
	void append(ElemType data);
	void append(ElemType data,BiTNode* pdata);
	void ChangeData(ElemType data);
	int len();
	mylist& operator[](int i);
};
#endif

