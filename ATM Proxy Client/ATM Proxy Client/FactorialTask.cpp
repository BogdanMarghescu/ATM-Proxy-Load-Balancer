#include "FactorialTask.h"

FactorialTask::FactorialTask(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
}

FactorialTask::~FactorialTask() { ; }

void FactorialTask::on_buttonBox_accepted()
{
	emit sendOperators(1, ui.operator1->value());
	this->close();
}

void FactorialTask::on_buttonBox_rejected()
{
	this->close();
}