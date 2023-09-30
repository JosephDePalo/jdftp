CXX      = g++
TARGET   = $(patsubst %.cpp,%,$(CXX_FILE))
DEPS = lib/netlib.cpp lib/helpers.cpp

all:
	$(CXX) server.cpp $(DEPS) lib/server_cmds.cpp -o server.out
	$(CXX) client.cpp $(DEPS) lib/client_cmds.cpp -o client.out
clean:
	rm -f $(TARGET).out
