#include "server_cmds.h"
#include "netlib.h"
#include "helpers.h"

using namespace std;

void server_handler(string input, int target_fd) {
    vector<string> argv = parse(input);
    int argc = argv.size();

    if (cmd_map.find(argv[0]) == cmd_map.end())
        return;
    
    Cmd command = cmd_map.at(argv[0]);
    
    switch(command) {
        case GET:
            cout << "get " << argv[1] << endl;
            send_file(target_fd, argv[1]);
            break;
        case PUT:
            cout << "put" << argv[1] << endl;
            read_file(target_fd);
            break;
        case MGET:
            cout << "mget" << endl;
            break;
        case MPUT:
            cout << "mput" << endl;
            break;
        case DELETE:
            cout << "delete" << endl;
            break;
        case OPEN:
            break;
        case CLOSE:
            cout << "close" << endl;
            break;
        case LS:
            cout << "ls" << endl;
            break;
        case CD:
            cout << "cd" << endl;
            break;
        case PWD:
            cout << "pwd" << endl;
            break;
    }
}