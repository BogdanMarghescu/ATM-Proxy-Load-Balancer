#include "ReplyThread.h"

ReplyThread* ReplyThread::instance = nullptr;

ReplyThread& ReplyThread::getInstance(QObject* parent)
{
	if (!ReplyThread::instance)
	{
		ReplyThread::instance = new ReplyThread(parent);
	}
	return *ReplyThread::instance;
}

void ReplyThread::destroyInstance()
{
	if (ReplyThread::instance)
	{
		delete instance;
		instance = nullptr;
	}
}

ReplyThread::ReplyThread(QObject* parent) : QThread(parent) { ; }

ReplyThread::~ReplyThread() { ; }

void ReplyThread::run()
{
	try
	{
		Client& cl = Client::getInstance();
		while (true)
		{
			string response = cl.getResponseFromServer();
			string type, output = response;
			stringstream resp(response);
			resp >> type;
			if (type == "ALG")
			{
				output.erase(0, 4);
				Log::getInstance().write("SERVER> " + output + "\n");
				emit addCommand(output);
			}
			if (type == "TASK")
			{
				output.erase(0, 5);
				Log::getInstance().write("SERVER> " + output + "\n");
				emit addCommand(output);
			}
			if (type == "INFO")
			{
				cl.updateServerInfo(response);
				Log::getInstance().write("SERVER>\n" + output + "\n");
				emit updateTable(cl.getServerList());
			}
		}
	}
	catch (ConnectException* e)
	{
		ReplyThread::getInstance().terminate();
		ReplyThread::destroyInstance();
		Log::getInstance().write("CONNECTION ERROR #" + to_string(e->getCode()) + ": " + e->getMessage() + "\n");
		QMessageBox::critical(nullptr, "Connection Error", e->getError().c_str());
		delete e;
		exit(-1);
	}
}