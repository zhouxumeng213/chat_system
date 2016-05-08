#pragma once

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<string>
#include<errno.h>
#include<stdio.h>
using namespace std;
class server
{
	public:
		server(string &ip,short &port);
		~server();
		void init_server();
		bool recv_data(string &out);
		bool send_data(string &data,struct sockaddr_in* client,socklen_t len);
	private:
		string _ip;
		short _port;
		int _sock;
};
