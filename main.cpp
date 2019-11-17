#include "buscartablas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    buscarTablas w;
    w.database = QSqlDatabase::addDatabase("QMYSQL");
    w.show();

    return a.exec();
}
