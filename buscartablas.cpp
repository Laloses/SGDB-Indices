#include "buscartablas.h"
#include "ui_buscartablas.h"
#include "mainwindow.h"

buscarTablas::buscarTablas(QWidget *parent, QSqlDatabase datab) :
    QDialog(parent),
    ui(new Ui::buscarTablas)
{
    this->setWindowTitle("Busqueda de tablas");
    this->setFixedSize(241,150);
    database=datab;
    database.setHostName("localhost");
    database.setPort(3306);
    ui->setupUi(this);
    ui->lb_cantTablas->hide();
    ui->pb_nuevaT->hide();
    ui->sa_tablas->hide();
    nombre.clear();
    this->db.clear();
}

buscarTablas::~buscarTablas()
{
    delete ui;
}

void buscarTablas::clearLay(QLayout *layout) {
    if (layout) {
        QLayoutItem *item;
            while((item = layout->takeAt(0))){
                if (item->layout()) {
                    clearLay(item->layout());
                    delete item->layout();
                }
                if(item->widget())
                    item->widget();
                delete item->widget();
            }
        }
}

void buscarTablas::on_pb_buscarDB_clicked()
{
    select=false;
    hay=false;
    clearLay(ui->layTablas);
    db=ui->le_DB->text();
    database.setDatabaseName(db);
    if( !database.open("root","") ){
        ui->lb_cantTablas->setText("[Error]: Verifique el nombre.");
        qDebug()<<database.lastError().text();
        ui->pb_nuevaT->hide();
        ui->sa_tablas->hide();
        this->setFixedSize(241,200);
        hay=false;
    }
    else{
        hay=true;
        int cont=0;
        QStringList tablas;
        tablas = database.tables();
        QLabel *lab;
        QPushButton *pb;
        QHBoxLayout *hlay;
        QString nombre;
        for(cont=0; cont<tablas.size(); cont++){
            hlay= new QHBoxLayout;
            lab=new QLabel;
            pb = new QPushButton;
            nombre = tablas.at(cont);

            lab->setText(nombre);
            lab->setAlignment(Qt::AlignCenter);
            hlay->addWidget(lab);

            pb->setText("Seleccionar");
            pb->setStyleSheet("background:black; color:white; border:1px solid blue;");
            hlay->addWidget(pb);
            connect(pb,&QPushButton::clicked,[=](){emit seleccionarT(nombre, pb);});

            ui->layTablas->addLayout(hlay);
        }
        ui->lb_cantTablas->setText("Hay "+QString::number(cont)+" tablas");
        ui->sa_tablas->show();
        this->setFixedSize(241,270);
    }
    ui->lb_cantTablas->show();
    this->update();
}

void buscarTablas::seleccionarT(QString nombre, QPushButton *pb){
    db=ui->le_DB->text();
    int cont=0, tam;
    tam=ui->layTablas->layout()->count();
    //No uso w para no pedir mas memoria y guardar el nuevo objeto widget
    //QWidget *w;
    QString estiloSel="background:red; color:black;", estiloNoSel="background:black; color:white; border:1px solid blue;";
    //Desmarcamos los demas
    for(cont=0; cont<tam; cont++){
        //w=ui->layTablas->layout()->itemAt(cont)->layout()->itemAt(1)->widget();
       //Si es difente el boton acutal que selecciono
       if( pb == ui->layTablas->layout()->itemAt(cont)->layout()->itemAt(1)->widget() ){
           if(ui->layTablas->layout()->itemAt(cont)->layout()->itemAt(1)->widget()->styleSheet() == estiloSel){
               ui->layTablas->layout()->itemAt(cont)->layout()->itemAt(1)->widget()->setStyleSheet(estiloNoSel);
           }
           else{
               ui->layTablas->layout()->itemAt(cont)->layout()->itemAt(1)->widget()->setStyleSheet(estiloSel);
               this->nombre=nombre;
           }
       }
       else{
           ui->layTablas->layout()->itemAt(cont)->layout()->itemAt(1)->widget()->setStyleSheet(estiloNoSel);
       }
    }
    qDebug()<<this->nombre;
}

QString buscarTablas::getDB(){
    if(!db.isEmpty() && hay)
        return ui->le_DB->text();
    return "";
}

void buscarTablas::on_bb_aceptar_accepted()
{
    if(!nombre.isEmpty() && !db.isEmpty() ){
        MainWindow *w = new MainWindow(nullptr,database,db,nombre);
        database.close();
        w->show();
        this->close();
    }
    else {
        QMessageBox::information(this,"Error","Por favor seleccione una tabla");
    }
}

void buscarTablas::on_pb_nuevaDB_clicked()
{
    QString nombre = QInputDialog::getText(this,"Ingresa el nombre de la base de datos","Nombre");
    database.setDatabaseName("information_schema");
    database.open("root","");
    QSqlQuery *nueva = new QSqlQuery;
    if( !nueva->exec("CREATE DATABASE "+nombre) ){
        qDebug()<<nueva->lastError().text();
        QMessageBox::information(this,"Error","Error al crear database");
        return;
    }
    QMessageBox::information(this,"Correcto","Creado correctamente");
    database.close();
    clearLay(ui->layTablas);
    ui->le_DB->setText(nombre);
    on_pb_buscarDB_clicked();
    delete nueva;
}

void buscarTablas::on_pb_nuevaT_clicked()
{
    QSqlQuery *tabla = new QSqlQuery;
    QString nombre = QInputDialog::getText(this,"Ingresa el nombre de la tabla","Nombre");
    int cant = QInputDialog::getInt(this,"Columnas","Ingrese la cantidad de atributos",0,0,10);
    int i=0;
    QStringList atributos;
    for(i=0; i<cant; i++){
        atributos[i] = QInputDialog::getText(this,"Atributo","Ingrese el atributo "+QString::number(i)+" [ejemplo: int(5) not null default 5]");
    }
    if (tabla->exec("CREATE TABLE "+nombre+" "+atributos[0]) ){
        for(i=1; i<cant; i++){
            if( !tabla->exec("ALTER TABLE "+nombre+" ADD "+atributos[i]) )
                qDebug()<<tabla->lastError().text();
        }
    }
    else {
        qDebug()<<tabla->lastError().text();
        QMessageBox::information(this,"Error","Error al crear tabla");
    }
    delete tabla;
}

void buscarTablas::on_bb_aceptar_rejected()
{
    this->close();
}
