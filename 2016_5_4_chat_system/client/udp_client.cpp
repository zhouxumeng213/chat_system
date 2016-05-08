#include"udp_client.h"
using namespace std;
client::client(std::string &ip,short &port)
	:_ip(ip)
	 ,_port(port)
	 ,_sock(-1)
{
}
client::~client()
{
	if(_sock>-1){
		close(_sock);
	}
}
void client::init_client()
{
	_sock=socket(AF_INET,SOCK_DGRAM,0);
	if(_sock<0){
		//perror("socket");
		exit(1);
	}
}
bool client::recv_data(std::string &buf)
{
	return true;
}
bool client::send_data(std::string &data)
{
	struct sockaddr_in remote;
	remote.sin_family=AF_INET;
	remote.sin_port=htons(_port);
	remote.sin_addr.s_addr=inet_addr(_ip.c_str());
	socklen_t len=sizeof(remote);
	ssize_t _size=sendto(_sock,data.c_str(),data.size(),0,(struct sockaddr*)&remote,len);
	if(_size<0){
		//perror("sendto");
		return false;
	}else{}
	return true;
}
void usage(string arg)
{
	cout<<arg<<"[ip] [port]"<<endl;
}
int main(int argc,char* argv[])
{
	if(argc!=3){
		usage(argv[0]);
		return 1;
	}
	string ip=argv[1];
	short port=atoi(argv[2]);
	client _cli(ip,port);
	_cli.init_client();
	while(1){
		string msg="hello world";
		_cli.send_data(msg);
		sleep(1);
	}
}
