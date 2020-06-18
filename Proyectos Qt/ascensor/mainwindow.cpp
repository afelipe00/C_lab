#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "on_building.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

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
    CreateUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateUi(){
    setWindowTitle(tr("Ports COM"));
     ui->connect_button->setCheckable(false);
     ui->ascensor_button->setDisabled(true);
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

void MainWindow::OpenSerialPort(QString port){
    qDebug()<<"Puerto abierto";
    ui->ascensor_button->setDisabled(false);
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
            if(serialData.at(0)=='S' && serialData.at(4) =='t'){
                mode = 'w';
            }
        }else if(mode=='w'){
            if(serialData.at(0) == 'G' && serialData.at(1) == 'o' && flag_port == false){
                 WriteSerial();
            }else if(serialData.at(0) == 'r' && serialData.at(1) == 't' && flag_port == false){
                mode = 'r';
            }else {
                serialData.clear();
            }
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
    unsigned char checked = 0;
    QByteArray check = 0;
    datos.clear();
    qDebug()<<"datos Recibidos: "<<serialData;
    if(serialData.size() > 20){
            check = serialData.mid(0,20);
            checked = checkSum(&check);
            qDebug()<<"byte de check: "<<checked;
            if(checked == serialData.at(20)){
                qDebug()<<"paquete correcto";
                datos = serialData;
                flag_check=true;
            }else{
                qDebug()<<"paquete erroneo";
                flag_check=false;
                serialData.clear();
            }
      }
}

void MainWindow::WriteSerial(){
    qDebug() << "mode write";
    unsigned char check;
    datos.clear();
    datos.append(0x01);
    datos.append(actual);
    datos.append(m_building->data_buttons);
    check = checkSum(&m_building->data_buttons);
    datos.append(check);
    datos.append(0x05);
    qDebug()<<datos;
    m_serial->write(datos);
    if(m_serial->readAll() == "ok"){
        mode = 'r';
    }
}

unsigned char MainWindow::checkSum(QByteArray  *b)
{
    qint16 b_len = b->length();

    unsigned char Xor = 0;

    for ( int i = 0 ; i < b_len ; i ++ )
    {
       Xor = Xor ^ b->at(i);
    }
    return  Xor;
}

void MainWindow::CloseSerial(){
    if(m_serial->isOpen()){
        m_serial->close();
        ui->connect_button->setText("Open Port");
        ui->port_box->setDisabled(false);
    }
}

void MainWindow::on_write_button_clicked()
{
    mode = 'w';
}

void MainWindow::on_ascensor_button_clicked()
{
    m_building->show();
}

void MainWindow::on_read_button_clicked()
{
    mode = 'r';
}
