//Programado por Eduardo Martell Hernandez Hernandez AKA Laloses
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
    explicit buscarTablas(QWidget *parent = nullptr, QSqlDatabase datab= QSqlDatabase::database());
    ~buscarTablas();
    QString getDB();
    void seleccionarT(QString nombre,QPushButton* pb);
    void clearLay(QLayout *layout);
    QSqlDatabase database;


private slots:
    void on_pb_buscarDB_clicked();

    void on_bb_aceptar_accepted();

    void on_pb_nuevaDB_clicked();

    void on_pb_nuevaT_clicked();

    void on_bb_aceptar_rejected();

private:
    Ui::buscarTablas *ui;
    void verificarDB();
    QString db,nombre;
    bool hay,select;
};

#endif // BUSCARTABLAS_H
