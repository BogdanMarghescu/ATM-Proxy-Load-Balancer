#include "PowerTask.h"

PowerTask::PowerTask(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
}

PowerTask::~PowerTask() { ; }

void PowerTask::on_buttonBox_accepted()
{
	emit sendOperators(2, ui.operator1->value(), ui.operator2->value());
	this->close();
}

void PowerTask::on_buttonBox_rejected()
{
	this->close();
}