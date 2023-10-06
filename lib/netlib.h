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
#include <vector>

const int PORT = 1234;
const int BUFSIZE = 4096;

class Connection { // TODO Refactor program to use Connection instead of raw file descriptors
private:
    bool open_;
    int fd_;
    std::string ip_;
public:
    Connection(const int fd, const std::string ip);
    bool is_open() const;
    int fd() const;
    std::string ip() const;
};

int create_server_fd(const int port, const int n_conns);
int create_client_fd(const int port);
sockaddr_in create_addr(const std::string addr, const int port);
Connection get_client();
void mysend(int target_fd, std::string msg);
std::string myread(int sock);
int read_file(int sock);
int send_file(int target_fd, std::string file_name);


#endif