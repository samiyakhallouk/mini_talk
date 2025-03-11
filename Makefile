CLIENT_NAME = client
SERVER_NAME = server
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = cc
SRC = tools.c 
CLIENT_SRC = client.c
SERVER_SRC = server.c
OBJ = $(SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o) 
SERVER_OBJ = $(SERVER_SRC:.c=.o)
HEAD = minitalk.h


%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(CLIENT_OBJ) -o $(CLIENT_NAME)
	
$(SERVER_NAME): $(SERVER_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SERVER_OBJ) -o $(SERVER_NAME)
	
clean:
	$(RM) $(OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: clean fclean