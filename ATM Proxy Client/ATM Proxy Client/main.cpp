#include"ClientApp.h"
int main(int argc, char *argv[])
{
	Client::getInstance("25.49.139.156", 54001);
	//Client::getInstance();
	QApplication app(argc, argv);
	ClientApp::getInstance().init();
	return app.exec();
}