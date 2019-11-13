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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_buscarDB;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *layTablas;
    QPushButton *pb_nuevaT;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *bb_aceptar;
    QLabel *lb_cantTablas;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *buscarTablas)
    {
        if (buscarTablas->objectName().isEmpty())
            buscarTablas->setObjectName(QString::fromUtf8("buscarTablas"));
        buscarTablas->resize(241, 172);
        buscarTablas->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"color: white;"));
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

        horizontalLayout_4->addWidget(le_DB);

        pushButton = new QPushButton(buscarTablas);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_buscarDB = new QPushButton(buscarTablas);
        pb_buscarDB->setObjectName(QString::fromUtf8("pb_buscarDB"));
        pb_buscarDB->setMaximumSize(QSize(30, 30));
        pb_buscarDB->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_buscarDB->setIcon(icon);
        pb_buscarDB->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pb_buscarDB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        layTablas = new QVBoxLayout();
        layTablas->setObjectName(QString::fromUtf8("layTablas"));

        verticalLayout->addLayout(layTablas);

        pb_nuevaT = new QPushButton(buscarTablas);
        pb_nuevaT->setObjectName(QString::fromUtf8("pb_nuevaT"));
        pb_nuevaT->setStyleSheet(QString::fromUtf8("color:black;\n"
""));

        verticalLayout->addWidget(pb_nuevaT);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        bb_aceptar = new QDialogButtonBox(buscarTablas);
        bb_aceptar->setObjectName(QString::fromUtf8("bb_aceptar"));
        bb_aceptar->setStyleSheet(QString::fromUtf8("color:black;\n"
""));
        bb_aceptar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(bb_aceptar);

        lb_cantTablas = new QLabel(buscarTablas);
        lb_cantTablas->setObjectName(QString::fromUtf8("lb_cantTablas"));

        horizontalLayout_3->addWidget(lb_cantTablas);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(buscarTablas);

        QMetaObject::connectSlotsByName(buscarTablas);
    } // setupUi

    void retranslateUi(QWidget *buscarTablas)
    {
        buscarTablas->setWindowTitle(QApplication::translate("buscarTablas", "Form", nullptr));
        label->setText(QApplication::translate("buscarTablas", "Base de Datos", nullptr));
        pushButton->setText(QApplication::translate("buscarTablas", "Nueva DB", nullptr));
        pb_buscarDB->setText(QString());
        pb_nuevaT->setText(QApplication::translate("buscarTablas", "Nueva tabla", nullptr));
        lb_cantTablas->setText(QApplication::translate("buscarTablas", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buscarTablas: public Ui_buscarTablas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARTABLAS_H
