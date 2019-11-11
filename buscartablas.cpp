#include "buscartablas.h"
#include "ui_buscartablas.h"

buscarTablas::buscarTablas(QWidget *parent, QSqlDatabase db) :
    QWidget(parent),
    ui(new Ui::buscarTablas)
{
    database=db;
    ui->setupUi(this);
    ui->lb_cantTablas->hide();
}

buscarTablas::~buscarTablas()
{
    delete ui;
}

void buscarTablas::on_pb_buscarDB_clicked()
{
    db=ui->le_DB->text();
    database.setHostName("localhost");
    database.setPort(3306);
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
        while(tablas.next()){
            cont++;
        }
        ui->lb_cantTablas->setText("Hay "+QString::number(cont)+" tablas");
    }
    ui->lb_cantTablas->show();
}

QString buscarTablas::getDB(){
    if(!db.isEmpty() && hay)
        return ui->le_DB->text();
    return "";
}
