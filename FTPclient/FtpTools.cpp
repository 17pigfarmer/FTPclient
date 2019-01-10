#include "FtpTools.h"


void FtpTools::CreateSocketAddr_in(struct sockaddr_in * addr,const string &ipaddr,int port)
{
	memset(addr, 0, sizeof(struct sockaddr_in));
	struct in_addr s;
	inet_pton(AF_INET,ipaddr.c_str(), (void *)&s);
	(*addr).sin_addr.s_addr = s.s_addr;
	(*addr).sin_family = AF_INET;
	(*addr).sin_port = htons(port);
	return;
}

bool FtpTools::ConnectServer(SOCKET s,const struct sockaddr_in * name)
{
	if (connect(s, (struct sockaddr *)name, sizeof(*name)) == SOCKET_ERROR) {
		return false;
	}
	return true;
}

int FtpTools::LogIn(SOCKET s, const string &username, const string &password)
{
	//string send_buf;
	//send_buf = "USER " + username + "\r\n";
	//FlushBuffer(s);
	//send(s, send_buf.c_str(), send_buf.size() + 1, 0);
	this->SendCommand(s, "USER "+username+"\r\n");
	
	char readbuffer[3];
	recv(s, readbuffer, 3, 0);
	if (readbuffer[0]!='3'||readbuffer[1]!='3'||readbuffer[2]!='1') {
		return -2;
	}

	//send_buf.clear();
	//send_buf = "PASS " + password + "\r\n";
	//FlushBuffer(s);
	//send(s, send_buf.c_str(), send_buf.size() + 1, 0);
	this->SendCommand(s, "PASS "+password+"\r\n");

	memset(readbuffer, 0, 3);
	recv(s, readbuffer, 3, 0);
	if (readbuffer[0] != '2' || readbuffer[1] != '3' || readbuffer[2] != '0')  {
		return -1;
	}

	//send_buf.clear();
	//send_buf = "PASV";
	//FlushBuffer(s);
	//send(s, send_buf.c_str(), send_buf.size() + 1, 0);
	
	//this->SendCommand(s, "NLST");
	return 1;

}

void FtpTools::SendCommand(SOCKET s, const string &command)
{
	FlushBuffer(s);
	send(s, command.c_str(), command.size() + 1, 0);
	return;
}

bool FtpTools::WSA()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0) {
		return 0;
	}
	return 1;
}

void FtpTools::DownloadFile(SOCKET s, const string & filename, const string & dir)
{
	
	SendCommand(s, "SIZE " + filename+"\r\n");
	char readbuffer[50];
	recv(s, readbuffer, 50, 0);
	string size = readbuffer;
	string size_sub = size.substr(4,size.size()-6);
	int filesize_int = std::stoi(size_sub);

	std::ofstream mcfile;
	mcfile.open(dir+filename);

	SOCKET data_s = PassiveMode(s);
	SendCommand(s, "RETR " + filename + "\r\n");
	int max = filesize_int/500+1;
	char recvbuffer[500];
	for (int i = 0; i < max; i++) {
		recv(data_s, recvbuffer, 500, 0);
		mcfile << recvbuffer;
	}
	mcfile.close();

}

void FtpTools::ListFile(SOCKET s,string &filelist)
{
	SOCKET data_s = PassiveMode(s);
	SendCommand(s, "NLST\r\n");
	char readbuffer[1000];
	while (true)
	{
		int ret = recv(data_s, readbuffer, 1000, 0);
		filelist += readbuffer;
		if (ret < 1000)
		{
			break;
		}
	}

}

void FtpTools::CloseSocket(SOCKET s)
{
	closesocket(s);
}

void FtpTools::CloseSocket(SOCKET s, SOCKET data_s)
{
	closesocket(s);
	closesocket(data_s);
}

void FtpTools::UploadFile(SOCKET s, string & file)
{
	std::ifstream mcfile;
	mcfile.open(file);
	std::stringstream ss;
	ss << mcfile.rdbuf();
	string str(ss.str());
	SOCKET data_s = PassiveMode(s);
	string filename = file.substr(file.find_last_of('/')+1);
	SendCommand(s, "STOR " + filename + "\r\n");


	send(data_s,str.c_str(),str.size()+1, 0);

	mcfile.close();
	
	char readbuffer[50];
	recv(s, readbuffer, 50, 0);
	
}

SOCKET FtpTools::PassiveMode(SOCKET s)
{
	ip_port* ipp = new ip_port;
	this->SendCommand(s, "PASV");

	char readbuffer2[100];
	recv(s, readbuffer2, 100, 0);
	if (readbuffer2[0] != '2' || readbuffer2[1] != '2' || readbuffer2[2] != '7') {
		return 0;
	}
	string port1, port2;
	string ip(readbuffer2);
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (readbuffer2[i] == ',') {
			count++;
		}
		if (count == 4) {
			i++;
			ip = ip.substr(27, i - 28);
			for (; readbuffer2[i] != ','; i++) {
				port1 += readbuffer2[i];
			}
			i++;
			for (; readbuffer2[i] != ')'; i++) {
				port2 += readbuffer2[i];
			}
			break;
		}
	}
	std::replace(ip.begin(), ip.end(), ',', '.');
	ipp->ip = ip;

	ipp->port = std::stoi(port1) * 256 + std::stoi(port2);
	
	SOCKET data_s;

	data_s = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in data_addr;
	CreateSocketAddr_in(&data_addr, ipp->ip, ipp->port);


	if (ConnectServer(data_s, &data_addr) == 0) {
		//QMessageBox::critical(0, "critical message", "Connect fail!", QMessageBox::Default, 0, 0);
		closesocket(data_s);
		return 0;
	}
	delete ipp;
	return data_s;
	
}





void FtpTools::FlushBuffer(SOCKET s)
{	
	fd_set recvfd;
	struct timeval tv = { 3, 0 };
	FD_ZERO(&recvfd);
	FD_SET(s, &recvfd);
	int result = select(0, &recvfd, NULL, NULL, &tv);
	char readbuffer[500];
	if (result > 0) {
		while (true)
		{
			int ret = recv(s, readbuffer, 500, 0);
			if (ret < 500)
			{
				break;
			}
		}
	}
}
