#ifndef DIALOG_H
#define DIALOG_H

#include "ui_paint_tree.h"
#include "paint_tree.h"
#include "BiTree.h"
#include "mylist.h"
class mylist;
class BiTNode;
class MyDialog: public QDialog, public Ui_Dialog
{
    Q_OBJECT
    public:
        MyDialog(QWidget *parent = 0);
        void create(BiTNode* Bitree);
    private slots:
        void PreOrder();
        void InOrder();
        void PostOrder();
        void CountLeaves();
        void PreThreading();
        void InThreading();
        void PostThreading();
        void NoneThreading();
        void ThreadedPreOrder();
        void ThreadedInOrder();
    private:
        BiTNode* Bitree;
};

#endif
