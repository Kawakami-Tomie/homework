#include"cClient.h"
#include <string>
#include <iostream>
using namespace std;

int cClient::ClientNum=0;
string cClient::ServerName = "0";


cClient::cClient()
{
	ClientNum++;
}

cClient::~cClient()
{
	ClientNum--;
}

int cClient::getClientNum() { return ClientNum; }


void cClient::SetServerName(const string& serverName) {
	ServerName = serverName;
}
string cClient::GetServerName()
{
	return ServerName;
}

void cClient::SetName(const string& name) {
	Name = name;
	
}
string cClient::GetName()
{
	return Name;
}

void cClient::Display()
{
	cout << "��������Ϊ" << GetServerName() <<"�û���Ϊ"<<GetName()<< endl;
}