#include "netlib.h"

using namespace std;

const string ADDR = "127.0.0.1";


int main(int argc, char argv[]) {
    istringstream iss;
    string file_name;


    if (argc != 2) {
        exit(EXIT_FAILURE);
    }

    iss >> file_name;


    int client_fd;
    struct sockaddr_in serv_addr;
    string input;

    client_fd = create_client_fd(PORT);
    serv_addr = create_addr(ADDR, PORT);

    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Connection failed" << endl;
        return -1;
    }


    send_file(client_fd, file_name);

    close(client_fd);
    return 0;
}

