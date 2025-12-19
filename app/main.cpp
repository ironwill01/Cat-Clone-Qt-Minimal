#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <memory>
#include <QtLogging>
#include <qlogging.h>
#include <qobject.h>

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

std::unique_ptr<QFile> getFile(const QString & path) {

    if(!QFile::exists(path)) {
        qWarning() << "Your file was not found !";
        return nullptr;
    }

    std::unique_ptr<QFile> fileptr(new QFile(path));
    return fileptr;
}

int main(int argc , char ** argv) {

    QCoreApplication app(argc , argv);

    if(app.arguments().count() < 2) {
        qFatal() << "Cant start the app there is no path passed to program !";    
    }

    if(auto file = getFile(app.arguments().at(1))) {
        if(!readFile(*file)) {
            qFatal() << "Error : File you passed either was not readable or found exiting ...";
        }        
    }
}