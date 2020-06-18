#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPixmap>


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

private:
    Ui::MainWindow *ui;
    //metodos
    void CreateUi();

    void LogicUi();
    void OpenSerialPort(QString port);
    void ReadSerial(QByteArray serialData);
    void WriteSerial();
    void CloseSerial();

    //atributos
    QSerialPort *m_serial = nullptr;
    char mode = 'n';
    bool flag_port = false;

    char sem1;
    char sem2;
    char sem3;
    char sem4;
};
#endif // MAINWINDOW_H
