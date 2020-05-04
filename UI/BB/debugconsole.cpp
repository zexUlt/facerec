#include "debugconsole.h"

#include <QDebug>


DebugConsole::DebugConsole(QObject *parent, QString fileName, QPlainTextEdit *editor) :
    QObject(parent)
{
    m_editor = editor;
    m_showDate = true;
    if (!fileName.isEmpty()) {
        file = new QFile;
        file->setFileName(fileName);
        file->open(QIODevice::Append | QIODevice::Text);
    }
}

void DebugConsole::log(const QString &value) {
    QString text = value;// + "";
    if (m_showDate){
        text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text + "\n";
    }

    QTextStream out(file);
    out.setCodec("UTF-8");

    if (file != 0) {
        out << text;
    }

    if (m_editor != 0){
        m_editor->appendPlainText(text);
    }
}


void DebugConsole::setShowDateTime(bool value) {
    m_showDate = value;
}

DebugConsole::~DebugConsole() {
    if (file != 0){
        file->close();
    }
}
