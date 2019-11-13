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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImportar_Tablas;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tv_indice;
    QTableView *tv_tabla;
    QMenuBar *menubar;
    QMenu *menuDatos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(573, 313);
        MainWindow->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white;"));
        actionImportar_Tablas = new QAction(MainWindow);
        actionImportar_Tablas->setObjectName(QString::fromUtf8("actionImportar_Tablas"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tv_indice = new QTableView(centralwidget);
        tv_indice->setObjectName(QString::fromUtf8("tv_indice"));
        tv_indice->setEnabled(false);
        tv_indice->setMinimumSize(QSize(92, 254));
        tv_indice->setMaximumSize(QSize(100, 16777215));
        tv_indice->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;"));

        horizontalLayout->addWidget(tv_indice);

        tv_tabla = new QTableView(centralwidget);
        tv_tabla->setObjectName(QString::fromUtf8("tv_tabla"));
        tv_tabla->setMinimumSize(QSize(457, 254));
        tv_tabla->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;"));
        tv_tabla->horizontalHeader()->setCascadingSectionResizes(true);

        horizontalLayout->addWidget(tv_tabla);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 573, 21));
        menuDatos = new QMenu(menubar);
        menuDatos->setObjectName(QString::fromUtf8("menuDatos"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDatos->menuAction());
        menuDatos->addAction(actionImportar_Tablas);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionImportar_Tablas->setText(QApplication::translate("MainWindow", "Importar Tablas", nullptr));
        menuDatos->setTitle(QApplication::translate("MainWindow", "Datos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
