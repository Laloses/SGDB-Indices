#include "buscartablas.h"
#include "ui_buscartablas.h"
#include "mainwindow.h"

buscarTablas::buscarTablas(QWidget *parent, QSqlDatabase db) :
    QDialog(parent),
    ui(new Ui::buscarTablas)
{
    database=db;
    database.setHostName("localhost");
    database.setPort(3306);
    ui->setupUi(this);
    ui->lb_cantTablas->hide();
    ui->pb_nuevaT->hide();
}

buscarTablas::~buscarTablas()
{
    delete ui;
}

void buscarTablas::clearLay(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLay(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void buscarTablas::on_pb_buscarDB_clicked()
{
    ui->pb_nuevaT->show();
    clearLay(ui->layTablas);
    db=ui->le_DB->text();
    database.setDatabaseName(db);
    if( !database.open("root","") ){
        ui->lb_cantTablas->setText("[Error]: Verifique el nombre.");
        hay=false;
    }
    else{
        hay=true;
        QSqlQuery tablas;
        int cont=0;
        tablas.exec("SHOW TABLES");
        QLabel *lab;
        QPushButton *pb;
        QHBoxLayout *hlay;
        QString nombre;
        while(tablas.next()){
            hlay= new QHBoxLayout;
            lab=new QLabel;
            pb = new QPushButton;
            nombre = tablas.value(0).toString();

            lab->setText(nombre);
            lab->setAlignment(Qt::AlignLeft);
            hlay->addWidget(lab);

            pb->setText("Seleccionar");
            connect(pb,&QPushButton::clicked,[=](){emit seleccionarT(nombre);});

            ui->layTablas->addLayout(hlay);

            cont++;
        }
        ui->lb_cantTablas->setText("Hay "+QString::number(cont)+" tablas");
    }
    ui->lb_cantTablas->show();
    this->update();
}

void buscarTablas::seleccionarT(QString nombre){
    nombre=this->nombre;
    db=ui->le_DB->text();
}

QString buscarTablas::getDB(){
    if(!db.isEmpty() && hay)
        return ui->le_DB->text();
    return "";
}

void buscarTablas::on_bb_aceptar_accepted()
{
    MainWindow *w = new MainWindow(nullptr,db,nombre);
    w->show();
    this->close();
}

void buscarTablas::on_pb_nuevaDB_clicked()
{
    QString nombre = QInputDialog::getText(this,"Ingresa el nombre de la base de datos","Nombre");
    database.setDatabaseName("information_schema");
    database.open();
    QSqlQuery *nueva = new QSqlQuery;
    if( !nueva->exec("CREATE DATABASE "+nombre) ){
        qDebug()<<nueva->lastError().text();
        QMessageBox::information(this,"Error","Error al crear");
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
    tabla->exec("CREATE TABLE "+nombre)

    delete tabla;
}
