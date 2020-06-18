#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("graficador de voz");

    Widget w;
    w.show();

    return a.exec();
}
