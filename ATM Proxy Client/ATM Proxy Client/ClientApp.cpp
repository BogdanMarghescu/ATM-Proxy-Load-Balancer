#include "ClientApp.h"

ClientApp* ClientApp::instance = nullptr;

ClientApp& ClientApp::getInstance()
{
	if (!ClientApp::instance)
	{
		ClientApp::instance = new ClientApp();
	}
	return *ClientApp::instance;
}

void ClientApp::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void ClientApp::init()
{
	qRegisterMetaType<ServerList>();
	qRegisterMetaType<string>();
	Log::getInstance().open("ATM_PROXY_Client.log");
	Log::getInstance().write("ATM PROXY Client opened.\n");
	QObject::connect(&login, &ATMproxy::openMenu, &mainmenu, &MainMenuATMproxy::openMainMenu);
	QObject::connect(&mainmenu, &MainMenuATMproxy::returnLoginMenu, &login, &ATMproxy::returnLoginMenu);
	Base64::getInstance();
	login.show();
}