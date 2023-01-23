#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#define portno 2222
#define bufflen 256

int main()
{	
	struct sockaddr_in client;
	int flag;
	char buffer[bufflen];
	int main_sock;
	
	memset(&client,0,sizeof(client));
	
	main_sock=socket(AF_INET, SOCK_STREAM, 0);
	
	if(main_sock<0)
	{
		printf("SOCKET ERROR!");
		exit(1);
	}	
	
	client.sin_addr.s_addr=INADDR_ANY;
	client.sin_family=AF_INET;
	client.sin_port=portno;
	
	flag=connect(main_sock,(struct sockaddr*)&client,sizeof(client));
	if(flag<0)
	{
		printf("CONNECT ERROR!");
		exit(1);
	}
	
	for(;;)
	{
		printf("CLIENT: ");
		fgets(buffer,100,stdin);
		
		flag=write(main_sock,buffer,100,0);
		if(flag<0)
		{
			printf("SEND ERROR!");
			exit(1);
		}
		
		flag=read(main_sock,buffer,100,0); 
		if(flag<0)
		{
			printf("RECEİVE ERROR!");
			exit(1);
		}
		
		printf("SERVER: %s",buffer);
	}
	
	close(main_sock);
	exit(0);
	return 0;
		
}
