#pragma once
#include <QThread>
#include "Client.h"

class ReplyThread : public QThread
{
	Q_OBJECT

private:
	static ReplyThread* instance;
	ReplyThread(QObject* parent = Q_NULLPTR);
	~ReplyThread();

signals:
	void updateTable(ServerList svlist);
	void addCommand(string command);

public:
	static ReplyThread& getInstance(QObject* parent = Q_NULLPTR);
	static void destroyInstance();
	void run();
};
