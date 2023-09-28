#include "netlib.h"

using namespace std;


int create_server_fd(const int port, const int n_conns) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    // Create Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cerr << "socket failed" << endl;
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        cerr << "setsockopt" << endl;
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind to address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        cerr << "bind failed" << endl;
        exit(EXIT_FAILURE);
    }

    // Listen on port
    if (listen(server_fd, n_conns) < 0) {
        cerr << "listen" << endl;
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

int create_client_fd(const int port) {
    int client_fd;

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cerr << "Socket creation error" << endl;
        return -1;
    }

    return client_fd;
}

sockaddr_in create_addr(const string addr, const int port) {
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, addr.c_str(), &serv_addr.sin_addr) <= 0) {
        cerr << "Invalid address, not supported" << endl;
        exit(EXIT_FAILURE);
    }
    
    return serv_addr;

}

void mysend(int target_fd, string msg) {
    if (msg.length() > BUFSIZE) {
        string new_msg(msg, 0, BUFSIZE);
        send(target_fd, new_msg.c_str(), BUFSIZE, 0);
    }

    send(target_fd, msg.c_str(), BUFSIZE, 0);
}

string myread(int sock) {
    char buffer[BUFSIZE] = {0};

    read(sock, buffer, BUFSIZE);

    return string(buffer);
}

void read_file(int sock) {
    string file_name = myread(sock);
    ofstream outfile("output.txt", ios::binary);
    string line;
    while (true) {
        line = myread(sock);
        if (line.empty()) break;
        outfile << line << endl;
    }
}

void send_file(int target_fd, string file_name) {
    ifstream file(file_name, ios::binary);
    char buf[BUFSIZE];

    mysend(target_fd, file_name);
    while (file.peek() != EOF) {
        file.read(buf, BUFSIZE);
        mysend(target_fd, buf);
    }
    mysend(target_fd, "");

    file.close();
}