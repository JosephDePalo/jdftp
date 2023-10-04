#include "helpers.h"

using namespace std;

vector<string> parse(string raw_input, char delimiter) {
    stringstream ss(raw_input);
    vector<string> argv;
    string arg;

    while (ss.good()) {
        getline(ss, arg, delimiter);
        argv.push_back(arg);
    }

    return argv;
}

