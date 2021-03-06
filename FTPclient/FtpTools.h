#pragma once
#include <WINSOCK2.H>
#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#ifndef string
#define string std::string
#endif // string



class FtpTools {
public:
	struct ip_port{
		string ip;
		int port;
	};
	void CreateSocketAddr_in(struct sockaddr_in * addr,const string &ipaddr,int port);
	bool ConnectServer(SOCKET s, const struct sockaddr_in *name);
	int LogIn(SOCKET s, const string &username, const string &password);
	void SendCommand(SOCKET s,const string &command);
	bool WSA();
	void DownloadFile(SOCKET s,const string &filename,const string &dir);
	void ListFile(SOCKET s,string &filelist);
	void CloseSocket(SOCKET s);
	void CloseSocket(SOCKET s, SOCKET data_s);
	void UploadFile(SOCKET s, string &file);
	SOCKET PassiveMode(SOCKET s);
private:
	void FlushBuffer(SOCKET s);

};
