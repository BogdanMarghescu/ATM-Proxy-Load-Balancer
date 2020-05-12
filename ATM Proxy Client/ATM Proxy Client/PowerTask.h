#pragma once
#include <QDialog>
#include "ui_PowerTask.h"

class PowerTask : public QDialog
{
	Q_OBJECT

public:
	PowerTask(QWidget *parent = Q_NULLPTR);
	~PowerTask();

private:
	Ui::PowerTask ui;

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

signals:
	void sendOperators(int type, int op1, int op2);
};
