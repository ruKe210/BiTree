#include "Button.h"

void myButton::myButton_connect(BiTNode* Bitree, PaintTree* painttree)
{
    this->Bitree = Bitree;
    this->painttree = painttree;
    this->buttonMenu->addAction(buttonAction0);
    this->buttonMenu->addAction(buttonAction1);
    this->buttonMenu->addAction(buttonAction2);
    connect(buttonAction0, &QAction::triggered, this, &myButton::ChangeData);
    connect(buttonAction1, &QAction::triggered, this, &myButton::InsertLeftChild);
    connect(buttonAction2, &QAction::triggered, this, &myButton::InsertRightChild);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowWidget(const QPoint&)));
}
myButton::~myButton()
{
    delete this->buttonAction1;
    delete this->buttonAction2;
    delete this->buttonMenu;
}

#if 0
myButton::myButton(BiTNode* Bitree, PaintTree* painttree)
{
    this->Bitree = Bitree;
    this->painttree = painttree;
    this->buttonMenu = new QMenu(this);
    this->buttonAction1 = new QAction("btnFirstAction", this);
    this->buttonAction2 = new QAction("btnSecondAction", this);
    this->buttonMenu->addAction(buttonAction1);
    this->buttonMenu->addAction(buttonAction2);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowWidget(const QPoint&)));
}
#endif
void myButton::ShowWidget(const QPoint& point)
{
    buttonMenu->move(QCursor::pos());
    buttonMenu->show();
    buttonMenu->exec();
}
void myButton::ChangeData()
{
    bool ok;
    QString text = QInputDialog::getText(this->painttree, QString("请输入要更改的值"), QString("输入值(仅数字): "), QLineEdit::Normal, QString(""), &ok);
    if (ok)
    {
        this->Bitree->ChangeData(text.toInt());
        this->painttree->update();
    }
    return;
}
void myButton::InsertLeftChild()
{
    bool ok;
    QString text = QInputDialog::getText(this->painttree, QString("请输入插入的值"), QString("输入值(仅数字): "), QLineEdit::Normal, QString(""), &ok);
    if(ok)
    {
        if (this->Bitree->ltag)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("错误");
            msgBox.setText("已存在左子节点");
            msgBox.setIcon(QMessageBox::Critical);
            QPushButton* okButton = msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        this->Bitree->InsertLeftChild(text.toInt());
        this->painttree->bitree->NoneThreading();
        this->painttree->update();
    }
    return;
}
void myButton::InsertRightChild()
{
    bool ok;
    QString text = QInputDialog::getText(this->painttree, QString("请输入插入的值"), QString("输入值(仅数字): "), QLineEdit::Normal, QString(""), &ok);
    if (ok)
    {
        if (this->Bitree->rtag)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("错误");
            msgBox.setText("已存在右子节点");
            msgBox.setIcon(QMessageBox::Critical);
            QPushButton* okButton = msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
            return;
        }
        this->Bitree->InsertRightChild(text.toInt());
        this->painttree->bitree->NoneThreading();
        this->painttree->update();
    }
    return;
}
