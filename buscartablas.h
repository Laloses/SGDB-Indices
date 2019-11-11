#ifndef BUSCARTABLAS_H
#define BUSCARTABLAS_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class buscarTablas;
}

class buscarTablas : public QWidget
{
    Q_OBJECT

public:
    explicit buscarTablas(QWidget *parent = nullptr);
    ~buscarTablas();

private slots:
    void on_pb_buscarDB_clicked();

private:
    Ui::buscarTablas *ui;
    void verificarDB();
};

#endif // BUSCARTABLAS_H
