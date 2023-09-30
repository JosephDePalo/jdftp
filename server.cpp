#include "netlib.h"
#include "cmds.h"

using namespace std;

int main() {
    string output;
    int new_socket = get_client();
    cout << "Client connected" << endl;

    while (true) {
        output = myread(new_socket);
        vector<string> argv = parse(output);
        int argc = argv.size();

        if (cmd_map.find(argv[0]) == cmd_map.end())
            continue;
        
        Cmd command = cmd_map.at(argv[0]);
        
        switch(command) {
            case GET:
                if (argc != 2) {
                    cout << "Usage: get <file>" << endl;
                    break;
                }
                
                break;
            case PUT:
                if (argc != 2) {
                    cout << "Usage: put <file>" << endl;
                    break;
                }
                cout << "put" << endl;
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

    return 0;
}