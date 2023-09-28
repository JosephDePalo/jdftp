#ifndef _NETLIB_
#define _NETLIB_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>

const int PORT = 1234;

const int BUFSIZE = 4096;

int create_server_fd(const int port, const int n_conns);
int create_client_fd(const int port);
sockaddr_in create_addr(const std::string addr, const int port);
void mysend(int target_fd, std::string msg);
std::string myread(int sock);
void read_file(int sock);
void send_file(int target_fd, std::string file_name);


#endif