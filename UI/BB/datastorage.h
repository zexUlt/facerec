#include <QString>
#include <QVector>
//#include <QTime>

#pragma once


class DataStorage
{
public:
    explicit DataStorage() = default;

    QVector<QString> getVideoName() const;
    void addVideoName(QString _videoName);
    bool removeVideoNameFromStorage(QString _videoName);

    QString getOutputPath() const;
    void setOutputPath(QString _outputPath);

private:
    static QVector<QString> videoName;
    static QString outputPath;
};

