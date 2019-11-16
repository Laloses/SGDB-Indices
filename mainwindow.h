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
    explicit MainWindow(QWidget *parent = nullptr, QSqlDatabase *databse=nullptr, QString db="", QString nombre="");
    ~MainWindow();

private slots:
    void on_actionImportar_Tablas_triggered();

    void on_pb_insertar_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase *database;
    QFile datosImp;
    QString db, nombreT;
    int contIndices;
    void vaciarIndices();
    void vaciarTabla();
    void llenarIndices();
    void llenarTabla();
};

#endif // MAINWINDOW_H
