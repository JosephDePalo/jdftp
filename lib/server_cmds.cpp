#include "server_cmds.h"
#include "netlib.h"
#include "helpers.h"

using namespace std;

void server_handler(string input, int target_fd) {
    ostringstream ss;
    vector<string> argv = parse(input);
    int argc = argv.size();

    if (cmd_map.find(argv[0]) == cmd_map.end())
        return;

    cout << input << endl;
    
    Cmd command = cmd_map.at(argv[0]);
    
    switch(command) {
        case GET:
            send_file(target_fd, argv[1]);
            break;
        case PUT:
            read_file(target_fd);
            break;
        case MGET:
            for (int i = 1; i < argc; i++) send_file(target_fd, argv[i]);
            break;
        case MPUT:
            for (int i = 1; i < argc; i++) read_file(target_fd);
            break;
        case DELETE:
            remove(argv[1].c_str());
            break;
        case OPEN:
            break;
        case CLOSE:
            break;
        case LS:
            ss.str("");
            for (const auto &file : ls(filesystem::current_path().u8string()))
                ss << file << " " << endl;
            mysend(target_fd, ss.str());
            break;
        case CD:
            break;
        case PWD:
            break;
    }
}

vector<string> ls(string path) {
    vector<string> files;
    for (const auto &file : filesystem::directory_iterator(path))
        files.push_back(parse(file.path().u8string(), '/').back());
    return files;
}