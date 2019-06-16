#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <thread>
#include "../FileSystem/FileSystem.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"


class Client
{
public:

	void Receiver();
	void Sender();
	bool connectSocketStatus(std::string addr, int portNo, SocketConnecter& si);

	Client(std::string taddr = "localhost:8080", std::string tpath = "ClientRepository\\")
	{
		address = taddr.substr(0, taddr.find(':'));
		port = std::stoi(taddr.substr(taddr.find(':') + 1, taddr.size()));
		path = tpath;
	}
	void HandleCommonFunction(std::string message);
	void HandleCheckIn(std::string message, std::string cmd);
	void StartClientSenRec();

private:
	std::string address;
	
	int port;
	std::string path;
};



#endif