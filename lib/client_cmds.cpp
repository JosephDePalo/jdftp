#include "client_cmds.h"
#include "netlib.h"
#include "helpers.h"

using namespace std;

void client_handler(string input, State& state) {
    vector<string> argv = parse(input);
    int argc = argv.size();

    if (argc == 0) return;

    if (cmd_map.find(argv[0]) == cmd_map.end())
        return;

    Cmd command = cmd_map.at(argv[0]);

    switch(command) {
        case GET:
            if (argc != 2) {
                cout << "Usage: get <file>" << endl;
                break;
            }
            state.get_file(argv[1]);
            break;
        case PUT:
            if (argc != 2) {
                cout << "Usage: put <file>" << endl;
                break;
            }
            state.put_file(argv[1]);
            break;
        case MGET:
            if (argc < 2) {
                cout << "Usage: mget <file1> <file2> ..." << endl;
                break;
            }
            cout << "mget" << endl;
            break;
        case MPUT:
            if (argc < 2) {
                cout << "Usage: mput <file1> <file2> ..." << endl;
                break;
            }
            cout << "mput" << endl;
            break;
        case DELETE:
            if (argc != 2) {
                cout << "Usage: delete <file>" << endl;
                break;
            }
            cout << "delete" << endl;
            break;
        case OPEN:
            if (argc != 2) {
                cout << "Usage: open <host>" << endl;
                break;
            }
            state.open_conn(argv[1]);
            break;
        case CLOSE:
            if (argc != 1) {
                cout << "Usage: close" << endl;
                break;
            }
            cout << "close" << endl;
            break;
        case LS:
            if (argc != 1) {
                cout << "Usage: ls" << endl;
                break;
            }
            cout << "ls" << endl;
            break;
        case CD:
            if (argc != 2) {
                cout << "Usage: cd <dir>" << endl;
                break;
            }
            cout << "cd" << endl;
            break;
        case PWD:
            if (argc != 1) {
                cout << "Usage: pwd" << endl;
                break;
            }
            cout << "pwd" << endl;
            break;
    }
}

State::State() : open_{false}, fd_{-1} { }

bool State::is_open() const {
    return this->open_;
}

int State::fd() const {
    return this->fd_;
}

void State::open_conn(string ip) {
    int client_fd;
    struct sockaddr_in serv_addr;
    string cmd;

    client_fd = create_client_fd(PORT);
    serv_addr = create_addr(ip, PORT);

    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        return;

    this->open_ = true;
    this->fd_ = client_fd;
    cout << "Connected to " << ip << endl;
}

void State::get_file(string filename) {
    if (!this->is_open()) return;
    mysend(this->fd(), "get " + filename);

    read_file(this->fd());
}

void State::put_file(string filename) {
    if (!this->is_open()) return;
    mysend(this->fd(), "put " + filename);
    
    send_file(this->fd(), filename);
}