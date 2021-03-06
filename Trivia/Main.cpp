#pragma comment (lib, "ws2_32.lib")
#include "Server.h"
#include "WSAInitializer.h"
#include "SqliteDataBase.h"
#include <iostream>



int main()
{
	try
	{

		//NOTICE at the end of this block the WSA will be closed 
		WSAInitializer wsa_init;
		SqliteDataBase* dataBase = new SqliteDataBase();
		Server server(dataBase);
		server.run();

	}
	catch (const std::exception& e)
	{
		std::cout << "Exception was thrown in function: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception in main !" << std::endl;
	}
	return 0;
}
