#include "netlib.h"

using namespace std;

const int N_CONNS = 3;


int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    string output;

    server_fd = create_server_fd(PORT, N_CONNS);

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        cerr << "accept" << endl;
        exit(EXIT_FAILURE);
    }


    read_file(new_socket);


    return 0;
}