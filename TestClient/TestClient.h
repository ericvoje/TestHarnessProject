#ifndef TESTCLIENT_H
#define TESTCLIENT_H
/////////////////////////////////////////////////////////////////////
// TestClient.h - Class for handling the client networking code    //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 4,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include "../CppSockets/Sockets.h"

namespace Client {


	class TestClient
	{
	public:
		TestClient()
		{
			_running = false;
		}
		~TestClient()
		{
			if (_running)
				stop();
		}

		bool start(int port);
		void stop();
		int sendTest(std::string path);

	private:
		bool _running;
		Sockets::SocketConnecter _sc;
	};

}
#endif