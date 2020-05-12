#include "Server.h"

int main()
{
	Server& s = Server::getInstance("25.135.243.156", 54000);;
	//Server& s = Server::getInstance("127.0.0.1", 54000);
	if (s.init() != 0) {
		Log::getInstance().LogInfo("[ERROR]:Initialization problem!");
		std::cout << "Initialization problem! Quitting.." << std::endl;
		return -1;
	}
	std::cout << "Server ON" << std::endl;
	s.run();
	Server::destroyInstance();

	return 0;

}