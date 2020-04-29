#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

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
    void readSerial();
    void on_send_button_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *m_serial = nullptr;
    void openSerialPort(QString p);
    void closeSerialPort();
    bool saveFile();
    bool maybeSave();
    void writeSerial();
    QString currentfile;
    long int num_packet = 0;
};
#endif // MAINWINDOW_H
