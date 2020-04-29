#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFileInfo>

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
    bool on_action_Save_triggered();
    void on_action_Open_file_triggered();
    void on_port_button_clicked();
    void modeSerial();
    void on_send_button_clicked();

    void on_receive_button_clicked();

private:
    Ui::MainWindow *ui;
    bool band_w = false;
    bool band_r = false;
    QSerialPort *m_serial = nullptr;
    void openSerialPort(QString p);
    void closeSerialPort();
    bool saveFile();
    void readSerial(QByteArray serialData);
    bool maybeSave();
    void writeSerial();
    QString currentfile;
    QByteArray datos = 0;
    unsigned char checkSum(QByteArray  *b);
    long int num_packet_r = 0;
    long int num_packet_w = 0;
    QFileInfo extetion;
    void mostrarDatos();
    char mode = 'n';//n=none, w=write, r=read
};
#endif // MAINWINDOW_H
