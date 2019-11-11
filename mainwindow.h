#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include "buscartablas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionImportar_Tablas_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QFile datosImp;
    QString db;
    void setDB();
};

#endif // MAINWINDOW_H
