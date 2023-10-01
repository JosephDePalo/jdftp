#include "lib/netlib.h"
#include "lib/helpers.h"
#include "lib/server_cmds.h"

using namespace std;

int main() {
    string output;
    int new_socket = get_client();
    cout << "Client connected" << endl;

    while (true) {
        output = myread(new_socket);
        server_handler(output, new_socket);
    }

    return 0;
}