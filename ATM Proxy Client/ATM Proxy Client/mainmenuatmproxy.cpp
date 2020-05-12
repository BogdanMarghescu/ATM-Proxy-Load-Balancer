#include "mainmenuatmproxy.h"

MainMenuATMproxy::MainMenuATMproxy(QMainWindow* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(size());
}

void MainMenuATMproxy::openMainMenu(string usern)
{
	show();
	string username_string = "Logged in as:  " + usern;
	ui.userLabel->setText(QString::fromStdString(username_string));
	InfoTimer::getInstance(this);
	ReplyThread::getInstance().start();
	ui.algorithmSelect->setCurrentIndex(0);
	ui.taskSelect->setCurrentIndex(0);
	ui.commandList->clear();
	QObject::connect(&(ReplyThread::getInstance()), &ReplyThread::updateTable, this, &MainMenuATMproxy::updateTableWidget);
	QObject::connect(&(ReplyThread::getInstance()), &ReplyThread::addCommand, this, &MainMenuATMproxy::addCommand);
}

void MainMenuATMproxy::on_actionLog_Out_triggered()
{
	InfoTimer::destroyInstance();
	ReplyThread::getInstance().terminate();
	ReplyThread::destroyInstance();
	Client::getInstance().logout();
	this->hide();
	emit returnLoginMenu();
}

void MainMenuATMproxy::on_actionOpen_Log_File_triggered()
{
	QString logFilePath = QFileInfo("ATM_PROXY_Client.log").absoluteFilePath();
	QDesktopServices::openUrl(QUrl::fromLocalFile(logFilePath));
}

void MainMenuATMproxy::on_chooseAlgorithmButton_clicked()
{
	int option = ui.algorithmSelect->currentIndex() + 1;
	Client::getInstance().selectAlgorithm(option);
}

void MainMenuATMproxy::sendTask(int type, int op1, int op2)
{
	Client::getInstance().selectTask(type, op1, op2);
}

void MainMenuATMproxy::on_chooseTaskButton_clicked()
{
	Client& cl = Client::getInstance();
	int type = ui.taskSelect->currentIndex() + 1;
	try
	{
		switch (type)
		{
		case 1:
		{
			FactorialTask task1;
			QObject::connect(&task1, &FactorialTask::sendOperators, this, &MainMenuATMproxy::sendTask);
			task1.exec();
			break;
		}
		case 2:
		{
			PowerTask task2;
			QObject::connect(&task2, &PowerTask::sendOperators, this, &MainMenuATMproxy::sendTask);
			task2.exec();
			break;
		}
		case 3:
		{
			RootTask task3;
			QObject::connect(&task3, &RootTask::sendOperators, this, &MainMenuATMproxy::sendTask);
			task3.exec();
			break;
		}
		default:
		{
			throw new TaskException(1, "Task type not available!\n");
			break;
		}
		}
	}
	catch (TaskException* te)
	{
		QMessageBox::critical(this, "Error", te->getError().c_str());
		delete te;
	}
}

void MainMenuATMproxy::updateTableWidget(ServerList svlist)
{
	svlist.print(ui.serverTable);
}

void MainMenuATMproxy::addCommand(string command)
{
	QString cmd = QString::fromStdString(">> " + command);
	ui.commandList->addItem(cmd);
}

string splitstring(string str, int length)
{
	vector<string> vectstr;
	string result, strcopy(str);
	while (strcopy.size() >= length)
	{
		string part = strcopy.substr(0, length) + "\n";
		vectstr.push_back(part);
		strcopy.erase(0, length);
	}
	vectstr.push_back(strcopy);
	for (auto const& row : vectstr)
		result.append(row);
	return result;
}

void MainMenuATMproxy::on_commandList_itemDoubleClicked(QListWidgetItem* item)
{
	string cmd((item->text()).toStdString());
	cmd.erase(0, 3);
	QString info = QString::fromStdString(splitstring(cmd, 150));
	QMessageBox::information(this, "Command Details", info);
}