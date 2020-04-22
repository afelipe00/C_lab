#include "mainwindow.h"

#include <QApplication>
#include <QtGui/QGuiApplication>
#include <QtMultimedia/QAudio>
#include <QtDataVisualization>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q3DBars w;
    if(!w.hasContext()){
        qWarning()<< QStringLiteral("asfasdf");
        return  -1;
    }
    w.setFlags(w.flags()^ Qt::FramelessWindowHint);
    w.resize(800,500);
    w.setTitle("lets fucking go");
    w.show();
    MainWindow mainwindow(&w);
    return a.exec();
}
