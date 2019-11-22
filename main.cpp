//Programado por Eduardo Martell Hernandez Hernandez AKA Laloses
#include "buscartablas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    buscarTablas *w = new buscarTablas;
    w->database = QSqlDatabase::addDatabase("QMYSQL");
    w->setWindowTitle("Busqueda de tablas");
    w->show();

    return a.exec();
}
