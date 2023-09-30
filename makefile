CXX      = g++
TARGET   = $(patsubst %.cpp,%,$(CXX_FILE))
DEPS = netlib.cpp cmds.cpp

all:
	$(CXX) server.cpp $(DEPS) -o server.out
	$(CXX) client.cpp $(DEPS) -o client.out
clean:
	rm -f $(TARGET) $(TARGET).exe
