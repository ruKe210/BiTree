#include <QtGui>
#include "dialog.h"
#define Pre  1
#define In   2
#define Post 3
MyDialog::MyDialog(QWidget* parent) : QDialog(parent)
{
    setupUi(this);
    connect(this->preorder, SIGNAL(clicked()), SLOT(PreOrder()));
    connect(this->inorder, SIGNAL(clicked()), SLOT(InOrder()));
    connect(this->postorder, SIGNAL(clicked()), SLOT(PostOrder()));
    connect(this->countleaves, SIGNAL(clicked()), SLOT(CountLeaves()));
    connect(this->prethreading, SIGNAL(clicked()), SLOT(PreThreading()));
    connect(this->inthreading, SIGNAL(clicked()), SLOT(InThreading()));
    connect(this->postthreading, SIGNAL(clicked()), SLOT(PostThreading()));
    connect(this->nonethreading, SIGNAL(clicked()), SLOT(NoneThreading()));
    connect(this->threaded_preorder, SIGNAL(clicked()), SLOT(ThreadedPreOrder()));
    connect(this->threaded_inorder, SIGNAL(clicked()), SLOT(ThreadedInOrder()));
    connect(this->exit, SIGNAL(clicked()), qApp, SLOT(quit()));
}
void MyDialog::create(BiTNode* Bitree)
{
    this->Bitree = Bitree;
}
void MyDialog::PreOrder()
{
    mylist list;
    QString ts;
    this->Bitree->PreOrderTraverse(list);
    for (int i = 0; i < list.len(); i++)
    {
        ts.append(to_string(list[i].data).c_str());
        ts.append(" ");
    }
    this->output->setText(ts);
}
void MyDialog::InOrder()
{
    mylist list;
    QString ts;
    this->Bitree->InOrderTraverse(list);
    for (int i = 0; i < list.len(); i++)
    {
        ts.append(to_string(list[i].data).c_str());
        ts.append(" ");
    }
    this->output->setText(ts);
}
void MyDialog::PostOrder()
{
    mylist list;
    QString ts;
    this->Bitree->PostOrderTraverse(list);
    for (int i = 0; i < list.len(); i++)
    {
        ts.append(to_string(list[i].data).c_str());
        ts.append(" ");
    }
    this->output->setText(ts);
}
void MyDialog::CountLeaves()
{
    int num;
    num = this->Bitree->CountLeaves();
    QString ts;
    ts.append(to_string(num).c_str());
    ts.append("个");
    this->output->setText(ts);
}
void MyDialog::PreThreading()
{
    mylist list;
    this->Bitree->NoneThreading();
    this->Bitree->PreOrderTraverse(list);
    this->Bitree->Threading(list, Pre);
    this->Bitree->painttree->update();
    return;
}
void MyDialog::InThreading()
{
    mylist list;
    this->Bitree->NoneThreading();
    this->Bitree->InOrderTraverse(list);
    this->Bitree->Threading(list, In);
    this->Bitree->painttree->update();
    return;
}
void MyDialog::PostThreading()
{
    mylist list;
    this->Bitree->NoneThreading();
    this->Bitree->PostOrderTraverse(list);
    this->Bitree->Threading(list, Post);
    this->Bitree->painttree->update();
    return;
}
void MyDialog::NoneThreading()
{
    this->Bitree->NoneThreading();
    this->Bitree->painttree->update();
}
void MyDialog::ThreadedPreOrder()
{
    mylist list;
    QString ts;
    if (!this->Bitree->threaded)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("尚未线索化!\n请线索化后再次尝试!");
        msgBox.setIcon(QMessageBox::Critical);
        QPushButton* okButton = msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if (this->Bitree->threaded != Pre)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("线索化出错!\n不是先序线索化!");
        msgBox.setIcon(QMessageBox::Critical);
        QPushButton* okButton = msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    this->Bitree->ThreadPreOrderTraverse(list);
    for (int i = 0; i < list.len(); i++)
    {
        ts.append(to_string(list[i].data).c_str());
        ts.append(" ");
    }
    this->output->setText(ts);
}
void MyDialog::ThreadedInOrder()
{
    mylist list;
    QString ts;
    if (!this->Bitree->threaded)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("尚未线索化!\n请线索化后再次尝试!");
        msgBox.setIcon(QMessageBox::Critical);
        QPushButton* okButton = msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if (this->Bitree->threaded != In)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("线索化出错!\n不是中序线索化!");
        msgBox.setIcon(QMessageBox::Critical);
        QPushButton* okButton = msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    this->Bitree->ThreadInOrderTraverse(list);
    for (int i = 0; i < list.len(); i++)
    {
        ts.append(to_string(list[i].data).c_str());
        ts.append(" ");
    }
    this->output->setText(ts);
}

