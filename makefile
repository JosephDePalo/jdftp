CXX      = g++
TARGET   = $(patsubst %.cpp,%,$(CXX_FILE))

all:
	$(CXX) server.cpp netlib.cpp -o server.out
	$(CXX) client.cpp netlib.cpp -o client.out
clean:
	rm -f $(TARGET) $(TARGET).exe
