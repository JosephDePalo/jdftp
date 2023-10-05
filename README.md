# [JDFTP](https://github.com/JosephDePalo/jdftp)
A simple FTP server and client in C++, written as a learning project. Everything is built from scratch.

## Installation
To compile the server and client, you simply have to clone this repository and then run make.
```bash
git clone https://github.com/JosephDePalo/jdftp
cd jdftp
make
```

## Usage
### Server
To run the server, run `./server.out` after compiling. This will run the server on the default port 1234.

### Client
To run the client, run `./client.out` after compiling. This will put you into the client shell. To connect to
a server, run `open <ip>`. After this you can perform basic FTP commands such as `get` and `put`. To see a list
of implemented commands, see [below](#implemented-commands).

## Implemented Commands
- `open <ip>`: Connects to the server at the given IP address.
- `close`: Closes the connection to the server.
- `get <file>`: Downloads the given file from the server.
- `put <file>`: Uploads the given file to the server.
- `mget <file> <file> ...`: Downloads multiple files from the server.
- `mput <file> <file> ...`: Uploads multiple files to the server.
- `delete <file>`: Deletes the given file from the server.
- `ls`: Lists the files in the current directory on the server.
- `cd <dir>`: Changes the current directory on the server.
- `pwd`: Prints the current directory on the server.


## TODO
- [X] Implement `ls` command.
- [X] Implement `cd` command.
- [ ] Implement `mkdir` command.
- [ ] Implement `rmdir` command.
- [X] Implement `pwd` command.
- [ ] Implement `rename` command.
- [ ] Implement `help` command.
- [ ] Implement user authentication.
- [ ] Implement file permissions.
- [ ] Implement file locking.
- [ ] Implement file authentication.
- [ ] Implement file encryption.
- [ ] Implement multi-threading for concurrent connections.
- [ ] Implement multi-threading for concurrent file transfers.