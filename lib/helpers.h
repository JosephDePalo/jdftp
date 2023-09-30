#ifndef _HELPERS_
#define _HELPERS_

#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>

enum Cmd {GET, PUT, MGET, MPUT, DELETE, OPEN, CLOSE, LS, CD, PWD};
std::unordered_map<std::string,Cmd> const cmd_map = {
    {"get", GET}, {"put", PUT}, {"mget", MGET}, {"mput", MPUT},
    {"delete", DELETE}, {"open", OPEN}, {"close", CLOSE}, {"ls", LS},
    {"cd", CD}, {"pwd", PWD}
};

std::vector<std::string> parse(std::string raw_input);

#endif