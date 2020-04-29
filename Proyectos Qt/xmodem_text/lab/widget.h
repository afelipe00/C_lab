#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QVector>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void readSerial();
    void on_pushButton_2_clicked();
    bool send(const QString &filePath);
    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    int c;
    QSerialPort *m_serial = nullptr;
    QSerialPort *m_serial1 = nullptr;
    void openSerialPort(QString p);
    QVector<double> x;
    QVector<double> y;
    QVector<double> z;
    QVector<double> w;
    void setupPlot();
    QByteArray xmodem_rx;
    quint16 numpacket=1;
    void writeRawData(QString filepath, QByteArray datos);
    int calculateCRC(char *ptr, int count);
};
#endif // WIDGET_H
