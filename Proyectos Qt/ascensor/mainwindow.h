#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "on_building.h"

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFileInfo>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ModeSerial();

    void on_connect_button_clicked();

    void on_write_button_clicked();

    void on_ascensor_button_clicked();

    void on_read_button_clicked();

private:
    Ui::MainWindow *ui;
    //metodos
    void CreateUi();

    void OpenSerialPort(QString port);
    void ReadSerial(QByteArray serialData);
    void WriteSerial();
    unsigned char checkSum(QByteArray  *b);
    void CloseSerial();
    //atributos
    QSerialPort *m_serial = nullptr;
    on_building* m_building = new on_building(this);
    char mode = 'n';
    bool flag_port = false;
    bool flag_check = false;
    QByteArray datos;
    char actual = '1';
};
#endif // MAINWINDOW_H
