#ifndef BUTTON_H
#define BUTTON_H
#include <QPushButton>
#include <QMessageBox>
#include <QMenu>
#include "BiTree.h"
#include "paint_tree.h"

class BiTNode;
class PaintTree;
class myButton : public QPushButton
{
    Q_OBJECT
public:
    BiTNode* Bitree;
    PaintTree* painttree;
    QMenu* buttonMenu = new QMenu(this);
    QAction* buttonAction0 = new QAction("更改节点数值", this);
    QAction* buttonAction1 = new QAction("插入左子节点", this);
    QAction* buttonAction2 = new QAction("插入右子节点", this);

    void myButton_connect(BiTNode* Bitree, PaintTree* painttree);
    ~myButton();

    using QPushButton::QPushButton;
private slots:
    void ChangeData();
    void ShowWidget(const QPoint& point);
    void InsertLeftChild();
    void InsertRightChild();
};
#endif
