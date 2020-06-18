#ifndef THREAD_SERIAL_H
#define THREAD_SERIAL_H

#include <QThread>

class thread_serial : public QThread
{
public:
    explicit thread_serial(QObject *parent = nullptr);

signals:
    void datorecibido(int);
protected:
    void run();

};

#endif // THREAD_SERIAL_H
