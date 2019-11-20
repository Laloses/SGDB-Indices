/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImportar_Tablas;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tv_indice;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tv_tabla;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_insertar;
    QPushButton *pb_borrar;
    QPushButton *pb_modificar;
    QMenuBar *menubar;
    QMenu *menuDatos;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(577, 341);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow,QMenuBar,QMenu{\n"
"background-color:black;\n"
"color: white;\n"
"}\n"
"QPushButton{\n"
"background:black;\n"
"border: 1px solid red;\n"
"padding:2px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover{\n"
"margin-top:1px;\n"
"}\n"
"QMessageBox::StandarButton,QInputDialog, QDialogButtonBox{\n"
"color:black;\n"
"}\n"
""));
        actionImportar_Tablas = new QAction(MainWindow);
        actionImportar_Tablas->setObjectName(QString::fromUtf8("actionImportar_Tablas"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tv_indice = new QTableWidget(centralwidget);
        tv_indice->setObjectName(QString::fromUtf8("tv_indice"));
        tv_indice->setEnabled(false);
        tv_indice->setMinimumSize(QSize(92, 254));
        tv_indice->setMaximumSize(QSize(92, 16777215));
        tv_indice->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;"));
        tv_indice->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tv_indice);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tv_tabla = new QTableWidget(centralwidget);
        tv_tabla->setObjectName(QString::fromUtf8("tv_tabla"));
        tv_tabla->setMinimumSize(QSize(457, 254));
        tv_tabla->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;"));
        tv_tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tv_tabla->setTabKeyNavigation(false);
        tv_tabla->setProperty("showDropIndicator", QVariant(false));
        tv_tabla->setDragDropOverwriteMode(false);
        tv_tabla->setSelectionMode(QAbstractItemView::NoSelection);
        tv_tabla->setColumnCount(0);

        verticalLayout_2->addWidget(tv_tabla);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_insertar = new QPushButton(centralwidget);
        pb_insertar->setObjectName(QString::fromUtf8("pb_insertar"));

        horizontalLayout_2->addWidget(pb_insertar);

        pb_borrar = new QPushButton(centralwidget);
        pb_borrar->setObjectName(QString::fromUtf8("pb_borrar"));

        horizontalLayout_2->addWidget(pb_borrar);

        pb_modificar = new QPushButton(centralwidget);
        pb_modificar->setObjectName(QString::fromUtf8("pb_modificar"));
        pb_modificar->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pb_modificar);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 577, 21));
        menuDatos = new QMenu(menubar);
        menuDatos->setObjectName(QString::fromUtf8("menuDatos"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuDatos->menuAction());
        menuDatos->addAction(actionImportar_Tablas);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionImportar_Tablas->setText(QApplication::translate("MainWindow", "Importar Tabla", nullptr));
        label->setText(QApplication::translate("MainWindow", "Indices", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Datos", nullptr));
        pb_insertar->setText(QApplication::translate("MainWindow", "Insertar Fila", nullptr));
        pb_borrar->setText(QApplication::translate("MainWindow", "Borra Fila", nullptr));
        pb_modificar->setText(QApplication::translate("MainWindow", "Modificar Fila", nullptr));
        menuDatos->setTitle(QApplication::translate("MainWindow", "Datos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
