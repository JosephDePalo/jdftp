#ifndef _CLIENT_CMDS_
#define _CLIENT_CMDS_

/*
get: copy file from remote sever to local machine
put: copy file from local machine to remote server
mget: copy multiples files fro remote server to local machine
mput: copy multiple files from local machine to remote server
delete: delete a file in the current remote directory
open: open a connection with remote server
close: terminate connection with remote server
ls: list the names of files in the current remote directory
cd: change directory on remote server
pwd: print current directory on remote server
*/

#include <string>
#include <iostream>

class State {
private:
    bool open_;
    int fd_;
public:
    State();
    bool is_open() const;
    int fd() const;
    void open_conn(std::string ip);
    void get_file(std::string filename);
    void put_file(std::string filename);

};

void client_handler(std::string input, State& state);

#endif