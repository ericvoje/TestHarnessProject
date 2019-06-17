#pragma once
#ifndef SERVER_H
#define SERVER_H
/////////////////////////////////////////////////////////////////////
// Server.h - messaging and file transfer                         //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 4,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai, Chaulladevi Bavda          //
//              ervoje@syr.edu, kutsai@syr.edu, cvbavda@syr.edu    //
/////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include "../HttpMessage/HttpMessage.h"
#include "../Sockets/Sockets.h"
#include "../FileSystem/FileSystem.h"
#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"
#include "../Logger/Logger.h"

#include "../Utilities/Utilities.h"

using namespace Utilities;

class Server
{
public:

	void ServerSender();
	void ServerReceiver();
	bool connectSocketStatus(std::string addr, int portNo, SocketConnecter& si);
	
	Server(std::string taddr = "localhost:8081", std::string tpath = "ServerRepository\\")
	{
		addr = taddr.substr(0, taddr.find(':'));
		port = std::stoi(taddr.substr(taddr.find(':') + 1, taddr.size()));
		path = tpath;
		
	}

private:
	std::string addr;
	int port;
	std::string path;
};


#endif 