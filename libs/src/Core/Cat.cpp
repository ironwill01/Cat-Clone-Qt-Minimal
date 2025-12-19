#include <Cat.hpp>
#include <QFile>
#include <QFile>
#include <QIODevice>
#include <QDir>
#include <QFile>

std::unique_ptr<QFile> getFile(const QString & path) {
    if(!QFile::exists(path)) {
        qWarning() << "Your file was not found !";
        return nullptr;
    }

    std::unique_ptr<QFile> fileptr(new QFile(path));
    return fileptr;
}


void catFile(const QString & data) {
    if(auto file = getFile(data)) {
        if(!readFile(*file)) {
            qFatal() << "Error : File you passed either was not readable or found exiting ...";
        }
    }
};


bool readFile(QFile & file) {
    if(file.open(QIODevice::ReadOnly)) {
        while(!file.atEnd()) {
            qInfo().noquote() << file.readLine();
        }
        
        return true;
    }

    qFatal() << "File is not readable , should be a text or any readable format";
    return false;
}