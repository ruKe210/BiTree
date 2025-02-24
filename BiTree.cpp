#include "BiTree.h"
#include "paint_tree.h"
BiTNode::BiTNode(PaintTree* painttree)
{
	this->data = 0;
	this->lchild = NULL;
	this->rchild = NULL;
	this->ltag = 0;
	this->rtag = 0;
	this->threaded = 0;
	this->x = 0;
	this->y = 0;
	this->painttree = painttree;
	this->button = new myButton("", painttree);
	this->button->resize(40, 40);
	this->button->setStyleSheet("QPushButton{font-size:100px;border-style:solid;border-radius:150px;}");
	this->button->myButton_connect(this, painttree);
}

BiTNode::BiTNode(ElemType data, PaintTree* painttree)
{
	this->data = data;
	this->lchild = NULL;
	this->rchild = NULL;
	this->ltag = 0;
	this->rtag = 0;
	this->threaded = 0;
	this->x = 0;
	this->y = 0;
	this->painttree = painttree;
	this->button = new myButton("", painttree);
	this->button->resize(40, 40);
	this->button->setStyleSheet("QPushButton{font-size:100px;border-style:solid;border-radius:150px;}");
	this->button->myButton_connect(this, painttree);
}

void BiTNode::ChangeData(ElemType data)
{
	this->data = data;
}

void BiTNode::InsertLeftChild(ElemType data)
{
	BiTNode* q = new BiTNode(data, this->painttree);
	if (!q)
		exit(-1);
	this->lchild = q;
	this->ltag = 1;
}

void BiTNode::InsertRightChild(ElemType data)
{
	BiTNode* q = new BiTNode(data, this->painttree);
	if (!q)
		exit(-1);
	this->rchild = q;
	this->rtag = 1;
}

void BiTNode::Destroy()
{
	if (lchild == NULL && rchild == NULL)
		delete this;
	else if (lchild != NULL && rchild == NULL)
	{
		this->lchild->Destroy();
		this->lchild = NULL;
		this->ltag = 0;
	}
	else if (lchild == NULL && rchild != NULL)
	{
		this->rchild->Destroy();
		this->rchild = NULL;
		this->rtag = 0;
	}
	else
	{
		this->lchild->Destroy();
		this->lchild = NULL;
		this->ltag = 0;
		this->rchild->Destroy();
		this->rchild = NULL;
		this->rtag = 0;

	}
}

int BiTNode::DeleteLeft(bool IfKeepRest)
{
	if (IfKeepRest)
	{
		if (this->lchild->lchild == NULL && this->lchild->rchild == NULL)
		{
			this->lchild->Destroy();
			this->lchild = NULL;
			this->ltag = 0;
		}
		else if (this->lchild->lchild == NULL && this->lchild->rchild != NULL)
		{
			BiTNode* p = this->lchild;
			this->lchild = this->lchild->rchild;
			delete p;
		}
		else if (this->lchild->lchild != NULL && this->lchild->rchild == NULL)
		{
			BiTNode* p = this->lchild;
			this->lchild = this->lchild->lchild;
			delete p;
		}
		else
			return Fail;
	}
	else
	{
		this->lchild->Destroy();
		this->lchild = NULL;
		this->ltag = 0;
	}
	return Success;

}

int BiTNode::DeleteRight(bool IfKeepRest)
{
	if (IfKeepRest)
	{
		if (this->rchild->lchild == NULL && this->rchild->rchild == NULL)
		{
			this->rchild->Destroy();
			this->rchild = NULL;
			this->rtag = 0;
		}
		else if (this->rchild->lchild == NULL && this->rchild->rchild != NULL)
		{
			BiTNode* p = this->rchild;
			this->rchild = this->rchild->rchild;
			delete p;
		}
		else if (this->rchild->lchild != NULL && this->rchild->rchild == NULL)
		{
			BiTNode* p = this->rchild;
			this->rchild = this->rchild->lchild;
			delete p;
		}
		else
			return Fail;
	}
	else
	{
		this->rchild->Destroy();
		this->rchild = NULL;
	}
	return Success;
}

void BiTNode::PreOrderTraverse(mylist& list)
{
	list.append(this->data, this);
	if (this->ltag)
		this->lchild->PreOrderTraverse(list);
	if (this->rtag)
		this->rchild->PreOrderTraverse(list);
}

