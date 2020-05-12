#pragma once
#include <QDialog>
#include "ui_RootTask.h"

class RootTask : public QDialog
{
	Q_OBJECT

public:
	RootTask(QWidget *parent = Q_NULLPTR);
	~RootTask();

private:
	Ui::RootTask ui;

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

signals:
	void sendOperators(int type, int op1, int op2);
};
