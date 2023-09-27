#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include "netlib.h"

using namespace std;

const int PORT = 8080;
const char* ADDR = "127.0.0.1";


int main() {
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";
    char buffer[1024] = {0};
    client_fd = create_client_fd(ADDR, PORT);

    serv_addr = create_addr(ADDR, PORT);

    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        cerr << "Conncetion failed" << endl;
        return -1;
    }

    send(client_fd, hello, strlen(hello), 0);
    cout << "Hello sent" << endl;
    valread = read(client_fd, buffer, 1024);
    cout << buffer << endl;


    close(client_fd);
    return 0;
}

