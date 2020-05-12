#include "InfoTimer.h"

InfoTimer* InfoTimer::instance = nullptr;

InfoTimer& InfoTimer::getInstance(QObject* parent)
{
	if (!InfoTimer::instance)
	{
		InfoTimer::instance = new InfoTimer(parent);
	}
	return *InfoTimer::instance;
}

void InfoTimer::destroyInstance()
{
	if (InfoTimer::instance)
	{
		delete instance;
		instance = nullptr;
	}
}

InfoTimer::InfoTimer(QObject* parent) : QObject(parent)
{
	servertimer = new QTimer(this);
	QObject::connect(servertimer, &QTimer::timeout, this, &InfoTimer::sendInfo);
	servertimer->start(1000);
}

InfoTimer::~InfoTimer()
{
	delete servertimer;
	servertimer = Q_NULLPTR;
}

void InfoTimer::sendInfo()
{
	(Client::getInstance()).getServersStatus();
}