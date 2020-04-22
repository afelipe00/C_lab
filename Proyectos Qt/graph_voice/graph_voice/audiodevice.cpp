#include "audiodevice.h"
#include<QtCore/QtDebug>

using namespace QtDataVisualization;

static const int resolution = 8;
static const int rowsize = 800;
static const int rowcount = 7;
static const int middlerow = rowcount / 2;

Audiodevice::Audiodevice(QBarDataProxy *proxy, QObject *parent)
    :QIODevice(parent)
    ,m_proxy(proxy)
    ,m_array(new QBarDataArray)
{
    m_array->reserve(rowcount);
    for (int i = 0; i < rowcount;i++)
        m_array->append(new QBarDataRow(rowsize));
    qDebug() << "Total of" << (rowsize *rowcount)<< "items in the array.";
}

qint64 Audiodevice::readData(char *data, qint64 maxSize){
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
}

qint64 Audiodevice::writeData(const char *data, qint64 maxSize){
    int newDataSize = maxSize / resolution;
    int newDataStartIndex = qMax(0, (newDataSize - rowsize));

    if (!newDataStartIndex) {
        for (int i = 0; i <= middlerow; i++) {
            QBarDataItem *srcPos = m_array->at(i)->data();
            QBarDataItem *dstPos = srcPos + newDataSize;
            memmove((void *)dstPos, (void *)srcPos, (rowsize - newDataSize) * sizeof(QBarDataItem));
        }
    }

    int index = 0;
    for (int i = newDataSize - 1; i >= newDataStartIndex; i--) {
        // Add 0.01 to the value to avoid gaps in the graph (i.e. zero height bars).
        // Also, scale to 0...100
        float value = float(quint8(data[resolution * i]) - 128) / 1.28f + 0.01f;
        (*m_array->at(middlerow))[index].setValue(value);
        // Insert a fractional value into front half of the rows.
        for (int j = 1; j <= middlerow; j++) {
            float fractionalValue = value / float(j + 1);
            (*m_array->at(middlerow - j))[index].setValue(fractionalValue);
        }
        index++;
    }

    m_proxy->resetArray(m_array);

    return maxSize;
}
