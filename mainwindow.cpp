#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Indices");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Cuando se importan las tablas
void MainWindow::on_actionImportar_Tablas_triggered()
{
    buscarTablas *bus= new buscarTablas;
    bus->show();
}
