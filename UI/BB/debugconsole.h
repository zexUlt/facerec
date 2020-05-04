#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QObject>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

namespace Ui {
class DebugConsole;
}

class DebugConsole : public QObject
{
    Q_OBJECT

public:
    explicit DebugConsole(QObject *parent, QString fileName, QPlainTextEdit *editor = nullptr);
    ~DebugConsole();
    void setShowDateTime(bool value);

private:
    QFile *file;
    QPlainTextEdit *m_editor;
    bool m_showDate;

signals:

public slots:
    void log(const QString &value);

};

#endif // DEBUGCONSOLE_H
