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
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *le_DB;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_buscarDB;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lb_cantTablas;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *buscarTablas)
    {
        if (buscarTablas->objectName().isEmpty())
            buscarTablas->setObjectName(QString::fromUtf8("buscarTablas"));
        buscarTablas->resize(240, 134);
        verticalLayout_2 = new QVBoxLayout(buscarTablas);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
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

        le_DB = new QLineEdit(buscarTablas);
        le_DB->setObjectName(QString::fromUtf8("le_DB"));

        verticalLayout->addWidget(le_DB);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_buscarDB = new QPushButton(buscarTablas);
        pb_buscarDB->setObjectName(QString::fromUtf8("pb_buscarDB"));
        pb_buscarDB->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_buscarDB->setIcon(icon);
        pb_buscarDB->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pb_buscarDB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        lb_cantTablas = new QLabel(buscarTablas);
        lb_cantTablas->setObjectName(QString::fromUtf8("lb_cantTablas"));

        horizontalLayout_3->addWidget(lb_cantTablas);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(buscarTablas);

        QMetaObject::connectSlotsByName(buscarTablas);
    } // setupUi

    void retranslateUi(QWidget *buscarTablas)
    {
        buscarTablas->setWindowTitle(QApplication::translate("buscarTablas", "Form", nullptr));
        label->setText(QApplication::translate("buscarTablas", "Base de Datos", nullptr));
        pb_buscarDB->setText(QString());
        lb_cantTablas->setText(QApplication::translate("buscarTablas", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buscarTablas: public Ui_buscarTablas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARTABLAS_H
