#pragma once
#include <QWidget>
#include <QtWidgets/QMainWindow>
#include <QFileInfo>
#include <QUrl>
#include <QDesktopServices>
#include "ui_mainmenuatmproxy.h"
#include "InfoTimer.h"
#include "ReplyThread.h"
#include "FactorialTask.h"
#include "PowerTask.h"
#include "RootTask.h"
using namespace std;

class MainMenuATMproxy : public QMainWindow
{
	Q_OBJECT

public:
	MainMenuATMproxy(QMainWindow*parent = Q_NULLPTR);

private:
	Ui::MainMenuATMproxy ui;

public slots:
	void openMainMenu(string username);
	void updateTableWidget(ServerList svlist);
	void addCommand(string command);

private slots:
	void sendTask(int type, int op1, int op2 = 0);
	void on_chooseAlgorithmButton_clicked();
	void on_chooseTaskButton_clicked();
	void on_actionOpen_Log_File_triggered();
	void on_actionLog_Out_triggered();
	void on_commandList_itemDoubleClicked(QListWidgetItem* item);

signals:
	void returnLoginMenu();
};