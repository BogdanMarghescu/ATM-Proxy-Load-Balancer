/********************************************************************************
** Form generated from reading UI file 'PowerTask.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERTASK_H
#define UI_POWERTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerTask
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Message;
    QSpinBox *operator1;
    QSpinBox *operator2;

    void setupUi(QDialog *PowerTask)
    {
        if (PowerTask->objectName().isEmpty())
            PowerTask->setObjectName(QString::fromUtf8("PowerTask"));
        PowerTask->setWindowModality(Qt::ApplicationModal);
        PowerTask->resize(420, 110);
        buttonBox = new QDialogButtonBox(PowerTask);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 70, 401, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(11);
        buttonBox->setFont(font);
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        layoutWidget = new QWidget(PowerTask);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 401, 49));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Message = new QLabel(layoutWidget);
        Message->setObjectName(QString::fromUtf8("Message"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        Message->setFont(font1);
        Message->setStyleSheet(QString::fromUtf8("border: transparent;\n"
"background-color: transparent;\n"
"color: rgb(21, 200, 8);\n"
"font: 14pt \"Gill Sans MT\";"));
        Message->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(Message);

        operator1 = new QSpinBox(layoutWidget);
        operator1->setObjectName(QString::fromUtf8("operator1"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gill Sans MT"));
        font2.setPointSize(12);
        operator1->setFont(font2);
        operator1->setCursor(QCursor(Qt::PointingHandCursor));
        operator1->setStyleSheet(QString::fromUtf8("padding: 10px;"));
        operator1->setWrapping(false);
        operator1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        operator1->setMaximum(999999999);

        horizontalLayout->addWidget(operator1);

        operator2 = new QSpinBox(layoutWidget);
        operator2->setObjectName(QString::fromUtf8("operator2"));
        operator2->setFont(font2);
        operator2->setCursor(QCursor(Qt::PointingHandCursor));
        operator2->setStyleSheet(QString::fromUtf8("padding: 10px;"));
        operator2->setWrapping(false);
        operator2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        operator2->setMaximum(999999999);

        horizontalLayout->addWidget(operator2);


        retranslateUi(PowerTask);

        QMetaObject::connectSlotsByName(PowerTask);
    } // setupUi

    void retranslateUi(QDialog *PowerTask)
    {
        PowerTask->setWindowTitle(QCoreApplication::translate("PowerTask", "Send PowerTask", nullptr));
        Message->setText(QCoreApplication::translate("PowerTask", "Choose operators:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PowerTask: public Ui_PowerTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERTASK_H
