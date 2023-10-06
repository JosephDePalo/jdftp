#include "lib/netlib.h"
#include "lib/helpers.h"
#include "lib/server_cmds.h"

using namespace std;

int main() {
    vector<thread*> thread_arr;
    while (true) {
        thread* new_thread = new thread(handle_client, get_client());
        thread_arr.push_back(new_thread);
    }

    return 0;
}