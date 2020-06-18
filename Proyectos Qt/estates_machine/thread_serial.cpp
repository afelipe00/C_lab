#include "thread_serial.h"

thread_serial::thread_serial(QObject *parent) : QThread(parent)
{

}

void thread_serial::run(){
    emit datorecibido(10);
}
