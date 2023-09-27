#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

int const PORT = 8080;

int main() {
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";
    char buffer[1024] = {0};
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cerr << "Socket creation error" << endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        cerr << "Invalid address, not supported" << endl;
        return -1;
    }

    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        cerr << "Conncetion failed" << endl;
        return -1;
    }

    send(client_fd, hello, strlen(hello), 0);
    cout << "Hell sent" << endl;
    valread = read(client_fd, buffer, 1024);
    cout << buffer << endl;


    close(client_fd);
    return 0;
}

