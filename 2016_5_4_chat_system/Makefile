ROOT_PATH=$(shell pwd)
SERVER=udp_serverd
CLIENT=udp_client
CC=g++

SERVER_PATH=$(ROOT_PATH)/server
CLIENT_PATH=$(ROOT_PATH)/client

SERVER_SRC=$(shell ls $(SERVER_PATH) | egrep '*.cpp')
CLIENT_SRC=$(shell ls $(CLIENT_PATH) | egrep '*.cpp')

SERVER_OBJ=$(SERVER_SRC:.cpp=.o)
CLIENT_OBJ=$(CLIENT_SRC:.cpp=.o)

.PHONY:all
all:$(SERVER) $(CLIENT)
$(SERVER):$(SERVER_OBJ)
	$(CC) -o $@ $^
$(CLIENT):$(CLIENT_OBJ)
	$(CC) -o $@ $^

%.o:$(SERVER_PATH)/%.cpp
	$(CC) -c $<
%.o:$(CLIENT_PATH)/%.cpp
	$(CC) -c $<
.PHONY:clean
clean:
	rm -rf *.o $(SERVER) $(CLIENT) 
.PHONY:debug
debug:
	@echo $(SERVER_SRC)
	@echo $(SERVER_OBJ)
	@echo $(CLIENT_SRC)
	@echo $(CLIENT_OBJ)
