#pragma once
#include <QRegExpValidator>
#include <QtWidgets/QMainWindow>
#include "ui_atmproxy.h"
#include "Client.h"
using namespace std;

class ATMproxy : public QMainWindow
{
	Q_OBJECT

public:
	ATMproxy(QWidget *parent = Q_NULLPTR);
	string getUsername();
	string getPassword();
	bool validCredentials();

public slots:
	void returnLoginMenu();

signals:
	void openMenu(string username);

private:
	Ui::ATMproxy ui;
	void validateLogin();

private slots:
	void on_LogIn_clicked();
	void on_Create_User_clicked();
	void on_Exit_clicked();
};