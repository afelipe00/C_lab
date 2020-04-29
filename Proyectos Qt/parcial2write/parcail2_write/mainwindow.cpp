#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

//constructor
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
}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//accion menu para save
bool MainWindow::on_action_Save_triggered()
{
    QString Filename = QFileDialog::getSaveFileName(this
                                                    ,"Save File - save as"
                                                    ,"C:/Users/Felipe Diaz/Documents/GitHub/Programas_C/Proyectos Qt/parcial2write"
                                                    ,"MP3 (*.mp3);;JPEG (*.jpg);;Text file (*.txt);;PNG (*.png);;All Files (*.*)");
    if(!Filename.isEmpty())
    {
        currentfile = Filename;
        return saveFile();
    }
    return false;
}

//funcion de guardado
bool MainWindow::saveFile()
{
    QFile file(currentfile);
    if(file.open(QFile::WriteOnly)){
        file.write(ui->plainTextEdit->toPlainText().toUtf8());
        return true;
    }else{
        QMessageBox::warning(this
                             ,"file save"
                             ,tr("cannot write file %1.\nError: %2")
                             .arg(currentfile)
                             .arg(file.error()));
        return false;
    }
}

//funcion verificacion de guardado
bool MainWindow::maybeSave()
{
    if(ui->plainTextEdit->document()->isModified()){
        QMessageBox::StandardButton ret=
                QMessageBox::warning(this,
                                     "jumm"
                                     ,tr("this file has modified")
                                     ,QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if( ret == QMessageBox::Yes){
            return on_action_Save_triggered();
        }else if(ret == QMessageBox::Cancel){
            return  false;
        }
    }
    return true;

}

//accion para abrir archivo
void MainWindow::on_action_Open_file_triggered()
{
    if(maybeSave()){
        QString Filename = QFileDialog::getOpenFileName(this
                                                        ,"editor - openfile"
                                                        ,"C:/Users/Felipe Diaz/Documents/GitHub/Programas_C/Proyectos Qt/parcial2write/"
                                                        ,"All Files (*.*);;JPEG (*.jpg);;Text file (*.txt);;PNG (*.png);;MP3 (*.mp3)");
        if(!Filename.isEmpty()){
            QFile file(Filename);
            QFileInfo extetion = file;
            qDebug()<< "extencion: "<< extetion.suffix();
            if(file.open(QFile::ReadOnly)){
                if (extetion.suffix() == "txt"){
                    ui->plainTextEdit->setPlainText(file.readAll());
                }else if(extetion.suffix() == "jpg"){
                    ui->picture_label->setPixmap((QPixmap)file.readAll());
                }else if(extetion.suffix() == "mp3"){
                    ui->sound_label->setText(file.readAll());
                }

            }else{
                QMessageBox::warning(this
                                     ,"warning"
                                     ,tr("Cannot read file %1. \n Error: %2")
                                     .arg(Filename)
                                     .arg(file.errorString()));
            }
        }
    }
}

//metodo de clicked sobre boton del port
void MainWindow::on_port_button_clicked()
{
    ui->port_button->setCheckable(true);
    QString puerto = ui->port_box->currentText();
    if(ui->port_button->isChecked()){
        openSerialPort(puerto);
    }else{
        closeSerialPort();
    }
}

//metodo para iniciar apertura del puerto
void MainWindow::openSerialPort(QString p)
{
    qDebug()<<"puerto abierto";
    disconnect(m_serial,SIGNAL(readyRead()),this, SLOT(readSerial()));
    m_serial->setPortName(p);
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_serial,SIGNAL(readyRead()),this, SLOT(readSerial()));

    if(m_serial->open(QIODevice::ReadWrite)){
        ui->port_button->setText("Close Port");
        ui->port_box->setDisabled(true);
    }else{
        QMessageBox::critical(this,tr("Error"), m_serial->errorString());
    }

}


void MainWindow::readSerial(){
     QByteArray serialData = m_serial->readAll();
     qDebug()<<serialData.at(0);
     if(serialData.at(0) == 'G' && serialData.at(1) == 'o'){
         writeSerial();
     }
}

void MainWindow::writeSerial(){
    QByteArray data;
    data = ui->plainTextEdit->toPlainText().toUtf8();
    int size = data.size();
    int suma = 0;
    int inicio = 0x01;
    int extention = (int)"txt";
    int check = 0;
    for (int i = 0; i < size - 1 ; i++){
        char packet = data.at(i);
        qDebug() << "paquete"<<packet;
        if(m_serial->isWritable()){
            m_serial->putChar(inicio);
            m_serial->write("txt");
            m_serial->putChar(packet);
            suma = suma + inicio + extention + (int)packet;
            check = size xor suma;
            m_serial->putChar(check);
            num_packet ++;
            qDebug() << "se envio packet" << num_packet;
        }
    }
}

//metodo para cerrar el puerto
void MainWindow::closeSerialPort(){
    if(m_serial->isOpen()){
        m_serial->close();
        ui->port_button->setText("Open Port");
        ui->port_box->setDisabled(false);
    }
}

void MainWindow::on_send_button_clicked()
{
    writeSerial();
}
