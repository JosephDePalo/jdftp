#ifndef _SERVER_CMDS_
#define _SERVER_CMDS_

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>
#include <thread>

#include "netlib.h"

void handle_client(Connection conn);
void server_handler(std::string input, int target_fd);
std::vector<std::string> ls(std::string path);

#endif