#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include<vector>
#include<iostream>
#include<fstream>

#define MAXHOSTNAME 256

int establish(unsigned short portnum) {
  int socketHandle;
  char myName[MAXHOSTNAME +1];
  struct sockaddr_in socketAddress;
  struct hostent *hostPort;
  
  memset(&socketAddress, 0, sizeof(struct sockaddr_in));
  gethostname(myName, MAXHOSTNAME);
  hostPort = gethostbyname(myName);
  if(hostPort == NULL)
    return(-2);
  socketAddress.sin_family = hostPort->h_addrtype;
  socketAddress.sin_port = htons(portnum);
  
  if ((socketHandle = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return(-3);
  if(bind(socketHandle, (struct sockaddr *) &socketAddress, sizeof(struct sockaddr_in)) < 0 ) {
    close(socketHandle);
    return(-4);
  }
  listen(socketHandle, 3);
  return(socketHandle);
  
}

int getConnection(int socket) {
  int connectionSocket;
  
  if ((connectionSocket = accept(socket, NULL, NULL)) < 0)
    return(-1);
  return(connectionSocket);
}
