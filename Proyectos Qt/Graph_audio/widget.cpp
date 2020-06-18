#include "widget.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyle>
#include <QMenu>
#include <QFileDialog>
#include <QTimerEvent>
#include <QMessageBox>

//constructor
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    ,m_mode(Nomode)
    ,m_infoMessage(new Qlabel)
{
    createUi();
    connectUi();
}
//destructor
Widget::~Widget()
{
}

void Widget::createUi(){
    createMenus();
    setWindowTitle(tr("prueba"));

    QVBoxLayout *windowLayout = new QVBoxLayout(this);

}

void Widget::connectUi(){

}

void Widget::createMenus(){

}
