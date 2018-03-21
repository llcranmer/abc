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
#include<iostream>
#include<fstream>

int callSocket(std::string hostname, unsigned short portNumber) {
  struct sockaddr_in socketAddress;
  struct hostent     *hostPort;
  int address, socketPort;

  if((hostPort = gethostbyname(hostname.c_str())) == NULL) {
    errno = ECONNREFUSED;
    return -1;
  }

  memset(&socketAddress, 0, sizeof(socketAddress));
  memcpy((char *)&socketAddress.sin_addr, hostPort->h_addr, hostPort->h_length);
  socketAddress.sin_family = hostPort->h_addrtype;
  socketAddress.sin_port = htons((u_short)portNumber);

  if((socketPort = socket(hostPort->h_addrtype, SOCK_STREAM, 0)) < 0)
    return(-1);
  if(connect(socketPort, (struct sockaddr *) &socketAddress, sizeof socketAddress) < 0) {
    close(socketPort);
    return(-1);
  }
  return(socketPort);

}
