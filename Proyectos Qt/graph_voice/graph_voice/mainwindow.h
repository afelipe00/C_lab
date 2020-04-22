#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDataVisualization/q3dbars.h>
#include <QtMultimedia>
#include <QtDataVisualization>

using namespace QtDataVisualization;

class Audiodevice;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Q3DBars *graph, QWidget *parent = nullptr);
    ~MainWindow();
private:
    Q3DBars *m_graph;
    Audiodevice *m_device;
    QAudioInput *m_audioinput;
};
#endif // MAINWINDOW_H
