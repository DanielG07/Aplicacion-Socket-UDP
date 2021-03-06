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
	int numeros[4];
	int contador = 0;
	int operaciones = 0; 
	int i, j, temp;

	char *adios = "Adios";
	char *add = "Add";
	char *mal = "mal";
 
	int sockfd; 
	char buffer[MAXLINE]; 
	
	struct sockaddr_in servaddr, cliaddr; 
      

	if ( (sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
      
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
      

	servaddr.sin_family    = PF_INET; 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
     

	if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
		sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
      
	int len, n; 

	printf("Socket iniciado\n");

	len = sizeof(cliaddr); 
 
	while(strcmp(buffer, "Adios")){
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
		MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                &len); 

		buffer[n] = '\0'; 

		numeros[contador] = atoi(buffer);

		printf("Cliente : %d\n", numeros[contador]); 

		sendto(sockfd, (const char *)add, strlen(add),  
			MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
			len); 

		contador++;
		printf("Contador: %d\n",contador);
		
		if(contador == 4){

			for (i=1;i<4;i++)
			{
			       for (j=0; j < 4-i ;j++) 
			       {
				  if (numeros[j] < numeros[j+1])
				  {
				    temp=numeros[j];
				    numeros[j]=numeros[j+1];
				    numeros[j+1]=temp;
				  }
			       }
			}

			for(i=0; i<4; i++){
				printf("Numero %d: %d\n",i+1,numeros[i]);
			}			

			operaciones = ((numeros[0]*numeros[3])-numeros[1])*numeros[2];
			printf("El resultado es: %d\n", operaciones);

			if(operaciones < 5000){
				sendto(sockfd, (const char *)adios, strlen(adios),  
				MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
				len); 

				n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
				MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
				&len); 

				buffer[n] = '\0'; 

				
			}
			else{
				contador = 0;
				sendto(sockfd, (const char *)mal, strlen(mal),  
				MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
				len); 
			}
		}

	}

	close(sockfd);
	return 0; 
} 
