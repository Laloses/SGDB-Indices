#include "buscartablas.h"
#include "ui_buscartablas.h"

buscarTablas::buscarTablas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buscarTablas)
{
    ui->setupUi(this);
}

buscarTablas::~buscarTablas()
{
    delete ui;
}

void buscarTablas::on_pb_buscarDB_clicked()
{
    QSqlDatabase database;
    database= QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setPort(3306);
    database.setDatabaseName(ui->le_DB->text());
    if( !database.open("root","") ){
        ui->lb_cantTablas->setText("[Error]: Verifique el nombre.");
    }
    else{
        QSqlQuery tablas;
        int cont=0;
        tablas.exec("SHOW TABLES");
        while(tablas.next()){
            cont++;
        }
        ui->lb_cantTablas->setText("Hay "+QString::number(cont)+" tablas");
    }
}
