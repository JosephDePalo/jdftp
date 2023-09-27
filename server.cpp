#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#include "netlib.h"

using namespace std;

const int PORT = 8080;
const int N_CONNS = 3;


int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char* hello = "Hello from server";

    server_fd = create_server_fd(PORT, N_CONNS);

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        cerr << "accept" << endl;
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, 1024);
    cout << buffer << endl;
    send(new_socket, hello, strlen(hello), 0);
    cout << "Sent hello" << endl;
    


    return 0;
}