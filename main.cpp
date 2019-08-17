#include <QCoreApplication>

#include "version.h"
#include "registry.h"
#include "environment.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Enviroment env;
    env.printEnviromentVariables();
    return a.exec();
}
