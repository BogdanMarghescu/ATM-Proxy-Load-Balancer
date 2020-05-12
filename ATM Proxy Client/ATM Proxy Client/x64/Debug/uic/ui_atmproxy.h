/********************************************************************************
** Form generated from reading UI file 'atmproxy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATMPROXY_H
#define UI_ATMPROXY_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATMproxy
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *UsernameInput;
    QLineEdit *PasswordInput;
    QPushButton *LogIn;
    QPushButton *Create_User;
    QPushButton *Exit;
    QLabel *label;
    QLabel *Logo;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ATMproxy)
    {
        if (ATMproxy->objectName().isEmpty())
            ATMproxy->setObjectName(QString::fromUtf8("ATMproxy"));
        ATMproxy->resize(974, 622);
        ATMproxy->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-repeat: no-repeat;\n"
"background-image: url(:/Resources/images/Resources/images/tech_background.png);\n"
"}\n"
"\n"
"\n"
"QLineEdit:focus{ border-color:#66afe9;}\n"
"\n"
"QLineEdit{\n"
"	color: rgb(21, 138, 8);\n"
"	border-style: transparent ;\n"
"	border-radius: 20px;\n"
"	border-width: 1px;\n"
"	border-color: green;\n"
"	min-width: 10em;\n"
"	padding: 6px;\n"
"}"));
        ATMproxy->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        centralwidget = new QWidget(ATMproxy);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(480, 70, 16, 491));
        line->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 170, 0);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(570, 190, 321, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UsernameInput = new QLineEdit(layoutWidget);
        UsernameInput->setObjectName(QString::fromUtf8("UsernameInput"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(16);
        UsernameInput->setFont(font);
        UsernameInput->setContextMenuPolicy(Qt::DefaultContextMenu);
        UsernameInput->setAutoFillBackground(false);
        UsernameInput->setStyleSheet(QString::fromUtf8(""));
        UsernameInput->setMaxLength(32);
        UsernameInput->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        UsernameInput->setClearButtonEnabled(false);

        verticalLayout->addWidget(UsernameInput);

        PasswordInput = new QLineEdit(layoutWidget);
        PasswordInput->setObjectName(QString::fromUtf8("PasswordInput"));
        PasswordInput->setFont(font);
        PasswordInput->setStyleSheet(QString::fromUtf8(""));
        PasswordInput->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        PasswordInput->setMaxLength(64);
        PasswordInput->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(PasswordInput);

        LogIn = new QPushButton(centralwidget);
        LogIn->setObjectName(QString::fromUtf8("LogIn"));
        LogIn->setGeometry(QRect(610, 370, 241, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        LogIn->setFont(font1);
        LogIn->setCursor(QCursor(Qt::PointingHandCursor));
        LogIn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 75 16pt \"Gill Sans MT\";\n"
"border:1px solid transparent;\n"
"border-radius: 20px;\n"
"color: #fff;\n"
"background-color: #5fc82b;\n"
"border: transparent\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"color: #fff;\n"
"background-color:rgb(21, 138, 8);\n"
"border: transparent\n"
"}\n"
"\n"
""));
        Create_User = new QPushButton(centralwidget);
        Create_User->setObjectName(QString::fromUtf8("Create_User"));
        Create_User->setGeometry(QRect(610, 430, 241, 41));
        Create_User->setFont(font1);
        Create_User->setCursor(QCursor(Qt::PointingHandCursor));
        Create_User->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 75 16pt \"Gill Sans MT\";\n"
"border:1px solid transparent;\n"
"border-radius: 20px;\n"
"color: #fff;\n"
"background-color: #5fc82b;\n"
"border: transparent\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"color: #fff;\n"
"background-color:rgb(21, 138, 8);\n"
"border: transparent\n"
"}\n"
"\n"
""));
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(610, 490, 241, 41));
        Exit->setFont(font1);
        Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Exit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 75 16pt \"Gill Sans MT\";\n"
"border:1px solid transparent;\n"
"border-radius: 20px;\n"
"color: #fff;\n"
"background-color: #5fc82b;\n"
"border: transparent\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"color: #fff;\n"
"background-color:rgb(21, 138, 8);\n"
"border: transparent\n"
"}\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 110, 381, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gill Sans MT"));
        font2.setPointSize(24);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("border: transparent;\n"
"background-color: transparent;\n"
"color: rgb(21, 180, 8);"));
        label->setAlignment(Qt::AlignCenter);
        Logo = new QLabel(centralwidget);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(20, 50, 441, 441));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/Resources/images/Resources/images/ATMproxylogo.png")));
        ATMproxy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ATMproxy);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 974, 21));
        ATMproxy->setMenuBar(menubar);

        retranslateUi(ATMproxy);

        QMetaObject::connectSlotsByName(ATMproxy);
    } // setupUi

    void retranslateUi(QMainWindow *ATMproxy)
    {
        ATMproxy->setWindowTitle(QCoreApplication::translate("ATMproxy", "ATM Proxy", nullptr));
        UsernameInput->setPlaceholderText(QCoreApplication::translate("ATMproxy", "Username", nullptr));
        PasswordInput->setText(QString());
        PasswordInput->setPlaceholderText(QCoreApplication::translate("ATMproxy", "Password", nullptr));
        LogIn->setText(QCoreApplication::translate("ATMproxy", "Log In", nullptr));
        Create_User->setText(QCoreApplication::translate("ATMproxy", "Create New User", nullptr));
        Exit->setText(QCoreApplication::translate("ATMproxy", "Exit", nullptr));
        label->setText(QCoreApplication::translate("ATMproxy", "Welcome to ATM Proxy!", nullptr));
        Logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ATMproxy: public Ui_ATMproxy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATMPROXY_H
