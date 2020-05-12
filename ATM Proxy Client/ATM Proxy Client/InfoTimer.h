#pragma once
#include <QTimer>
#include "Client.h"

class InfoTimer : public QObject
{
	Q_OBJECT

private:
	QTimer* servertimer;
	static InfoTimer* instance;
	InfoTimer(QObject *parent = Q_NULLPTR);
	~InfoTimer();

public:
	static InfoTimer& getInstance(QObject* parent = Q_NULLPTR);
	static void destroyInstance();

private slots:
	void sendInfo();
};
