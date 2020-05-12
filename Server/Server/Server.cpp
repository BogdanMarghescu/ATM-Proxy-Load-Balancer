#include "Server.h"
#include <algorithm>
std::mutex				key;
long					availableThreads = POOL_SIZE;
Server*					Server::instance = nullptr;

Server& Server::getInstance(std::string ipAdress, int port)
{
	if (!instance)
	{
		Server::instance = new Server(ipAdress, port);
	}
	return *Server::instance;
}

void Server::destroyInstance()
{
	if (instance)
	{
		delete Server::instance;
		Server::instance = nullptr;
	}
}

void Server::onClientDisconnected(int clientSocket)
{
	Log::getInstance().LogInfo("Client from socket #" + std::to_string(clientSocket) + " disconnected");
	std::cout << "Client from socket #" + std::to_string(clientSocket) + " disconnected" << std::endl;
	closesocket(clientSocket);
}

void handleTask(ITask* task,std::string taskID)
{
	InterlockedDecrement(&availableThreads);

	std::string result = task->solve();
	result = taskID + " " + result;

	key.lock();
	Server::resultList.push_back(result);
	key.unlock();

	key.lock();
	delete task;
	key.unlock();

	InterlockedIncrement(&availableThreads);
}

bool is_digits(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

void Server::onMessageReceived(int clientSocket, std::string msg)
{	
	std::string message = Base64::getInstance().decode(msg);

	std::istringstream iss(message);
	std::vector<std::string> parsed((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
	if (parsed.size() == 0)
	{
		return;
	}

	if (parsed[0] == "INFO")
	{
		Log::getInstance().LogInfo("[INFO]:Info request");

		int disp = POOL_SIZE - availableThreads;
		disp *= 100;
		disp /= POOL_SIZE;
		std::string buff = "INFO 1 " + std::to_string(disp) + " " + std::to_string(hits);
		sendToClient(clientSocket, buff);
		return;
	}
	else if (!is_digits(parsed[0]) || parsed.size() <= 1)
	{
		Log::getInstance().LogInfo("[ERROR]:Unknown command");
		std::string bu = "Unknown command";
		std::cout << bu;
		//sendToClient(clientSocket, bu, bu.length());

		return;
	}
	else if (parsed[1] == "TASK")
	{	
		Log::getInstance().LogInfo("[INFO]:TASK request");
		std::cout << "[TASK]:";

		if (availableThreads == 0)
		{
			Log::getInstance().LogInfo("[ERROR]:Server is fully loaded!");
			return;
		}

		if(stoi(parsed[2]) > 3 || stoi(parsed[2]) <= 0)
		{
			Log::getInstance().LogInfo("[ERROR]: TASK " + parsed[2] + " doesn't exist!");
			
			std::string buffi = "Nu exista task-ul " + parsed[2];
			sendToClient(clientSocket, buffi.c_str());
			
			return;
		}
		
		ITask* task = nullptr;
		
		if (parsed[2] == "1") {
			task = ITask::generate(stoi(parsed[2]), stoi(parsed[3]), 0);
		}
		else {
			task = ITask::generate(stoi(parsed[2]), stoi(parsed[3]), stoi(parsed[4]));
		}
		hits++;

		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (availableThreads > 0)
			{
				pool.push_back(std::thread(handleTask, task, parsed[0]));
				pool[pool.size() - 1].detach();
				break;
			}
		}

		return;
	}

}