void BiTNode::InOrderTraverse(mylist& list)
{
	if (this->ltag)
		this->lchild->InOrderTraverse(list);
	list.append(this->data, this);
	if (this->rtag)
		this->rchild->InOrderTraverse(list);
}

void BiTNode::PostOrderTraverse(mylist& list)
{
	if (this->ltag)
		this->lchild->PostOrderTraverse(list);
	if (this->rtag)
		this->rchild->PostOrderTraverse(list);
	list.append(this->data, this);
}

int BiTNode::CountLeaves()
{
	if (this->ltag == 0 && this->rtag == 0)
		return 1;
	else if (this->ltag == 0 && this->rtag != 0)
		return this->rchild->CountLeaves();
	else if (this->ltag != 0 && this->rtag == 0)
		return this->lchild->CountLeaves();
	else
		return this->lchild->CountLeaves() + this->rchild->CountLeaves();
}

void BiTNode::Threading(mylist list,int ThreadedType)
{
	for (int i = 0; i < list.len(); i++)
	{
		list[i].pdata->threaded = ThreadedType;
		if (list[i].pdata->ltag && list[i].pdata->rtag)
			continue;
		else if (!list[i].pdata->ltag && list[i].pdata->rtag)
		{
			if (i - 1 >= 0)
				list[i].pdata->lchild = list[i - 1].pdata;
		}
		else if (list[i].pdata->ltag && !list[i].pdata->rtag)
		{
			if (i + 1 < list.len())
				list[i].pdata->rchild = list[i + 1].pdata;
		}
		else
		{
			if (i - 1 >= 0)
				list[i].pdata->lchild = list[i - 1].pdata;
			if (i + 1 < list.len())
				list[i].pdata->rchild = list[i + 1].pdata;
		}

	}
}


void BiTNode::NoneThreading()
{
	if (this->ltag)
		this->lchild->NoneThreading();
	if (this->rtag)
		this->rchild->NoneThreading();
	if (!this->ltag)
		this->lchild = NULL;
	if (!this->rtag)
		this->rchild = NULL;
	this->threaded = 0;
}

void BiTNode::ThreadPreOrderTraverse(mylist& list)
{
	BiTNode* p = this;
	while (p)
	{
		list.append(p->data);
		if (p->ltag)
			p = p->lchild;
		else
			p = p->rchild;
	}
}

void BiTNode::ThreadInOrderTraverse(mylist& list)
{
	BiTNode* p = this;
	while (p)
	{
		while (p->ltag)
		{
			p = p->lchild;
		}
		list.append(p->data);
		while (!p->rtag && p->rchild)
		{
			p = p->rchild;
			list.append(p->data);
		}
		p = p->rchild;
	}
}

void BiTNode::Draw(PaintTree* painttree, QPoint pt, QPainter* painter, int scale, int height, int radi)
{
	QPoint end;
	QRect rect(QPoint(pt.x() - radi, pt.y() - radi), QPoint(pt.x() + radi, pt.y() + radi));
	QBrush brush(Qt::green, Qt::SolidPattern);
	QString str = QString("%1").arg(this->data, 0, 10);
	QFont font;
	this->x = pt.x();
	this->y = pt.y();
	font.setPixelSize(radi - 2 * str.length());
	if (this->ltag)
	{
		end.setX(pt.x() - scale);
		end.setY(pt.y() + height);
		painter->setPen(Qt::black);
		painter->drawLine(pt, end);
		this->lchild->Draw(painttree, end, painter, scale / 2, height, radi);
	}
	if (this->rtag)
	{
		end.setX(pt.x() + scale);
		end.setY(pt.y() + height);
		painter->setPen(Qt::black);
		painter->drawLine(pt, end);
		this->rchild->Draw(painttree, end, painter, scale / 2, height, radi);
	}
#if 0
	if (this->threaded)
	{
		if (!this->ltag)
		{
			QBrush newbrush;
			newbrush.setStyle(Qt::NoBrush);
			painter->setBrush(newbrush);
			painter->setPen(Qt::black);
			QPainterPath path;
			path.moveTo(pt);
			path.cubicTo(pt.x(), pt.y(), (pt.x() + end.x()) / 2, pt.y(), end.x(), end.y());
			painter->drawPath(path);

		}
	}
#endif 
	/////////////////////////////////////////////////////

	this->button->move(pt.x() - 20, pt.y() - 20);
	this->button->show();

	/////////////////////////////////////////////////////
	painter->setBrush(brush);
	painter->setPen(Qt::black);
	painter->drawEllipse(pt, radi, radi);
	painter->setPen(Qt::red);
	painter->setFont(font);
	painter->drawText(rect, Qt::AlignCenter, str);
}


