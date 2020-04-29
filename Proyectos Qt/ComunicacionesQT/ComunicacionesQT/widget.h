#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void readSerial();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    int contador = 0;
    int c;

    QSerialPort *m_serial = nullptr;
    void openSerialPort(QString p);

};

#endif // WIDGET_H
