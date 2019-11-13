#ifndef BUSCARTABLAS_H
#define BUSCARTABLAS_H

#include <QDialog>
#include <QtSql>
#include <QInputDialog>

namespace Ui {
class buscarTablas;
}

class buscarTablas : public QDialog
{
    Q_OBJECT

public:
    explicit buscarTablas(QWidget *parent = nullptr, QSqlDatabase db=QSqlDatabase::database());
    ~buscarTablas();
    QString getDB();
    void seleccionarT(QString nombre);
    void clearLay(QLayout *layout);


private slots:
    void on_pb_buscarDB_clicked();

    void on_bb_aceptar_accepted();

    void on_pb_nuevaDB_clicked();

    void on_pb_nuevaT_clicked();

private:
    Ui::buscarTablas *ui;
    void verificarDB();
    QSqlDatabase database;
    QString db,nombre;
    bool hay;
};

#endif // BUSCARTABLAS_H
