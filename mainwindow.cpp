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
    contIndices=0;
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
    contIndices= ui->tv_tabla->model()->rowCount();
    ui->tv_indice->setColumnCount(2);
    ui->tv_indice->setRowCount(contIndices);
    int i=0;
    QTableWidgetItem *item;
    for (i=0;i<contIndices;i++) {
        qDebug()<<"hola"<<contIndices;
        //Llenamos la columna llave
        item= new QTableWidgetItem(QString::number(i));
        ui->tv_indice->setItem(i,0,item);
        //Llenamos la columna renglon
        item= new QTableWidgetItem(ui->tv_tabla->model()->index(i,0).data().toString());
        ui->tv_indice->setItem(i,1,item);
    }
    ui->tv_tabla->model()->index(i,0);
    ui->tv_indice->setHorizontalHeaderLabels({tr("LLave"),tr("Renglón")});
    ui->tv_indice->setColumnWidth(0,40);
    ui->tv_indice->setColumnWidth(1,52);
}

void MainWindow::vaciarIndices(){
    int tam=ui->tv_indice->model()->rowCount();
    while(tam>1){
        ui->tv_indice->model()->removeRow(tam-1);
        tam=ui->tv_indice->model()->rowCount();
    }
}

//Cuando se importan las tablas
void MainWindow::on_actionImportar_Tablas_triggered()
{
    buscarTablas *l= new buscarTablas(nullptr,database,db);
    l->show();
    this->close();
}
