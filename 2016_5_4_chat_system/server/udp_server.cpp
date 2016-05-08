#include"udp_server.h"
using namespace std;

server::server(string &ip,short &port)
	:_ip(ip)
	 ,_port(port)
	 ,_sock(-1)
{}
server::~server()
{
	if(_sock>-1){
		close(_sock);
	}
}
void server::init_server()
{
	_sock=socket(AF_INET,SOCK_DGRAM,0);
	if(_sock<0){
		//perror("socket");
		exit(1);
	}
	struct sockaddr_in local;
	local.sin_family=AF_INET;
	local.sin_port=htons(_port);
	local.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(_sock,(struct sockaddr*)&local,sizeof(local))<0){
		//perror("bind");
		exit(2);
	}
}
bool server::recv_data(string &out)
{
	struct sockaddr_in client;
	socklen_t len=sizeof(client);
	char buf[1024];
	memset(buf,'\0',sizeof(buf));
	ssize_t _size=recvfrom(_sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
	if(_size<0){
		//perror("recvfrom");
		return false;
	}else if(_size==0){
		//cout<<"client is close.."<<endl;
	}else{
		out=buf;
	}
	return true;
}
bool server::send_data(string &data,struct sockaddr_in* client,socklen_t len)
{
	ssize_t _size=sendto(_sock,data.c_str(),data.size(),0,(struct sockaddr*)client,len);
	if(_size<=0){
		//perror("sendto");
		return false;
	}else{
	}
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
	server _ser(ip,port);
	_ser.init_server();
	string out;
	bool done=true;
	while(done){
		_ser.recv_data(out);
		cout<<out<<endl;
	}
	return 0;
}
