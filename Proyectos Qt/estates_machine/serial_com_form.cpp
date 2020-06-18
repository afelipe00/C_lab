#include "serial_com_form.h"
#include "ui_serial_com_form.h"
#include "thread_serial.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

Serial_com_form::Serial_com_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serial_com_form)
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
    m_threadserial = new thread_serial(this);
    connect(m_threadserial, &thread_serial::datorecibido,[&](int n){

    });
    m_serial = new QSerialPort(this);
    CreateUi();
}

Serial_com_form::~Serial_com_form()
{
    delete ui;
}

void Serial_com_form::CreateUi(){
    setWindowTitle(tr("Ports COM"));
     ui->connect_button->setCheckable(false);

}

void Serial_com_form::on_connect_button_clicked()
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

void Serial_com_form::OpenSerialPort(QString port){
    qDebug()<<"Puerto abierto";
    disconnect(m_serial,SIGNAL(readyRead()),this, SLOT(ModeSerial()));
    m_serial->setPortName(port);
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_serial,SIGNAL(readyRead()),this, SLOT(ModeSerial()));
    qDebug()<< "slot";
    if(m_serial->open(QIODevice::ReadWrite)){
        ui->connect_button->setText("Close Port");
        ui->port_box->setDisabled(true);
    }else{
        QMessageBox::critical(this,tr("Error"), m_serial->errorString());
    }
}

void Serial_com_form::ModeSerial(){
    QByteArray serialData = m_serial->readAll();
    if(serialData.size()>1){
        if (mode=='n'){
            qDebug() << "sleep";
        }else if(mode=='w'){
            if(serialData.at(0) == 'G' && serialData.at(1) == 'o' && flag_port == false){
                 WriteSerial();
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



void Serial_com_form::ReadSerial(QByteArray serialData){
    qDebug() << "mode read";
    m_serial->write("Go");
    unsigned char checked = 0;
    QByteArray check = 0;
    datos.clear();
    qDebug()<<"datos Recibidos: "<<serialData;
    if(serialData.size() > 1){
        if (serialData.at(0)==0x01 && serialData.at(1)==0x01){
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
}

void Serial_com_form::WriteSerial(){
    qDebug() << "mode write";
    QByteArray serialData = m_serial->readAll();
    if(serialData.at(0)== 0x00 && serialData.at(1)== 0x68){

    }

}

unsigned char Serial_com_form::checkSum(QByteArray  *b)
{
    qint16 b_len = b->length();

    unsigned char Xor = 0;

    for ( int i = 0 ; i < b_len ; i ++ )
    {
       Xor = Xor ^ b->at(i);
    }
    return  Xor;
}

void Serial_com_form::CloseSerial(){
    if(m_serial->isOpen()){
        m_serial->close();
        ui->connect_button->setText("Open Port");
        ui->port_box->setDisabled(false);
    }
}


void Serial_com_form::on_write_button_clicked()
{
    mode = 'w';
}

void Serial_com_form::on_read_button_clicked()
{
    mode = 'r';
}
