#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#define portno 2222
#define bufflen 256

int main()
{	
	struct sockaddr_in server, client;
	int flag;
	char buffer[bufflen];
	int main_sock;
	int new_sock;
	socklen_t len;
	
	memset(&client, 0 ,sizeof(client));
	memset(&server, 0 ,sizeof(server));
	
	main_sock=socket(AF_INET, SOCK_STREAM, 0);
	if(main_sock<0)
	{
		printf("SOCKET ERROR!");
		exit(1);
	}
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=portno;
	
	flag=bind(main_sock, (struct sockaddr*) &server, sizeof(server));
	if(flag<0)
	{
		printf("BİND ERROR!");
		exit(1);
	}
	
	flag=listen(main_sock,20);
	if(flag<0)
	{
		printf("LİSTEN ERROR!");
		exit(1);
	}
	
	len=sizeof(client);
	new_sock=accept(main_sock,(struct sockaddr*)&client,&len);
	if(new_sock<0)
	{
		printf("SOCKET ERROR!");
		exit(1);
	}
	
	for(;;)
	{
		flag=read(new_sock,buffer,100,0);
		if(flag<0)
		{
			printf("RECEİVE ERROR!");
			exit(1);
		}
		printf("CLIENT: %s",buffer);
		printf("SERVER: ");
		
		fgets(buffer,100,stdin);
		flag=write(new_sock,buffer,100,0);
		if(flag<0)
		{
			printf("SEND ERROR!");
			exit(1);
		}
		
	}
	close(new_sock);
	exit(0);
	return 0;
	
}
	
