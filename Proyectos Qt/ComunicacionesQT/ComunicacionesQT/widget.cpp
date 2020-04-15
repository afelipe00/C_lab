#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        qDebug() << "Name: " << info.portName();
        qDebug() << "Description: " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "Vendor: " << info.vendorIdentifier();
        qDebug() << "Product: " << info.productIdentifier();
        ui->comboBox->addItem(info.portName());
    }
    m_serial = new QSerialPort(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    static int cont = 0;
    qDebug() << cont++;
    ui->label->setText(QString::number(cont));
}

void Widget::on_pushButton_2_clicked()
{
    int a;
    int b;

    a = ui->lineEdit->text().toInt();
    b = ui->lineEdit_2->text().toInt();
    c = a + b;
    ui->plainTextEdit->appendPlainText(QString::number(c));
    qDebug() << "La suma es " << c;
}

void Widget::on_pushButton_3_clicked()
{
    QString puerto = ui->comboBox->currentText();
    openSerialPort(puerto);
}

void Widget::readSerial()
{
   QByteArray serialData = m_serial->readAll();
   qDebug() << serialData;
}

void Widget::openSerialPort(QString p)
{
    if(m_serial->isOpen()){
        m_serial->close();
        ui->pushButton_3->setText("Open Port");
        ui->comboBox->setDisabled(false);
    }
    disconnect(m_serial,SIGNAL(readyRead()),this, SLOT(readSerial()));
    m_serial->setPortName(p);
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_serial,SIGNAL(readyRead()),this, SLOT(readSerial()));
    if(m_serial->open(QIODevice::ReadWrite)){
        ui->pushButton_3->setText("Close Port");
        ui->comboBox->setDisabled(true);
    }else{
        QMessageBox::critical(this,tr("Error"), m_serial->errorString());
    }

}

void Widget::on_pushButton_4_clicked()
{
    static int n = 0;
    char texto[32];

    sprintf(texto,"%d", n++);

    if(m_serial->isOpen()){
        m_serial->write(texto,strlen(texto));
    }

}
