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

private slots:
    void on_actionImportar_Tablas_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QFile datosImp;
    QString db, nombre;
    int contIndices;
    void vaciarIndices();
    void llenarIndices();
};

#endif // MAINWINDOW_H
