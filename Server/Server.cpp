/////////////////////////////////////////////////////////////////////
// Server.cpp - messaging and file transfer                         //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 4,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai, Chaulladevi Bavda          //
//              ervoje@syr.edu, kutsai@syr.edu, cvbavda@syr.edu    //
/////////////////////////////////////////////////////////////////////

#include "Server.h"
#include <thread>
#include <sstream>
#include <functional>
#include "../Logger/Logger.h"
#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"

using Show = Logging::StaticLogger<1>;
using namespace Utilities;


void Server::ServerSender()
{
	try
	{
		SocketConnecter si;
		Sender send(this->addr, this->port);

		HttpMessageFunc popValue;
		BlockingQueue<HttpMessageFunc>& q1 = StaticBlockingQueue<HttpMessageFunc, 1>().getQueue();
		
		while (true)
		{
			

			

			

		}
	}
	catch (std::exception& exc)
	{
		
		std::string exMsg = "\n  " + std::string(exc.what()) + "\n\n";
		
	}
}

void Server::ServerReceiver()
{
	try
	{
		
		std::cin.get();
		std::cout << "received message";
	}
	catch (std::exception& exc)
	{
		
		std::string exMsg = "\n  " + std::string(exc.what()) + "\n\n";
		
	}
}

//----< test stub >--------------------------------------------------

int main(int argc, char* argv[])
{
	try
	{
		Server ms(argv[1], argv[2]);
		std::cout << "Server is up and running";
		std::thread Sender(&Server::ServerSender, ms);
		std::thread Receiver(&Server::ServerReceiver, ms);
		Sender.join();
		Receiver.join();
	}
	catch (std::exception& exc)
	{
		Show::write("\n  Server Response Failed.\n ");
		std::string exMsg = "\n  " + std::string(exc.what()) + "\n\n";
		Show::write(exMsg);
	}
}
