#ifndef _NETLIB_
#define _NETLIB_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

const int BUFSIZE = 4096;

int create_server_fd(const int port, const int n_conns);
int create_client_fd(const char* addr, const int port);
sockaddr_in create_addr(const char* addr, const int port);
void mysend(int target_fd, char* msg);
void myread(int sock);


#endif