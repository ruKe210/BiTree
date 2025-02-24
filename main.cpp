#include <QApplication>
#include "dialog.h"
#include "BiTree.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    PaintTree* tree = new PaintTree;
    //tree->bitree->InsertLeftChild(1);
    //tree->bitree->InsertRightChild(2);
    //tree->bitree->lchild->InsertRightChild(3);
    tree->show();
    MyDialog* dlg = new MyDialog;
    dlg->create(tree->bitree);
    dlg->show();
    return app.exec();
}
