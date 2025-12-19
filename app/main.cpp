#include <QCoreApplication>
#include <QDebug>
#include <Cat.hpp>

int main(int argc , char ** argv) {

    QCoreApplication app(argc , argv);

    if(app.arguments().count() < 2) {
        qFatal() << "Cant start the app there is no path passed to program !";    
    }
    
    catFile(app.arguments().at(1));
}