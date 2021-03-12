#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT     8080 
#define MAXLINE 1024 
  

int main() { 
	int contador = 0;
	char *adios = "Adios";

	int sockfd; 
	char buffer[MAXLINE];
	char message[MAXLINE];   
	struct sockaddr_in servaddr; 
  

	if ( (sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
  
	memset(&servaddr, 0, sizeof(servaddr)); 
      

	servaddr.sin_family = PF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
      
	int n, len; 

    while(strcmp(buffer, "Adios")){
		contador = 0;
		while(contador < 4){
			printf("Ingrese un mensaje: ");
			gets(message);
			fflush(stdin);

			sendto(sockfd, (char *)message, strlen(message), 
				MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
				sizeof(servaddr)); 

			printf("Message sent.\n"); 

			n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
				MSG_WAITALL, (struct sockaddr *) &servaddr, 
				&len); 

			buffer[n] = '\0';

			printf("Server : %s\n", buffer);
			contador++;
		}
		printf("Es correcto?\n");
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
				MSG_WAITALL, (struct sockaddr *) &servaddr, 
				&len); 

		buffer[n] = '\0';

		printf("Server: %s\n", buffer);  
		
	}

	sendto(sockfd, (char *)adios, strlen(adios), 
	MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
	sizeof(servaddr)); 
  
	close(sockfd); 
	return 0; 
} 
