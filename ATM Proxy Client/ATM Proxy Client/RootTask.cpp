#include "RootTask.h"

RootTask::RootTask(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
}

RootTask::~RootTask() { ; }

void RootTask::on_buttonBox_accepted()
{
	emit sendOperators(3, ui.operator1->value(), ui.operator2->value());
	this->close();
}

void RootTask::on_buttonBox_rejected()
{
	this->close();
}