#include "mylist.h"

mylist::mylist()
{
	this->data = 0;
	this->next = NULL;
	this->lenth = 0;
	this->pdata = NULL;
}

mylist::mylist(ElemType data)
{
	this->data = data;
	this->next = NULL;
	this->lenth = 1;
	this->pdata = NULL;
}
mylist::mylist(ElemType data,BiTNode* pdata)
{
	this->data = data;
	this->next = NULL;
	this->lenth = 1;
	this->pdata = pdata;
}

void mylist::append(ElemType data)
{
	mylist* p = new mylist(data);
	mylist* q = this;
	while (q->next)
		q = q->next;
	q->next = p;
	this->lenth++;
}
void mylist::append(ElemType data,BiTNode* pdata)
{
	mylist* p = new mylist(data,pdata);
	mylist* q = this;
	while (q->next)
		q = q->next;
	q->next = p;
	this->lenth++;
}

void mylist::ChangeData(ElemType data)
{
	this->data = data;
}

int mylist::len()
{
	return this->lenth;
}

mylist& mylist::operator[](int i)
{
	if (this->len() <= i || i < 0)
	{
		mylist* fail=new mylist(-1);
		return *fail;
	}
	else
	{
		int sum = i;
		mylist* p = this->next;
		while (p)
		{
			if (!sum)
				return *p;
			sum--;
			p = p->next;
		}
	}
	mylist* success = new mylist(0);
	return *success;
}

