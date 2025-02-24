#ifndef PAINTTREE_H
#define PAINTTREE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QlistWidget>
#include "BiTree.h"

#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
class QPaintEvent;
class QPainter;
class BiTNode;

class PaintTree : public QWidget
{
    Q_OBJECT
    public:
        PaintTree();
        void paintEvent(QPaintEvent *event);
    public:
        BiTNode* bitree;
        QMenu* buttonMenu = new QMenu(this);

};
#endif
