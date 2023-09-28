#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include "netlib.h"

using namespace std;

const int PORT = 8080;
const string ADDR = "127.0.0.1";


int main() {
    int client_fd;
    struct sockaddr_in serv_addr;
    string input;

    client_fd = create_client_fd(PORT);
    serv_addr = create_addr(ADDR, PORT);

    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Connection failed" << endl;
        return -1;
    }

    while (true) {
        getline(cin, input);
        mysend(client_fd, input);
        if (input.empty()) break;
    }

    close(client_fd);
    return 0;
}

