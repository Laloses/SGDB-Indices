//Programado por Eduardo Martell Hernandez Hernandez AKA Laloses
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
    database=datab;
    database.setDatabaseName(db);
    database.setPort(3306);
    database.setHostName("localhost");
    this->nombreT=nombre;
    if (!database.open("root",""))
        qDebug()<<"Error al abrir la base de datos";
    llenarTabla();
    llenarIndices();
}

void MainWindow::llenarTabla(){
    //Vaciamos primero los datos
    vaciarTabla();
    //Llenamos los datos de la tabla
    int tam=0, columnas=0, i,j;
    QSqlQuery *datos = new QSqlQuery;
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
    contIndices= ui->tv_tabla->rowCount();
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
    int tam=ui->tv_tabla->rowCount();
    //Eliminar filas
    while(tam>1){
        ui->tv_tabla->removeRow(tam-1);
        tam=ui->tv_tabla->rowCount();
    }
    //Eliminar columnas
    tam=ui->tv_tabla->columnCount();
    while(tam>1){
        ui->tv_tabla->removeColumn(tam-1);
        tam=ui->tv_tabla->columnCount();
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
    buscarTablas *l= new buscarTablas(nullptr,database);
    this->setWindowTitle("Busqueda de tablas");
    l->show();
    this->close();
}

//Busqueda Binaria
int MainWindow::localizarPos(int llave){
    int primero, ultimo,medio;
    primero=0;
    ultimo=contIndices-1;
    medio=(primero+ultimo)/2;
    while (primero<=ultimo){
        //Si es menor
        if (ui->tv_indice->item(medio,0)->text().toInt() < llave){
            primero=medio+1;
        }
        //Si lo encontramos
        else if (ui->tv_indice->item(medio,0)->text().toInt() == llave){
            qDebug()<<" Se encontro la posición "<<medio;
            return medio;
        }
        //Si es mayor
        else {
            ultimo = medio - 1;
        }
        medio = (primero+ultimo)/2;
    }
    if(primero>ultimo){
        qDebug()<<llave<<" hay hueco en "<<primero;
        return primero;
    }
    if(primero<ultimo){
        qDebug()<<llave<<" hay hueco en "<<medio;
        return medio;
    }
    qDebug()<<llave<<" no se encontro";
    return -1;
}

void MainWindow::corrimiento(int lugar){
    //Desde el inicio hasta el final
    //int i=0;
    ui->tv_indice->insertRow(lugar);
    //for(i=lugar; i<contIndices; i++){
    //}
}

bool MainWindow::existeLlave(int llave){
    int i=0;
    for(i=0; i<ui->tv_indice->rowCount(); i++){
        if(ui->tv_indice->item(i,0)->text().toInt() == llave){
            return true;
        }
    }
    return false;
}

int MainWindow::buscarLugarTabla(){
        int lugarTabla = contIndices,i;
        for(i=0; i<ui->tv_tabla->rowCount(); i++){
            //Si encontramos un lugar vacío
            if( ui->tv_tabla->item(i,0)->text().isEmpty() ){
                lugarTabla=i;
                return lugarTabla;
            }
        }
        return -1;
}

void MainWindow::on_pb_insertar_clicked()
{
    int i=0;
    //Pedimos la llave en donde quiere que se ponga
    int miPos = QInputDialog::getInt(this,"Ingresa la llave","Llave para este registro: ",0,0,contIndices*3);

    if(existeLlave(miPos)){
        QMessageBox::warning(this,"Error","Ingresa una llave que no exista en la tabla de indices.");
        return;
    }

    //Ciclo para obtener los datos a guardar
    QStringList *registro = new QStringList;
    for(i=0; i<ui->tv_tabla->columnCount(); i++){
        registro->append(QInputDialog::getText( this,"Igresa los datos","Ingresa los datos para '"+ui->tv_tabla->horizontalHeaderItem(i)->text()+"'") );
    }
    // **************************************************************
    //(Busqueda binaria)

    QTableWidgetItem* item;

    int lugarIndice = localizarPos(miPos);
    if(lugarIndice == -1)
        lugarIndice = contIndices;
    //Hacemos corrimiento
    corrimiento(lugarIndice);
    //Colocamos nuestro indice
    item = new QTableWidgetItem(QString::number(miPos));
    ui->tv_indice->setItem(lugarIndice,0, item);

    // **************************************************************
    //Buscamos un lugar disponible en la tabla

    int hayLugar=buscarLugarTabla();
    QTableWidgetItem* item2;

    //Si hay lugar disponible en la tabla
    if( hayLugar != -1){
        for(i=0; i<ui->tv_tabla->columnCount(); i++){
            item2 = new QTableWidgetItem(registro->at(i));
            ui->tv_tabla->setItem(hayLugar,i,item2);
        }
        //Insertamos el lugar del registro en los indices
        item = new QTableWidgetItem(QString::number(hayLugar+1));
        ui->tv_indice->setItem(lugarIndice,1,item);
    }

    //Si no hay lugar lo insertamos al final
    else{
        ui->tv_tabla->insertRow(contIndices);
        for(i=0; i<ui->tv_tabla->columnCount(); i++){
            item2 = new QTableWidgetItem(registro->at(i));
            ui->tv_tabla->setItem(contIndices,i,item2);
        }
        //Insertamos el lugar del registro en los indices
        item = new QTableWidgetItem(QString::number(contIndices+1));
        ui->tv_indice->setItem(lugarIndice,1,item);
    }

    // **************************************************************
    //Actualizamos nuestra cantidad de indices
    contIndices = ui->tv_indice->model()->rowCount();
}

void MainWindow::on_pb_borrar_clicked()
{
    int i=0;
    //Pedimos la llave en donde quiere borrar
    int miPos = QInputDialog::getInt(this,"Ingresa la llave","Llave a eliminar: ",0,0);

    if(existeLlave(miPos)){
        int llaveB = localizarPos(miPos);
        int posTabla = ui->tv_indice->item(llaveB,1)->text().toInt();
        qDebug()<<"Datos de la tabla "<<posTabla;
        QTableWidgetItem* aux;
        for (i=llaveB;i<contIndices-1;i++) {
            //Movemos la columa header
            aux= new QTableWidgetItem(ui->tv_indice->item(i+1,0)->text());
            ui->tv_indice->setItem(i,0,aux);
            //Movemos la columa filas
            aux = new QTableWidgetItem(ui->tv_indice->item(i+1,1)->text());
            ui->tv_indice->setItem(i,1,aux);
        }
        //Eliminamos la ultima fila de indices
        ui->tv_indice->removeRow(contIndices-1);

        //Vaciamos la fila de la tabla de datos
        for (i=0;i<ui->tv_tabla->columnCount();i++) {
            ui->tv_tabla->item(posTabla-1,i)->setText("");
        }
    }
    //Si no existe el indice
    else{
        QMessageBox::warning(this,"Error","No existe la llave en la tabla de indices.");
        return;
    }
    //Actualizamos el valor
    contIndices=ui->tv_indice->rowCount();
}

void MainWindow::on_pb_modificar_clicked()
{
    int i=0;
    //Pedimos la llave en donde quiere modificar
    int miPos = QInputDialog::getInt(this,"Ingresa la llave","Llave del registro a modificar: ",0,0);

    if(existeLlave(miPos)){
        int posTabla = ui->tv_indice->item(localizarPos(miPos),1)->text().toInt()-1;
        QStringList *datos = new QStringList;
        for(i=0; i<ui->tv_tabla->model()->columnCount(); i++){
            datos->append(QInputDialog::getText( this,"Igresa los datos","Ingresa los datos para '"+ui->tv_tabla->horizontalHeaderItem(i)->text()+"'") );
        }
        for(i=0; i<ui->tv_tabla->columnCount(); i++){
            ui->tv_tabla->item(posTabla,i)->setText(datos->at(i));
        }
    }
    else {
        QMessageBox::warning(this,"Error","No existe la llave en la tabla de indices.");
    }
}
