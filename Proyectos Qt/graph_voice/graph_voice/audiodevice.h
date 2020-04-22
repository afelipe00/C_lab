#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <QtDataVisualization/qbardataproxy.h>
#include <QtCore/QIODevice>

using namespace QtDataVisualization;

class Audiodevice : public QIODevice
{
    Q_OBJECT
public:
    explicit Audiodevice(QBarDataProxy *proxy, QObject *parent = 0);

protected:
    qint64 readData(char *data, qint64 maxSize);
    qint64 writeData(const char *data, qint64 maxSize);

private:
    //! [0]
    QBarDataProxy *m_proxy;
    QBarDataArray *m_array;
    //! [0]
};

#endif // AUDIODEVICE_H
