#include "buscartablas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    buscarTablas w;
    w.setWindowTitle("Busqueda de tablas");
    w.show();

    return a.exec();
}
