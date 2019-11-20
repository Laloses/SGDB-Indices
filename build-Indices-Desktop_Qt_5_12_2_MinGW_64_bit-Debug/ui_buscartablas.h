/********************************************************************************
** Form generated from reading UI file 'buscartablas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCARTABLAS_H
#define UI_BUSCARTABLAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buscarTablas
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *le_DB;
    QPushButton *pb_buscarDB;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lb_cantTablas;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line;
    QScrollArea *sa_tablas;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layTablas;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_nuevaT;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_nuevaDB;
    QDialogButtonBox *bb_aceptar;

    void setupUi(QWidget *buscarTablas)
    {
        if (buscarTablas->objectName().isEmpty())
            buscarTablas->setObjectName(QString::fromUtf8("buscarTablas"));
        buscarTablas->resize(241, 272);
        buscarTablas->setMaximumSize(QSize(16777215, 500));
        buscarTablas->setStyleSheet(QString::fromUtf8("#buscarTablas{\n"
"background-color:black;\n"
"color: white;\n"
"}\n"
"QWidget{\n"
"color: white;\n"
"}\n"
"QPushButton{\n"
"border: 1px solid red;\n"
"padding:2px;\n"
"}\n"
"QPushButton:hover{\n"
"margin-top:1px;\n"
"}\n"
"QMessageBox,QDialogButtonBox{\n"
"color:black;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(buscarTablas);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(buscarTablas);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        le_DB = new QLineEdit(buscarTablas);
        le_DB->setObjectName(QString::fromUtf8("le_DB"));
        le_DB->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_4->addWidget(le_DB);

        pb_buscarDB = new QPushButton(buscarTablas);
        pb_buscarDB->setObjectName(QString::fromUtf8("pb_buscarDB"));
        pb_buscarDB->setMaximumSize(QSize(30, 30));
        pb_buscarDB->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_buscarDB->setIcon(icon);
        pb_buscarDB->setIconSize(QSize(25, 25));

        horizontalLayout_4->addWidget(pb_buscarDB);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        lb_cantTablas = new QLabel(buscarTablas);
        lb_cantTablas->setObjectName(QString::fromUtf8("lb_cantTablas"));
        lb_cantTablas->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(lb_cantTablas);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_5);

        line = new QFrame(buscarTablas);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        sa_tablas = new QScrollArea(buscarTablas);
        sa_tablas->setObjectName(QString::fromUtf8("sa_tablas"));
        sa_tablas->setStyleSheet(QString::fromUtf8("background:transparent;"));
        sa_tablas->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 221, 71));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        layTablas = new QVBoxLayout();
        layTablas->setObjectName(QString::fromUtf8("layTablas"));
        layTablas->setContentsMargins(-1, -1, 9, -1);

        verticalLayout_2->addLayout(layTablas);

        sa_tablas->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(sa_tablas);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_nuevaT = new QPushButton(buscarTablas);
        pb_nuevaT->setObjectName(QString::fromUtf8("pb_nuevaT"));
        pb_nuevaT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(pb_nuevaT);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_nuevaDB = new QPushButton(buscarTablas);
        pb_nuevaDB->setObjectName(QString::fromUtf8("pb_nuevaDB"));
        pb_nuevaDB->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pb_nuevaDB);


        verticalLayout->addLayout(horizontalLayout);

        bb_aceptar = new QDialogButtonBox(buscarTablas);
        bb_aceptar->setObjectName(QString::fromUtf8("bb_aceptar"));
        bb_aceptar->setStyleSheet(QString::fromUtf8(""));
        bb_aceptar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(bb_aceptar);


        retranslateUi(buscarTablas);

        QMetaObject::connectSlotsByName(buscarTablas);
    } // setupUi

    void retranslateUi(QWidget *buscarTablas)
    {
        buscarTablas->setWindowTitle(QApplication::translate("buscarTablas", "Form", nullptr));
        label->setText(QApplication::translate("buscarTablas", "Base de Datos", nullptr));
        pb_buscarDB->setText(QString());
        lb_cantTablas->setText(QApplication::translate("buscarTablas", "TextLabel", nullptr));
        pb_nuevaT->setText(QApplication::translate("buscarTablas", "Nueva tabla", nullptr));
        pb_nuevaDB->setText(QApplication::translate("buscarTablas", "Nueva DB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buscarTablas: public Ui_buscarTablas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARTABLAS_H
