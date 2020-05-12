#pragma once
#include <QDialog>
#include "ui_FactorialTask.h"

class FactorialTask : public QDialog
{
	Q_OBJECT

public:
	FactorialTask(QWidget *parent = Q_NULLPTR);
	~FactorialTask();

private:
	Ui::FactorialTask ui;

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

signals:
	void sendOperators(int type, int op1, int op2 = 0);
};
