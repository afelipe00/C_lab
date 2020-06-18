#ifndef SERIAL_COM_FORM_H
#define SERIAL_COM_FORM_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFileInfo>

namespace Ui {
class Serial_com_form;
}

class thread_serial;

class Serial_com_form : public QWidget
{
    Q_OBJECT

public:
    explicit Serial_com_form(QWidget *parent = nullptr);
    ~Serial_com_form();

private slots:
    void on_connect_button_clicked();

    void on_write_button_clicked();

    void on_read_button_clicked();

    void ModeSerial();

private:
    Ui::Serial_com_form *ui;
    //metodos
    void CreateUi();

    void OpenSerialPort(QString port);
    void ReadSerial(QByteArray serialData);
    void WriteSerial();
    unsigned char checkSum(QByteArray  *b);
    void CloseSerial();
    //atributos
    QSerialPort *m_serial = nullptr;
    char mode = 'n';
    bool flag_port = false;
    bool flag_check = false;
    QByteArray datos = 0;
    thread_serial *m_threadserial;
};

#endif // SERIAL_COM_FORM_H
