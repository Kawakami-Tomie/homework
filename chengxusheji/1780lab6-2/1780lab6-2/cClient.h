#pragma once
#ifndef CCLINET_H
#define CCLIENT_H
#include <string>
using namespace std;
#include<iostream>
class cClient
{public:
	static void SetServerName(const string& serverName);	
	static string GetServerName();
	 void SetName(const string& name);
	 string GetName();
	 void Display();
	cClient();
	~cClient();
	static int getClientNum();

private:
	static string ServerName;
     string Name;
	static int ClientNum;
};

#endif