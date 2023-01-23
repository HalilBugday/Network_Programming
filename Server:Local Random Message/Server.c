#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netdb.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>




int main(int argc, char *argv[]) {



srand(time(0));
int randNumber=0;
randNumber = rand() %10;
char APRESSMESSAGE[1000]; 
char turkish0[] = "Ne mutlu 'Türküm' diyene!(Mustafa Kemal Atatürk)\n";
char turkish1[] = "Türkiye Cumhuriyetinin temeli kültürüdür!(Mustafa Kemal Atatürk)\n";
char turkish2[] = "Hayatta en hakiki mürşit ilimdir!(Mustafa Kemal Atatürk)\n";
char turkish3[] = "Türk, öğün, çalış, güven!(Mustafa Kemal Atatürk)\n";
char turkish4[] = "En büyük savaş, cahilliğe karşı yapılan savaştır!(Mustafa Kemal Atatürk)\n";
char turkish5[] = "Muhtaç olduğunda kudret; damarlarındaki asil kanda, mevcuttur!(Mustafa Kemal Atatürk)\n";
char turkish6[] = "Bir milletin ahlak değeri, o milletin yükselmesini sağlar!(Mustafa Kemal Atatürk)\n";
char turkish7[] = "Sorgulamayan insan cahildir, sorgulatmayan ise zalim!(Mustafa Kemal Atatürk)\n";
char turkish8[] = "Eğer bir gün benim sözlerim bilimle ters düşerse, bilimi seçin!(Mustafa Kemal Atatürk)\n";
char turkish9[] = "Gelecek gençlerin, gençler ise öğretmenlerin eseridir!(Mustafa Kemal Atatürk)\n";

switch (randNumber)
{
	
	case 0:
	strcpy(APRESSMESSAGE, turkish0);
	break;
	
	case 1:
	strcpy(APRESSMESSAGE, turkish1);
	break;
	
	case 2:
	strcpy(APRESSMESSAGE, turkish2);
	break;
	
	case 3:
	strcpy(APRESSMESSAGE, turkish3);
	break;
	
	case 4:
	strcpy(APRESSMESSAGE, turkish4);
	break;
	
	case 5:
	strcpy(APRESSMESSAGE, turkish5);
	break;
	
	case 6:
	strcpy(APRESSMESSAGE, turkish6);
	break;
	
	case 7:
	strcpy(APRESSMESSAGE, turkish7);
	break;
	
	case 8:
	strcpy(APRESSMESSAGE, turkish8);
	break;
	
	case 9:
	strcpy(APRESSMESSAGE, turkish9);
	break;	
	
}
	
int simpleSocket = 0;
int simplePort = 0;
int returnStatus = 0;
struct sockaddr_in simpleServer;

if (2 != argc) {

        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
}
simpleSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

     if (simpleSocket == -1) {
        fprintf(stderr, "Could not create a socket!\n");
        exit(1);

}
else {
        fprintf(stderr, "Socket created!\n");
    }

/* retrieve the port number for listening */
simplePort = atoi(argv[1]);


/* set up the address structure */
/* use INADDR_ANY to bind to all local addresses */ 
bzero(&simpleServer, sizeof(simpleServer)); 
simpleServer.sin_family = AF_INET; 
simpleServer.sin_addr.s_addr = htonl(INADDR_ANY); 
simpleServer.sin_port = htons(simplePort);


/* bind to the address and port with our socket */ 
returnStatus = bind(simpleSocket,
                    (struct sockaddr *)&simpleServer,
                    sizeof(simpleServer));

if (returnStatus == 0) {
fprintf(stderr, "Bind completed!\n");
}
else {
    fprintf(stderr, "Could not bind to address!\n");
    close(simpleSocket);
    exit(1);
}

/* let's listen on the socket for connections */ 
returnStatus = listen(simpleSocket, 5);

if (returnStatus == -1) {
fprintf(stderr, "Cannot listen on socket!\n"); 
close(simpleSocket);
exit(1);
}
while (1) 
{
struct sockaddr_in clientName = { 0 };
int simpleChildSocket = 0;
int clientNameLength = sizeof(clientName);
    /* wait here */

simpleChildSocket = accept(simpleSocket,
                                (struct sockaddr *)&clientName,
                                &clientNameLength);

if (simpleChildSocket == -1) {
fprintf(stderr, "Cannot accept connections!\n");
close(simpleSocket);
exit(1);
}
        /* handle the new connection request  */
        /* write out our message to the client */
        write(simpleChildSocket, APRESSMESSAGE, strlen(APRESSMESSAGE));
        close(simpleChildSocket);
}
    close(simpleSocket);
    return 0;
}