void BiTNode::DrawThreading(QPainter* painter)
{
	QBrush newbrush;
	newbrush.setStyle(Qt::NoBrush);
	painter->setBrush(newbrush);
	painter->setPen(Qt::black);

	if (!this->ltag && this->lchild)
	{
		QPainterPath path;
		path.moveTo(this->x - 20, this->y);
		if (this->x > this->lchild->x && this->y > this->lchild->y)
			path.cubicTo(this->x - 20, this->y, (this->x + this->lchild->x) / 2, this->y, this->lchild->x, this->lchild->y);
		else if (this->x < this->lchild->x && this->y < this->lchild->y)
			path.cubicTo(this->x - 20, this->y, this->x, (this->y + this->lchild->y) / 2, this->lchild->x, this->lchild->y);
		else if (this->x<this->lchild->x && this->y>this->lchild->y)
			path.cubicTo(this->x - 20, this->y, this->x, (this->y + this->lchild->y) / 2, this->lchild->x, this->lchild->y);
		else if (this->x > this->lchild->x && this->y < this->lchild->y)
			path.cubicTo(this->x - 20, this->y, (this->x + this->lchild->x) / 2, this->y, this->lchild->x, this->lchild->y);
		else if (this->y == this->lchild->y)
			path.cubicTo(this->x - 20, this->y, (this->x + this->lchild->x) / 2, this->y - 50, this->lchild->x, this->lchild->y);
		else
			path.cubicTo(this->x - 20, this->y, (this->x + this->lchild->x) / 2, this->y, this->lchild->x, this->lchild->y);
		painter->setPen(Qt::red);

		painter->drawPath(path);
	}
	if (!this->rtag && this->rchild)
	{
		QPainterPath path;
		path.moveTo(this->x + 20, this->y);
		if (this->x > this->rchild->x && this->y > this->rchild->y)
			path.cubicTo(this->x + 20, this->y, this->x, (this->y + this->rchild->y) / 2, this->rchild->x, this->rchild->y);
		else if (this->x < this->rchild->x && this->y < this->rchild->y)
			path.cubicTo(this->x + 20, this->y, (this->x + this->rchild->x) / 2, this->y, this->rchild->x, this->rchild->y);
		else if (this->x<this->rchild->x && this->y>this->rchild->y)
			path.cubicTo(this->x + 20, this->y, (this->x + this->rchild->x) / 2, this->y, this->rchild->x, this->rchild->y);
		else if (this->x > this->rchild->x && this->y < this->rchild->y)
			path.cubicTo(this->x + 20, this->y, this->x, (this->y + this->rchild->y) / 2, this->rchild->x, this->rchild->y);
		else if (this->y == this->rchild->y)
			path.cubicTo(this->x + 20, this->y, (this->x + this->rchild->x) / 2, this->y + 50, this->rchild->x, this->rchild->y);
		else
			path.cubicTo(this->x + 20, this->y, (this->x + this->rchild->x) / 2, this->y, this->rchild->x, this->rchild->y);
		painter->setPen(Qt::blue);
		painter->drawPath(path);
	}
	if (this->ltag)
		this->lchild->DrawThreading(painter);
	if (this->rtag)
		this->rchild->DrawThreading(painter);
}


int BiTNode::height()
{
	if (this->ltag == 0 && this->rtag == 0)
		return 1;
	else if (this->ltag == 0 && this->rtag != 0)
		return this->rchild->height() + 1;
	else if (this->ltag != 0 && this->rtag == 0)
		return this->lchild->height() + 1;
	else
	{
		int lefth = this->lchild->height() + 1;
		int righth = this->rchild->height() + 1;
		return lefth > righth ? lefth : righth;
	}
}

