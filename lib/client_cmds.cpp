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
            if (state.get_file(argv[1]) < 0)
                cerr << "Failed to get " << argv[1] << endl;
            break;
        case PUT:
            if (argc != 2) {
                cout << "Usage: put <file>" << endl;
                break;
            }
            if (state.put_file(argv[1]) < 0)
                cerr << "Failed to put " << argv[1] << endl;
            break;
        case MGET:
            if (argc < 2) {
                cout << "Usage: mget <file1> <file2> ..." << endl;
                break;
            }
            for (int i = 1; i < argc; i++)
                if (state.get_file(argv[i]) < 0)
                    cerr << "Failed to get " << argv[i] << endl;
            break;
        case MPUT:
            if (argc < 2) {
                cout << "Usage: mput <file1> <file2> ..." << endl;
                break;
            }
            for (int i = 1; i < argc; i++)
                if (state.get_file(argv[i]) < 0)
                    cerr << "Failed to get " << argv[i] << endl;
            break;
        case DELETE:
            if (argc != 2) {
                cout << "Usage: delete <file>" << endl;
                break;
            }
            mysend(state.fd(), "delete " + argv[1]);
            break;
        case OPEN:
            if (argc != 2) {
                cout << "Usage: open <host>" << endl;
                break;
            }
            if (state.open_conn(argv[1]) < 0)
                cerr << "Failed to open connection to " << argv[1] << endl;
            break;
        case CLOSE:
            if (argc != 1) {
                cout << "Usage: close" << endl;
                break;
            }
            state.close_conn();
            break;
        case LS:
            if (argc != 1) {
                cout << "Usage: ls" << endl;
                break;
            }
            break;
        case CD:
            if (argc != 2) {
                cout << "Usage: cd <dir>" << endl;
                break;
            }
            break;
        case PWD:
            if (argc != 1) {
                cout << "Usage: pwd" << endl;
                break;
            }
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

int State::open_conn(string ip) {
    int client_fd;
    struct sockaddr_in serv_addr;
    string cmd;

    client_fd = create_client_fd(PORT);
    serv_addr = create_addr(ip, PORT);

    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Failed to connect" << endl;
        return -1;
    }

    this->open_ = true;
    this->fd_ = client_fd;
    cout << "Connected to " << ip << endl;
    return 0;
}

int State::close_conn() {
    if (!this->is_open())
        return -1;
    close(this->fd());

    this->open_ = false;
    this->fd_ = -1;
    cout << "Disconnected from server" << endl;
    return 0;
}

int State::get_file(string filename) {
    if (!this->is_open())
        return -1;
    mysend(this->fd(), "get " + filename);

    read_file(this->fd());
    return 0;
}

int State::put_file(string filename) {
    if (!this->is_open())
        return -1;
    mysend(this->fd(), "put " + filename);
    
    send_file(this->fd(), filename);
    return 0;
}