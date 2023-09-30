#include "lib/netlib.h"
#include "lib/client_cmds.h"

using namespace std;



int main() {
    string file_name, cmd;

    State state;

    while (true) { // Client REPL
        cout << "> ";
        getline(cin, cmd);
        client_handler(cmd, state);
    }

    return 0;
}

