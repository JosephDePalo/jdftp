#include "netlib.h"
#include "client_cmds.h"

using namespace std;



int main() {
    string file_name, cmd;

    State state;

    while (true) {
        cout << "> ";
        getline(cin, cmd);
        handler(cmd, state);
    }

    return 0;
}

