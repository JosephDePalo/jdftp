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
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = create_server_fd(PORT, N_CONNS);

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        cerr << "accept" << endl;
        exit(EXIT_FAILURE);
    }
    string output;
    while (true) {
        output = myread(new_socket);
        if (output.empty()) break;
        cout << output << endl;
    }


    return 0;
}