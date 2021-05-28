#pragma once
#include "IDataBase.h"
#include <iostream>

#define SQL_BEGIN "BEGIN;"
#define SQL_COMMIT "COMMIT;"
#define SQL_BEGIN_ERROR "Couldn't send BEGIN."
#define SQL_COMMIT_ERROR "Couldn't send COMMIT."


class SqliteDataBase : IDataBase
{
public:
	virtual bool doesUserExist(std::string username);
	virtual bool doesPasswordMatch(std::string password, std::string repeat);
	virtual void addNewUser(std::string username, std::string password, std::string mail);

private:
	sqlite3* _Database;
	void sqlQuery(const char* query, std::string error, int (*ptr)(void*, int, char**, char**)); // Helper Method

};