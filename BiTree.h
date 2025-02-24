#ifndef BITREE_H
#define BITREE_H
#include<iostream>
#include "mylist.h"
#include <QPoint>
#include <QPainter>
#include <cstdlib>
#include <QString>
#include <QPainterPath>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include "Button.h"
#include <QInputDialog>
#define Fail -1
#define Success 0
using namespace std;
class mylist;
typedef int ElemType;
class PaintTree;
class myButton;
class BiTNode {
public:
	ElemType data;
	BiTNode* lchild = NULL, * rchild = NULL, * parent = NULL;
	int ltag = 0;
	int rtag = 0;
	int x = 0;
	int y = 0;
	int threaded = 0;
	myButton* button;
	PaintTree* painttree;
public:

	BiTNode(PaintTree *painttree);
	BiTNode(ElemType data, PaintTree* painttree);
	void ChangeData(ElemType data);

	void InsertLeftChild(ElemType data);
	void InsertRightChild(ElemType data);
	void Destroy();
	int DeleteLeft(bool IfKeepRest);
	int DeleteRight(bool IfKeepRest);
	void PreOrderTraverse(mylist &list);
	void InOrderTraverse(mylist& list);
	void PostOrderTraverse(mylist& list);
	int CountLeaves();
	void Threading(mylist list,int ThreadedType);
	void NoneThreading();

	void ThreadPreOrderTraverse(mylist& list);
	void ThreadInOrderTraverse(mylist& list);

	void Draw(PaintTree* painttree,QPoint pt, QPainter* painter, int scale, int height, int radi);
	void DrawThreading(QPainter* painter);
	int height();

};
#endif
