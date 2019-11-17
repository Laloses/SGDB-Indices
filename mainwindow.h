#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QSqlDatabase databse=QSqlDatabase::database(), QString db="", QString nombre="");
    ~MainWindow();
    QSqlDatabase database;

private slots:
    void on_actionImportar_Tablas_triggered();

    void on_pb_insertar_clicked();

    void on_pb_borrar_clicked();

    void on_pb_modificar_clicked();

private:
    Ui::MainWindow *ui;
    QFile datosImp;
    QString db, nombreT;
    int contIndices;
    void vaciarIndices();
    void vaciarTabla();
    void llenarIndices();
    void llenarTabla();
    void corrimiento(int lugar);
    int localizarPos(int llave);
    int buscarLugarTabla();
    bool existeLlave(int llave);
};

#endif // MAINWINDOW_H
