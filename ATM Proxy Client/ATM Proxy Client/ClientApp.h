#pragma once
#include <QtWidgets/QApplication>
#include "atmproxy.h"
#include "mainmenuatmproxy.h"

class ClientApp
{
private:
	static ClientApp* instance;
	ATMproxy login;
	MainMenuATMproxy mainmenu;
	ClientApp() : login(), mainmenu() { ; }
	ClientApp(const ClientApp&) = delete;
	~ClientApp() { ; }

public:
	static ClientApp& getInstance();
	static void destroyInstance();
	void init();
};