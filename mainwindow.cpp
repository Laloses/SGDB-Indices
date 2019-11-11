#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database= QSqlDatabase::addDatabase("QMYSQL");
    database.setPort(3306);
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Cuando se importan las tablas
void MainWindow::on_actionImportar_Tablas_triggered()
{
    buscarTablas *l= new buscarTablas(this,database);
    l->show();
    db=l->getDB();
}
