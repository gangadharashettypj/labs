/*
Program: UDP Server
Author: Gangadhara Shetty P J
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

int main()
{
	int sock;
	struct sockaddr_in addr = { AF_INET, htons(1236), INADDR_ANY };
	char buffer[100];
	char *msg = "this is server";
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	bind(sock, (struct sockaddr*)&addr, sizeof(addr));
	int len = sizeof(addr);
	
	recvfrom(sock, (char *)buffer, sizeof(buffer), 0, ( struct sockaddr *) &addr, &len); 
	printf("%s\n", buffer);
	sendto(sock, msg, strlen(msg), 0, (struct sockaddr *) &addr,sizeof(addr));
	return 0;
}
