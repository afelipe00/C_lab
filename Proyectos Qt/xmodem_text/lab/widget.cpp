#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QThread>
#include <QFile>
#include <QEventLoop>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

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
    m_serial1 = new QSerialPort(this);


    QPixmap image("3");
    image = image.scaled(351,381, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(image);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString puerto = ui->comboBox->currentText();
    openSerialPort(puerto);
}

void Widget::on_pushButton_2_clicked()
{
    char texto[2];

    texto[0]='C';
    if(m_serial->isOpen()){
        m_serial->write(texto,1);
    }
}

void Widget::openSerialPort(QString p)
{
    if(m_serial->isOpen()){
        m_serial->close();
        ui->pushButton->setText("Open Port");
    }

    disconnect(m_serial, SIGNAL(readyRead()),this, SLOT(readSerial()));
    m_serial->setPortName(p);
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_serial, SIGNAL(readyRead()),this, SLOT(readSerial()));


    if(m_serial->open(QIODevice::ReadWrite)){
        ui->pushButton->setText("Close Port");
        ui->comboBox->setDisabled(true);
    }else{
        QMessageBox::critical(this,tr("Error"), m_serial->errorString());
    }

}

void Widget::writeRawData(QString filepath, QByteArray datos){

    QFile file("out.txt");
    if(!file.open(QIODevice::WriteOnly /*| QIODevice::Text*/))
        return;

    QTextStream out(&file);
    out << datos;
}

void Widget::readSerial()//funcion de lectura
{
    QByteArray serialData = m_serial->readAll();//se crea serial data recibiendo el dato
    QByteArray temp = serialData.mid(3,128);//se quitan los primeros 2 bits y los ultimos 2 bits
    char txdata[1];// se crea variable de respuesta

    qDebug()<<serialData.size();//se imprime el numero de bytes que tiene serial data

    if(serialData.size() >= 132){// se verifica el tamaño del serialdata
        if(serialData.at(0) == 0x01 && serialData.at(1) == 0x01 &&  numpacket ==0) {//condicion del paquete incial
            //xmodem_rx.append(temp1);
            qDebug()<<"primer paquete";//se imprime lla recepcion del primer paquete
            char crc1 = calculateCRC(temp.data(),128);//se calcula crc
            char *crc = serialData.mid(132,1).data();//quitamos bytes
            int crc2=*crc;//calculamos
            int crc3=crc1;//calculamos

            if(crc2 == crc3){//comparamos que el dato sea correcto
                numpacket=1;//sumamos al numpacket
                serialData.clear();//se mlimpia el serial data
                xmodem_rx.append(temp);//se agrega dato a la lista
                crc=0;//se reinicia el crc
                txdata[0]=0x06;//se crea respuesta valida
                QThread::msleep(100);//se crea tiempo de espera
                m_serial->write(txdata,1);//se evnia la respuesta
            }else if(crc2 != crc3){
                serialData.clear();
                crc=0;
                txdata[0]=0x15;
                QThread::msleep(100);
                m_serial->write(txdata,1);
            }

            if(xmodem_rx.indexOf(0x1A) != -1){
                qDebug() << "final";
                qDebug() << xmodem_rx;
            }
            //segundos paquetes
        }else if(serialData.at(0) == 0x01 && serialData.at(1) == (char)numpacket &&  numpacket != 0){
                qDebug() << "Paquete valido!";
                qDebug() << serialData;
                qDebug()<<"paquete esperado: "<<numpacket;
                qDebug()<<"paquete recibido: "<<(unsigned char) serialData.at(1);

                QByteArray temp2 = serialData.mid(3,128);

                char crc1 = calculateCRC(temp2.data(),128);
                char *crc = serialData.mid(132,1).data();
                int crc2=*crc;
                int crc3=crc1;

                if(crc2 == crc3){
                    numpacket++;
                    crc=0;
                    xmodem_rx.append(temp2);
                    txdata[0] = 0x06;
                    QThread::msleep(100);
                    m_serial->write(txdata,1);
                    ui->progressBar->setValue(numpacket);
                    ui->label_2->setText("<font color='red'>Cargando...</font> ");
                    ui->textEdit->append("\n");
                    ui->textEdit->insertPlainText(QString::number(numpacket));
                    serialData.clear();
                }else if(crc2 != crc3){
                    serialData.clear();
                    crc=0;
                    txdata[0] = 0x15;
                    QThread::msleep(100);
                    m_serial->write(txdata,1);
                }
        }else if(serialData.at(0) == 0x01 && serialData.at(1) != (char)numpacket && numpacket != 0){
                qDebug()<<"Error";
                qDebug()<<serialData;
                qDebug()<<"paquete esperado: "<<numpacket;
                qDebug()<<"paquete recibido: "<<(unsigned char) serialData.at(1);
                serialData.clear();

        }
     }else if(serialData.size() == 1){
        if(serialData.at(0) == 0x04){
                        txdata[0]=0x06;
                        m_serial->write(txdata,1);
                        if(xmodem_rx.indexOf(0x1A) != -1 && xmodem_rx.indexOf(0x1A,2) != -1){
                            int s = xmodem_rx.indexOf(0x1A);
                            xmodem_rx = xmodem_rx.left(s);
                        }
                        ui->progressBar->setValue(100);
                        ui->label_2->setText("<font color='green'>FINALIZADO</font> ");
                        qDebug() << "final archivo";
                        qDebug() << xmodem_rx;
                        writeRawData("prueba.txt",xmodem_rx);
                        xmodem_rx.clear();
                        numpacket = 0;
                }
    }else{
        serialData.clear();
        txdata[0] = 0x15;
        QThread::msleep(100);
        m_serial->write(txdata,1);
    }

}

bool Widget::send(const QString &filePath){
    QFile file(filePath);

        if(!file.open(QFile::ReadOnly))
        {
            qDebug() << "failed to open file" << filePath;
            return false;
        }
    file.size();
    QByteArray serialData = m_serial1->readAll();
    char dataBuffer[128];
    int totalBytesRead = 0;
    while(!file.atEnd())
        {
            int bytesRead = file.read(dataBuffer, 128);
            totalBytesRead += bytesRead;

            for(int i = bytesRead; i < 128; i++)
                dataBuffer[i] = 0xFF; // pad buffer 

            qDebug() << "packet:" << numpacket << "bytes transfered:" << QString().sprintf("%10d / %10d", totalBytesRead, file.size());

            // enviar paketes
            
        }

}

int Widget::calculateCRC(char *ptr, int count)
{
    int  crc;
    char i;
    crc = 0;

    while (--count >= 0)
    {
        crc = crc ^ (int) *ptr++ << 8;
        i = 8;
        do
        {
            if (crc & 0x8000)
                crc = crc << 1 ^ 0x1021;
            else
                crc = crc << 1;
        } while(--i);
    }
    return (crc);
}

void Widget::on_pushButton_3_clicked()
{
    QFile file("C:\\Users\\Felipe Diaz\\Downloads\\lab\\build-lab-Desktop_Qt_5_14_1_MinGW_32_bit-Debug\\out.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"informacion",file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}
