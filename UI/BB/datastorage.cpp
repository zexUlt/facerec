#include "datastorage.h"

#include <QDebug>

QVector<QString> DataStorage::videoName = QVector<QString>();
QString DataStorage::outputPath = QString();


QVector<QString> DataStorage::getVideoName() const
{
    return this->videoName;
}

void DataStorage::addVideoName(QString _videoName)
{
    DataStorage::videoName.push_back(_videoName);
}

bool DataStorage::removeVideoNameFromStorage(QString _videoName)
{
    qDebug() << DataStorage::videoName;
    return DataStorage::videoName.removeOne(_videoName);
}

QString DataStorage::getOutputPath() const
{
    return this->outputPath;
}

void DataStorage::setOutputPath(QString _outputPath)
{
    DataStorage::outputPath = _outputPath;
}
