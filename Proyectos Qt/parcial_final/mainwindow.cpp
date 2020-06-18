#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        qDebug() << "Name: " << info.portName();
        qDebug() << "Description: " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "Vendor: " << info.vendorIdentifier();
        qDebug() << "Product: " << info.productIdentifier();
        ui->port_box->addItem(info.portName());
    }
    m_serial = new QSerialPort(this);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::gray);
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(Pal);
    ui->widget1->setAutoFillBackground(true);
    ui->widget1->setPalette(Pal);
    //CreateUi();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenSerialPort(QString port){
    qDebug()<<"Puerto abierto";
    disconnect(m_serial,SIGNAL(readyRead()),this, SLOT(ModeSerial()));
    m_serial->setPortName(port);
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_serial,SIGNAL(readyRead()),this, SLOT(ModeSerial()));
    if(m_serial->open(QIODevice::ReadWrite)){
        ui->connect_button->setText("Close Port");
        ui->port_box->setDisabled(true);
    }else{
        QMessageBox::critical(this,tr("Error"), m_serial->errorString());
    }
}

void MainWindow::ModeSerial(){
    QByteArray serialData = m_serial->readAll();
    if(serialData.size()>1){
        if (mode=='n'){
            qDebug() << "Sleep";
            qDebug()<<serialData;
            mode = 'r';
        }else if(mode=='w'){
            //WriteSerial();
        }else if(mode == 'r'){
            if(flag_port==false){
                ReadSerial(serialData);
            }
        }
    }else{
        qDebug()<<"paquete no encontrado";
    }
}

void MainWindow::ReadSerial(QByteArray serialData){
    qDebug() << "mode read";
    qDebug()<<"datos Recibidos: "<<serialData;
    sem1 = serialData.at(1);
    sem2 = serialData.at(3);
    sem3 = serialData.at(5);
    sem4 = serialData.at(7);
    qDebug()<<"datos seg1: "<<sem1;
    qDebug()<<"datos seg2: "<<sem2;
    qDebug()<<"datos seg3: "<<sem3;
    qDebug()<<"datos seg4: "<<sem4;
    LogicUi();
}

void MainWindow::CloseSerial(){
    if(m_serial->isOpen()){
        m_serial->close();
        ui->connect_button->setText("Open Port");
        ui->port_box->setDisabled(false);
    }
}

void MainWindow::LogicUi(){
    QString filename= "C:/Users/Felipe Diaz/Documents/parcial_final/rojo.png";
    QString filename2= "C:/Users/Felipe Diaz/Documents/parcial_final/verde.png";
    QString filename3= "C:/Users/Felipe Diaz/Documents/parcial_final/amarillo.png";
    QPixmap rojo;
    QPixmap verde;
    QPixmap amarillo;
    verde.load(filename2);
    amarillo.load(filename3);
    rojo.load(filename);
    rojo.scaled(ui->luces1->size(),Qt::KeepAspectRatio);
    verde.scaled(ui->luces1->size(),Qt::KeepAspectRatio);
    amarillo.scaled(ui->luces1->size(),Qt::KeepAspectRatio);
    //ui->luces1->setMask(pixmap.mask());
    if (sem1=='V'){
        ui->luces1->setPixmap(verde);
        ui->luces2->setPixmap(rojo);
        ui->luces3->setPixmap(rojo);
        ui->luces4->setPixmap(rojo);
    }else if (sem1=='R'){
        ui->luces1->setPixmap(rojo);
    }else if (sem1=='Y'){
        ui->luces1->setPixmap(amarillo);
        ui->luces2->setPixmap(amarillo);
        ui->luces3->setPixmap(amarillo);
        ui->luces4->setPixmap(amarillo);
    }
    if (sem2=='V'){
        ui->luces1->setPixmap(rojo);
        ui->luces2->setPixmap(verde);
        ui->luces3->setPixmap(rojo);
        ui->luces4->setPixmap(verde);
    }else if (sem2=='R'){
        ui->luces2->setPixmap(rojo);
        ui->luces4->setPixmap(rojo);
    }else if (sem2=='Y'){
        ui->luces1->setPixmap(amarillo);
        ui->luces2->setPixmap(amarillo);
        ui->luces3->setPixmap(amarillo);
        ui->luces4->setPixmap(amarillo);
    }
    if (sem3=='V'){
        ui->luces1->setPixmap(rojo);
        ui->luces2->setPixmap(rojo);
        ui->luces3->setPixmap(verde);
        ui->luces4->setPixmap(rojo);
    }else if (sem3=='R'){
        ui->luces3->setPixmap(rojo);
    }else if (sem3=='Y'){
        ui->luces1->setPixmap(amarillo);
        ui->luces2->setPixmap(amarillo);
        ui->luces3->setPixmap(amarillo);
        ui->luces4->setPixmap(amarillo);
    }
    if (sem4=='V'){
        ui->luces1->setPixmap(rojo);
        ui->luces2->setPixmap(verde);
        ui->luces3->setPixmap(rojo);
        ui->luces4->setPixmap(verde);
    }else if (sem4=='R'){
        ui->luces2->setPixmap(rojo);
        ui->luces4->setPixmap(rojo);
    }else if (sem4=='Y'){
        ui->luces1->setPixmap(amarillo);
        ui->luces2->setPixmap(amarillo);
        ui->luces3->setPixmap(amarillo);
        ui->luces4->setPixmap(amarillo);
    }
}
void MainWindow::on_connect_button_clicked()
{
    ui->connect_button->setCheckable(true);
    QString puerto =  ui->port_box->currentText();
    if(ui->connect_button->isChecked()){
        OpenSerialPort(puerto);
    }else{
        CloseSerial();
        flag_port = false;
        qDebug()<<"Puerto Cerrado";
    }
}
