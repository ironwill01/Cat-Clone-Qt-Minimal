#include <Cat.hpp>
#include <Flags.hpp>
#include <QFile>
#include <QFile>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <qlogging.h>
#include <qnamespace.h>
#include <qstringconverter_base.h>

std::unique_ptr<QFile> getFile(const QString & path) {
    if(!QFile::exists(path)) {
        qWarning() << "Your file was not found !";
        return nullptr;
    }

    std::unique_ptr<QFile> fileptr(new QFile(path));
    return fileptr;
}

void catFile(CLIOptions & options) {
    if(auto file = getFile(options.filePath)) {
        if(!readFile(*file , options)) {
            qWarning() << "Error : File you passed either was not readable or found exiting ...";
        }
    }        
};

bool readFile(QFile &file, CLIOptions &options) {
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Error: Cannot open file" << file.fileName() << ":" << file.errorString();
        return false;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);

    qint64 lineNumber = 1;

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (options.showLines) {
            line = QString("%1-%2").arg(lineNumber, 4).arg(line);
        }

        if (options.colorWords && !options.wordToColor.isEmpty()) {
            QString colored = "\033[31m" + options.wordToColor + "\033[0m";  // Red highlight
            line.replace(options.wordToColor, colored, Qt::CaseSensitive);
        }

        if (options.removeChars && !options.wordToRemove.isEmpty()) {
            line.remove(options.wordToRemove, Qt::CaseInsensitive);
        }

        qInfo().noquote() << line;

        ++lineNumber;
    }

    file.close();
    return true;
}