/********************************************************************************
** Form generated from reading UI file 'RootTask.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTTASK_H
#define UI_ROOTTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RootTask
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Message;
    QSpinBox *operator1;
    QSpinBox *operator2;

    void setupUi(QDialog *RootTask)
    {
        if (RootTask->objectName().isEmpty())
            RootTask->setObjectName(QString::fromUtf8("RootTask"));
        RootTask->setWindowModality(Qt::ApplicationModal);
        RootTask->resize(420, 110);
        buttonBox = new QDialogButtonBox(RootTask);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 70, 401, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(11);
        buttonBox->setFont(font);
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        layoutWidget = new QWidget(RootTask);
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


        retranslateUi(RootTask);

        QMetaObject::connectSlotsByName(RootTask);
    } // setupUi

    void retranslateUi(QDialog *RootTask)
    {
        RootTask->setWindowTitle(QCoreApplication::translate("RootTask", "Send RootTask", nullptr));
        Message->setText(QCoreApplication::translate("RootTask", "Choose operators:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RootTask: public Ui_RootTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTTASK_H
