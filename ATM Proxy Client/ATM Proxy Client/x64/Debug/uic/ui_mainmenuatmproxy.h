/********************************************************************************
** Form generated from reading UI file 'mainmenuatmproxy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUATMPROXY_H
#define UI_MAINMENUATMPROXY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuATMproxy
{
public:
    QAction *actionOpen_Log_File;
    QAction *actionLog_Out;
    QWidget *centralwidget;
    QLabel *labelAlgorithm;
    QLabel *labelTask;
    QComboBox *algorithmSelect;
    QPushButton *chooseAlgorithmButton;
    QComboBox *taskSelect;
    QPushButton *chooseTaskButton;
    QLabel *labelCommands;
    QTableWidget *serverTable;
    QLabel *userLabel;
    QListWidget *commandList;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainMenuATMproxy)
    {
        if (MainMenuATMproxy->objectName().isEmpty())
            MainMenuATMproxy->setObjectName(QString::fromUtf8("MainMenuATMproxy"));
        MainMenuATMproxy->resize(1280, 720);
        MainMenuATMproxy->setAutoFillBackground(false);
        MainMenuATMproxy->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-repeat: no-repeat;\n"
"background-image: url(:/Resources/images/Resources/images/tech_background.png);\n"
"}\n"
""));
        actionOpen_Log_File = new QAction(MainMenuATMproxy);
        actionOpen_Log_File->setObjectName(QString::fromUtf8("actionOpen_Log_File"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(11);
        actionOpen_Log_File->setFont(font);
        actionLog_Out = new QAction(MainMenuATMproxy);
        actionLog_Out->setObjectName(QString::fromUtf8("actionLog_Out"));
        actionLog_Out->setFont(font);
        centralwidget = new QWidget(MainMenuATMproxy);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelAlgorithm = new QLabel(centralwidget);
        labelAlgorithm->setObjectName(QString::fromUtf8("labelAlgorithm"));
        labelAlgorithm->setGeometry(QRect(110, 60, 191, 31));
        labelAlgorithm->setStyleSheet(QString::fromUtf8("border: transparent;\n"
"background-color: transparent;\n"
"color: rgb(21, 200, 8);\n"
"font: 18pt \"Gill Sans MT\";"));
        labelAlgorithm->setAlignment(Qt::AlignCenter);
        labelTask = new QLabel(centralwidget);
        labelTask->setObjectName(QString::fromUtf8("labelTask"));
        labelTask->setGeometry(QRect(440, 70, 191, 21));
        labelTask->setStyleSheet(QString::fromUtf8("border: transparent;\n"
"background-color: transparent;\n"
"color: rgb(21, 200, 8);\n"
"font: 18pt \"Gill Sans MT\";"));
        labelTask->setAlignment(Qt::AlignCenter);
        algorithmSelect = new QComboBox(centralwidget);
        algorithmSelect->addItem(QString());
        algorithmSelect->addItem(QString());
        algorithmSelect->addItem(QString());
        algorithmSelect->setObjectName(QString::fromUtf8("algorithmSelect"));
        algorithmSelect->setGeometry(QRect(100, 100, 207, 51));
        QPalette palette;
        QBrush brush(QColor(60, 76, 173, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0.503, 0, 0.503, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(190, 201, 184, 255));
        gradient.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0.503, 0, 0.503, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(190, 201, 184, 255));
        gradient1.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(0.503, 0, 0.503, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(190, 201, 184, 255));
        gradient2.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(60, 76, 173, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0.503, 0, 0.503, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(190, 201, 184, 255));
        gradient3.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush5(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0.503, 0, 0.503, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(190, 201, 184, 255));
        gradient4.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush6(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        QLinearGradient gradient5(0.503, 0, 0.503, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(190, 201, 184, 255));
        gradient5.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush7(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush8(QColor(60, 76, 173, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(0.503, 0, 0.503, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(190, 201, 184, 255));
        gradient6.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush9(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(0.503, 0, 0.503, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(190, 201, 184, 255));
        gradient7.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush10(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        QLinearGradient gradient8(0.503, 0, 0.503, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(190, 201, 184, 255));
        gradient8.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush11(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        QBrush brush12(QColor(60, 76, 173, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        algorithmSelect->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gill Sans MT"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        algorithmSelect->setFont(font1);
        algorithmSelect->setCursor(QCursor(Qt::PointingHandCursor));
        algorithmSelect->setContextMenuPolicy(Qt::DefaultContextMenu);
        algorithmSelect->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font: 16pt \"Gill Sans MT\";\n"
"border: 1px solid #D3D3D3;\n"
"background-color: qlineargradient(spread:pad, x1:0.503, y1:0, x2:0.503, y2:1, stop:0 rgba(190, 201, 184, 255), stop:0.511364 rgba(255, 255, 255, 255));\n"
"border-radius: 16px;\n"
"color: #3C4CAD;\n"
"padding: 1px 15px 1px 10px;\n"
"min-width: 6em;\n"
"}\n"
" \n"
"QComboBox:on {\n"
"background-color: qlineargradient(spread:pad, x1:0.52, y1:0, x2:0.503, y2:1, stop:0 rgba(143, 198, 118, 255), stop:0.511364 rgba(255, 255, 255, 255));\n"
" }\n"
" \n"
"QComboBox::drop-down {\n"
"border: 1px solid #D3D3D3;\n"
"border-radius: 8px;\n"
" }\n"
"\n"
"QComboBox::down-arrow {\n"
"padding: 10px 10px 5px 5px;\n"
" }\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
""));
        algorithmSelect->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        chooseAlgorithmButton = new QPushButton(centralwidget);
        chooseAlgorithmButton->setObjectName(QString::fromUtf8("chooseAlgorithmButton"));
        chooseAlgorithmButton->setGeometry(QRect(130, 160, 151, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gill Sans MT"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        chooseAlgorithmButton->setFont(font2);
        chooseAlgorithmButton->setCursor(QCursor(Qt::PointingHandCursor));
        chooseAlgorithmButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 75 16pt \"Gill Sans MT\";\n"
"border:1px transparent;\n"
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
        taskSelect = new QComboBox(centralwidget);
        taskSelect->addItem(QString());
        taskSelect->addItem(QString());
        taskSelect->addItem(QString());
        taskSelect->setObjectName(QString::fromUtf8("taskSelect"));
        taskSelect->setGeometry(QRect(430, 100, 207, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient9(0.503, 0, 0.503, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(190, 201, 184, 255));
        gradient9.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush13(gradient9);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient10(0.503, 0, 0.503, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(190, 201, 184, 255));
        gradient10.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush14(gradient10);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush14);
        QLinearGradient gradient11(0.503, 0, 0.503, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(190, 201, 184, 255));
        gradient11.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush15(gradient11);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush15);
        QBrush brush16(QColor(60, 76, 173, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient12(0.503, 0, 0.503, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(190, 201, 184, 255));
        gradient12.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush17(gradient12);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient13(0.503, 0, 0.503, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(190, 201, 184, 255));
        gradient13.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush18(gradient13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush18);
        QLinearGradient gradient14(0.503, 0, 0.503, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(190, 201, 184, 255));
        gradient14.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush19(gradient14);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush19);
        QBrush brush20(QColor(60, 76, 173, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush20);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient15(0.503, 0, 0.503, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(190, 201, 184, 255));
        gradient15.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush21(gradient15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient16(0.503, 0, 0.503, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(190, 201, 184, 255));
        gradient16.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush22(gradient16);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        QLinearGradient gradient17(0.503, 0, 0.503, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(190, 201, 184, 255));
        gradient17.setColorAt(0.511364, QColor(255, 255, 255, 255));
        QBrush brush23(gradient17);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        QBrush brush24(QColor(60, 76, 173, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush24);
#endif
        taskSelect->setPalette(palette1);
        taskSelect->setFont(font1);
        taskSelect->setCursor(QCursor(Qt::PointingHandCursor));
        taskSelect->setContextMenuPolicy(Qt::DefaultContextMenu);
        taskSelect->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font: 16pt \"Gill Sans MT\";\n"
"border: 1px solid #D3D3D3;\n"
"background-color: qlineargradient(spread:pad, x1:0.503, y1:0, x2:0.503, y2:1, stop:0 rgba(190, 201, 184, 255), stop:0.511364 rgba(255, 255, 255, 255));\n"
"border-radius: 16px;\n"
"color: #3C4CAD;\n"
"padding: 1px 15px 1px 10px;\n"
"min-width: 6em;\n"
"}\n"
" \n"
"QComboBox:on {\n"
"background-color: qlineargradient(spread:pad, x1:0.52, y1:0, x2:0.503, y2:1, stop:0 rgba(143, 198, 118, 255), stop:0.511364 rgba(255, 255, 255, 255));\n"
" }\n"
" \n"
"QComboBox::drop-down {\n"
"border: 1px solid #D3D3D3;\n"
"border-radius: 8px;\n"
" }\n"
"\n"
"QComboBox::down-arrow {\n"
"padding: 10px 10px 5px 5px;\n"
" }\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
""));
        taskSelect->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        chooseTaskButton = new QPushButton(centralwidget);
        chooseTaskButton->setObjectName(QString::fromUtf8("chooseTaskButton"));
        chooseTaskButton->setGeometry(QRect(460, 160, 151, 41));
        chooseTaskButton->setFont(font2);
        chooseTaskButton->setCursor(QCursor(Qt::PointingHandCursor));
        chooseTaskButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 75 16pt \"Gill Sans MT\";\n"
"border:1px transparent;\n"
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
        labelCommands = new QLabel(centralwidget);
        labelCommands->setObjectName(QString::fromUtf8("labelCommands"));
        labelCommands->setGeometry(QRect(750, 10, 521, 21));
        labelCommands->setStyleSheet(QString::fromUtf8("border: transparent;\n"
"background-color: transparent;\n"
"color: rgb(21, 200, 8);\n"
"font: 18pt \"Gill Sans MT\";"));
        labelCommands->setAlignment(Qt::AlignCenter);
        serverTable = new QTableWidget(centralwidget);
        if (serverTable->columnCount() < 4)
            serverTable->setColumnCount(4);
        QBrush brush25(QColor(20, 140, 10, 255));
        brush25.setStyle(Qt::SolidPattern);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Gill Sans MT"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font3);
        __qtablewidgetitem->setForeground(brush25);
        serverTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Gill Sans MT"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font4);
        __qtablewidgetitem1->setForeground(brush25);
        serverTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font4);
        __qtablewidgetitem2->setForeground(brush25);
        serverTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font4);
        __qtablewidgetitem3->setForeground(brush25);
        serverTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        serverTable->setObjectName(QString::fromUtf8("serverTable"));
        serverTable->setGeometry(QRect(80, 240, 601, 401));
        QPalette palette2;
        QBrush brush26(QColor(21, 180, 8, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush26);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush26);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush26);
        QBrush brush27(QColor(0, 209, 0, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush27);
        QBrush brush28(QColor(65, 197, 0, 128));
        brush28.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush28);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush26);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush26);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush26);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush27);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush28);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush26);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush26);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush26);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush27);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush28);
#endif
        serverTable->setPalette(palette2);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Gill Sans MT"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        serverTable->setFont(font5);
        serverTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        serverTable->setFocusPolicy(Qt::StrongFocus);
        serverTable->setContextMenuPolicy(Qt::NoContextMenu);
        serverTable->setAutoFillBackground(false);
        serverTable->setStyleSheet(QString::fromUtf8("color: rgb(21, 180, 8);\n"
"hover {background-color: #f5f5f5;}\n"
"\n"
"QHeaderView::section { border-bottom: 1px solid gray; }\n"
""));
        serverTable->setFrameShape(QFrame::Box);
        serverTable->setFrameShadow(QFrame::Plain);
        serverTable->setLineWidth(1);
        serverTable->setMidLineWidth(1);
        serverTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        serverTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        serverTable->setAutoScrollMargin(20);
        serverTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        serverTable->setDragDropOverwriteMode(false);
        serverTable->setSelectionMode(QAbstractItemView::NoSelection);
        serverTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        serverTable->setCornerButtonEnabled(false);
        serverTable->setRowCount(0);
        serverTable->horizontalHeader()->setCascadingSectionResizes(false);
        serverTable->horizontalHeader()->setMinimumSectionSize(40);
        serverTable->horizontalHeader()->setDefaultSectionSize(145);
        serverTable->horizontalHeader()->setHighlightSections(true);
        serverTable->horizontalHeader()->setStretchLastSection(true);
        serverTable->verticalHeader()->setMinimumSectionSize(30);
        serverTable->verticalHeader()->setDefaultSectionSize(40);
        serverTable->verticalHeader()->setStretchLastSection(false);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(20, 10, 331, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Gill Sans MT"));
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        userLabel->setFont(font6);
        userLabel->setStyleSheet(QString::fromUtf8("border: transparent;\n"
"background-color: transparent;\n"
"color: rgb(21, 200, 8);\n"
"font: 14pt \"Gill Sans MT\";"));
        userLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        commandList = new QListWidget(centralwidget);
        commandList->setObjectName(QString::fromUtf8("commandList"));
        commandList->setGeometry(QRect(750, 40, 521, 601));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Gill Sans MT"));
        font7.setPointSize(12);
        commandList->setFont(font7);
        commandList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        commandList->setStyleSheet(QString::fromUtf8("color: rgb(20, 120, 10);\n"
"hover {background-color: #f5f5f5;}"));
        commandList->setFrameShape(QFrame::Box);
        commandList->setFrameShadow(QFrame::Sunken);
        commandList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        commandList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        MainMenuATMproxy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenuATMproxy);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        MainMenuATMproxy->setMenuBar(menubar);
        toolBar = new QToolBar(MainMenuATMproxy);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setFont(font7);
        toolBar->setCursor(QCursor(Qt::PointingHandCursor));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(24, 24));
        toolBar->setFloatable(true);
        MainMenuATMproxy->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionOpen_Log_File);
        toolBar->addSeparator();
        toolBar->addAction(actionLog_Out);
        toolBar->addSeparator();

        retranslateUi(MainMenuATMproxy);

        QMetaObject::connectSlotsByName(MainMenuATMproxy);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenuATMproxy)
    {
        MainMenuATMproxy->setWindowTitle(QCoreApplication::translate("MainMenuATMproxy", "ATM Proxy", nullptr));
        actionOpen_Log_File->setText(QCoreApplication::translate("MainMenuATMproxy", "Open Log File", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_Log_File->setShortcut(QCoreApplication::translate("MainMenuATMproxy", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLog_Out->setText(QCoreApplication::translate("MainMenuATMproxy", "Log Out", nullptr));
#if QT_CONFIG(shortcut)
        actionLog_Out->setShortcut(QCoreApplication::translate("MainMenuATMproxy", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        labelAlgorithm->setText(QCoreApplication::translate("MainMenuATMproxy", "Select  Algorithm:", nullptr));
        labelTask->setText(QCoreApplication::translate("MainMenuATMproxy", "Choose  Task:", nullptr));
        algorithmSelect->setItemText(0, QCoreApplication::translate("MainMenuATMproxy", "Round Robin", nullptr));
        algorithmSelect->setItemText(1, QCoreApplication::translate("MainMenuATMproxy", "IP Hashing", nullptr));
        algorithmSelect->setItemText(2, QCoreApplication::translate("MainMenuATMproxy", "Least Connections", nullptr));

        chooseAlgorithmButton->setText(QCoreApplication::translate("MainMenuATMproxy", "Choose", nullptr));
        taskSelect->setItemText(0, QCoreApplication::translate("MainMenuATMproxy", "Factorial", nullptr));
        taskSelect->setItemText(1, QCoreApplication::translate("MainMenuATMproxy", "Power", nullptr));
        taskSelect->setItemText(2, QCoreApplication::translate("MainMenuATMproxy", "Root", nullptr));

        chooseTaskButton->setText(QCoreApplication::translate("MainMenuATMproxy", "Choose", nullptr));
        labelCommands->setText(QCoreApplication::translate("MainMenuATMproxy", "Command List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = serverTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainMenuATMproxy", "IP Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = serverTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainMenuATMproxy", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = serverTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainMenuATMproxy", "Load(%)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = serverTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainMenuATMproxy", "Hits", nullptr));
        userLabel->setText(QCoreApplication::translate("MainMenuATMproxy", "Logged in as: user", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainMenuATMproxy", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuATMproxy: public Ui_MainMenuATMproxy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUATMPROXY_H
