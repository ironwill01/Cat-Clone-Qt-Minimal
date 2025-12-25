#include <QCoreApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <Cat.hpp>
#include <Flags.hpp>
#include <qlogging.h>

int main(int argc , char ** argv) {

    if(argc < 2) {
        qInfo() << "Usage : cat [options 1] [options 2] [options ...] <FilePath>";
        exit(1);
    }

    QCoreApplication app(argc , argv);
    std::unique_ptr<QCommandLineParser> parser = flagsInit(app);
    std::unique_ptr<CLIOptions> options = optionsInit(*parser);

    catFile(*options);
    
    return 0;
}