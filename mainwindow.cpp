#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buscartablas.h"

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QWidget *parent,QSqlDatabase datab, QString db, QString nombre) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database = datab;
    database.setDatabaseName(db);
    database.setPort(3306);
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    if (!database.open())
        qDebug()<<"Error al abrir la base de datos";

    //Llenamos los datos de la tabla
    QSqlQueryModel *datos = new QSqlQueryModel;
    datos->setQuery("SELECT * FROM "+nombre);
    ui->tv_tabla->setModel(datos);
    llenarIndices();
}

void MainWindow::llenarIndices(){
    int contIndices;
}

//Cuando se importan las tablas
void MainWindow::on_actionImportar_Tablas_triggered()
{
    buscarTablas *l= new buscarTablas(nullptr,database,db);
    l->show();
    this->close();
}
