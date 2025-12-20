#include <QCoreApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <Cat.hpp>
#include <Flags.hpp>

int main(int argc , char ** argv) {

    QCoreApplication app(argc , argv);
    std::unique_ptr<QCommandLineParser> parser = flagsInit(app);
    std::unique_ptr<CLIOptions> options = optionsInit(*parser);

    catFile(*options);
    
    return 0;
}