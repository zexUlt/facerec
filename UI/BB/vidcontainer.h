#include <QString>
#include <QTime>

#pragma once


class VidContainer
{
public:
    VidContainer(const QString& name) : videoName(name){};
    QString videoName;
};

