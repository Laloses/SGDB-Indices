#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buscartablas.h"

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QWidget *parent,QSqlDatabase *datab, QString db, QString nombre) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    contIndices=0;
    if(datab->isValid()){
        database=datab;
    }
    else{
        database= new QSqlDatabase;
        database->addDatabase("QMYSQL");
    }
    database->setDatabaseName(db);
    database->setPort(3306);
    database->setHostName("localhost");
    this->nombreT=nombre;
    if (!database->open("root",""))
        qDebug()<<"Error al abrir la base de datos";
    llenarTabla();
    llenarIndices();
}

void MainWindow::llenarTabla(){
    //Vaciamos primero los datos
    vaciarTabla();
    //Llenamos los datos de la tabla
    int tam=0, columnas=0, i,j;
    QSqlQuery *datos = new QSqlQuery(*database);
    QList<QSqlRecord>*filas = new QList<QSqlRecord>;

    datos->exec("SELECT * FROM "+nombreT);
    //Sacamos todos los datos, guardamos cuantas filas y columnas hay
    while (datos->next()) {
        columnas=datos->record().count();
        filas->append(datos->record());
        tam++;
    }
    ui->tv_tabla->setColumnCount(columnas);
    ui->tv_tabla->setRowCount(filas->size());
    QTableWidgetItem* item;
    //Llenamos la tabla
    for(i=0; i<filas->size(); i++){
        for (j=0;j<columnas;j++) {
            //El dato de su fila y el valor de la columna
            item=new QTableWidgetItem(filas->at(i).value(j).toString());
            ui->tv_tabla->setItem(i,j,item);
        }
    }
    //Llenamos el header
    QStringList* header=new QStringList;
    for (i=0;i<1;i++) {
        for (j=0;j<columnas;j++) {
            header->append(filas->at(i).fieldName(j));
        }
        ui->tv_tabla->setHorizontalHeaderLabels(*header);
    }
}

void MainWindow::llenarIndices(){
    contIndices= ui->tv_tabla->model()->rowCount();
    ui->tv_indice->setColumnCount(2);
    ui->tv_indice->setRowCount(contIndices);
    int i=0;
    QTableWidgetItem *item;
    for (i=0;i<contIndices;i++) {
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

void MainWindow::vaciarTabla(){
    int tam=ui->tv_tabla->model()->rowCount();
    //Eliminar filas
    while(tam>1){
        ui->tv_tabla->model()->removeRow(tam-1);
        tam=ui->tv_tabla->model()->rowCount();
    }
    //Eliminar columnas
    tam=ui->tv_tabla->model()->columnCount();
    while(tam>1){
        ui->tv_tabla->model()->removeColumn(tam-1);
        tam=ui->tv_tabla->model()->columnCount();
    }
}

void MainWindow::vaciarIndices(){
    int tam=ui->tv_indice->model()->rowCount();
    //Eliminar filas
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

void MainWindow::on_pb_insertar_clicked()
{
    int i=0;
    QStringList *registro = new QStringList;
    //Ciclo para obtener los datos de los inserts
    for(i=0; i<ui->tv_tabla->model()->columnCount(); i++){
        registro->append(QInputDialog::getText( this,"Igresa los datos","Ingresa los datos para '"+ui->tv_tabla->horizontalHeaderItem(i)->text()+"'") );
    }
    //Insertar los datos
    QSqlQuery* insert = new QSqlQuery(*database);
    QString campos="", datos="";
    //Obtenemos los campos a insertar
    for (i=0;i<ui->tv_tabla->columnCount();i++) {
        if(i<ui->tv_tabla->columnCount()-1)
            campos+=ui->tv_tabla->horizontalHeaderItem(i)->text()+",";
        else {
            campos+=ui->tv_tabla->horizontalHeaderItem(i)->text();
        }
    }
    //Ordenamos los datos a insertar
    for (i=0;i<ui->tv_tabla->columnCount();i++) {
        if(i<ui->tv_tabla->columnCount()-1)
            datos+=registro->at(i)+",";
        else {
            datos+=registro->at(i);
        }
    }
    //hacemos el insert
    if( !insert->exec("INSERT INTO "+this->nombreT+"("+campos+") value ("+datos+")") )
        qDebug()<<insert->lastError().text();
    //Volvemos a llenar la tabla
    qDebug()<<database->lastError().text();
    delete insert;
    llenarTabla();
}
