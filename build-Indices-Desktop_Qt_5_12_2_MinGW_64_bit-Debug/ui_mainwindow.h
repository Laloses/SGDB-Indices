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
    QTableView *tableView;
    QTableView *tableView_2;
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
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(92, 254));
        tableView->setMaximumSize(QSize(100, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;"));

        horizontalLayout->addWidget(tableView);

        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setMinimumSize(QSize(457, 254));
        tableView_2->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;"));

        horizontalLayout->addWidget(tableView_2);

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
