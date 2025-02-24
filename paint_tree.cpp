#include <QPainter>
#include <QPoint>
#include "paint_tree.h"
#include <QtGui>
#include <qdebug.h>
PaintTree::PaintTree()
{
    this->bitree = new BiTNode(this);
    resize(800, 600);
    setWindowTitle(tr("Paint Tree"));

}

void PaintTree::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if (this->bitree->threaded)
        this->bitree->DrawThreading(&painter);

    if(this->bitree->height() == 0)
        this->bitree->Draw(this,QPoint(size().width() / 2, 25),
            &painter, size().width() / 4, 0, 20);
    else
        this->bitree->Draw(this,QPoint(size().width() / 2, 25), 
            &painter, size().width() / 4, (size().height() - 50) / this->bitree->height(), 20);


}


