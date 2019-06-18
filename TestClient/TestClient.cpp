// TestClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TestClient.h"
#include "../Logger/Logger.h"
#include "../CppSockets/Sockets.h"
#include "../Utilities/WindowsHelpers/WindowsHelpers.h"
#include "../Utilities/StringUtilities/StringUtilities.h"
#include "../Utilities/CodeUtilities/CodeUtilities.h"

using namespace Client;

// Helper objects
template<typename T>
using Conv = Utilities::Converter<T>;
using Show = Logging::StaticLogger<1>;

// Handle client messaging
class ClientHandler
{
public:
	void operator()(Sockets::Socket& socket_);
	bool testStringHandling(Sockets::Socket& socket_);
	bool testBufferHandling(Sockets::Socket& socket_);
};


/* maybe don't need
// Constructor
TestClient::TestClient()
{

}

// Destructor
TestClient::~TestClient()
{
	stop();
}
*/

// Start client app
// Returns true if started, false otherwise
bool TestClient::start(int port)
{
	// Attempt to connect, quit if not found
	while (!_sc.connect("localhost", port))
	{
		Show::write("\n  client waiting to connect");
		::Sleep(100);
	}

	return false;
}

// Stop client app
void TestClient::stop()
{
	// if not running, don't do anything
	if (!_running)
		return;

	// It is running, so stop it
	_sc.shutDownSend();
}

// Send server message to start test file at location
int TestClient::sendTest(std::string path)
{
	if (_running)
	{
		_sc.sendString(path);
	}

	// Something didn't work
	return -1;
}

/*
//----< test string handling - server echos back client sent string >--------
void clientTestStringHandling(Sockets::Socket& si)
{
	std::string command = "TEST_STRING_HANDLING";
	si.sendString(command);
	Show::write("\n  client sent : " + command);

	for (size_t i = 0; i < 5; ++i)
	{
		std::string text = "Hello World " + std::string("#") + Conv<size_t>::toString(i + 1);
		si.sendString(text);
		Show::write("\n  client sent : " + text);
	}
	command = "TEST_END";
	si.sendString(command);
	Show::write("\n  client sent : " + command);

	while (true)
	{
		std::string str = Sockets::Socket::removeTerminator(si.recvString());
		if (str.size() == 0)
		{
			Show::write("\n  client detected closed connection");
			break;
		}
		Show::write("\n  client recvd: " + str);
		if (str == "TEST_END")
		{
			Show::write("\n  End of string handling test in client");
			break;
		}
	}
}
//----< test buffer handling - server echos back client sent buffer >--------

// Handle incoming messages
void clientTestBufferHandling(Sockets::Socket& si)
{
	std::string command = "TEST_BUFFER_HANDLING";
	si.sendString(command);
	Show::write("\n  client sent : " + command);

	const int BufLen = 20;
	Sockets::Socket::byte buffer[BufLen];

	for (size_t i = 0; i < 5; ++i)
	{
		std::string text = "Hello World " + std::string("#") + Conv<size_t>::toString(i + 1);
		for (size_t i = 0; i < BufLen; ++i)
		{
			if (i < text.size())
				buffer[i] = text[i];
			else
				buffer[i] = '.';
		}
		buffer[BufLen - 1] = '\0';
		si.send(BufLen, buffer);
		Show::write("\n  client sent : " + std::string(buffer));
	}
	std::string text = "TEST_END";
	for (size_t i = 0; i < BufLen; ++i)
	{
		if (i < text.size())
			buffer[i] = text[i];
		else
			buffer[i] = '.';
	}
	buffer[BufLen - 1] = '\0';
	si.send(BufLen, buffer);
	Show::write("\n  client sent : " + std::string(buffer));

	bool ok;
	std::string collector;
	while (true)
	{
		if (si.bytesWaiting() == 0)
			break;
		ok = si.recv(BufLen, buffer);
		if (!ok)
		{
			Show::write("\n  client unable to receive");
			break;
		}
		std::string str(buffer);
		collector += str;
		if (str.size() == 0)
		{
			Show::write("\n  client detected closed connection");
			break;
		}
		Show::write("\n  client rcvd : " + str);
		if (collector.find("TEST_END") != std::string::npos)
		{
			Show::write("\n  End of buffer handling test in client");
			break;
		}
	}
}
*/

#ifdef TEST_TESTCLIENT

// main client function
int main()
{
	// Start Logger
	Show::attach(&std::cout);
	Show::start();

	Show::title("Test Handler Client", '=');

	try
	{
		Sockets::SocketSystem ss;
		Sockets::SocketConnecter si;
		Sockets::SocketListener sl(9070, Sockets::Socket::IP4);
		ClientHandler cp;
		sl.start(cp);

		while (!si.connect("localhost", 9070))
		{
			Show::write("\n  client waiting to connect");
			::Sleep(100);
		}

		Show::title("Starting string test on client");
		//clientTestStringHandling(si);

		si.sendString("TEST_STOP");

		Show::write("\n\n  client calling send shutdown\n");
		si.shutDownSend();
		sl.stop();
	}
	catch (std::exception & ex)
	{
		std::cout << "\n  Exception caught:";
		std::cout << "\n  " << ex.what() << "\n\n";
	}


}

#endif