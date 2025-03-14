CNAME = client
SNAME = server

BONUS_CNAME 	=	client_bonus
BONUS_SNAME 	=	server_bonus

HEAD = minitalk.h
BHEAD = minitalk_bonus.h


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = tools.c 
CLIENT_SRC = client.c
SERVER_SRC = server.c

BSRC = tools_bonus.c tools1_bonus.c
CLIENT_BSRC = client_bonus.c
SERVER_BSRC = server_bonus.c

OBJ = $(SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o) 
SERVER_OBJ = $(SERVER_SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)
CLIENT_BOBJ = $(CLIENT_BSRC:.c=.o) 
SERVER_BOBJ = $(SERVER_BSRC:.c=.o)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

%bonus.o : %bonus.c $(BHEAD)
	@ ${CC} ${CFLAGS} -c $< -o $@

all: $(CNAME) $(SNAME)

bonus: ${BONUS_CNAME} ${BONUS_SNAME}

$(CNAME): $(CLIENT_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(CLIENT_OBJ) -o $(CNAME)
	
$(SNAME): $(SERVER_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SERVER_OBJ) -o $(SNAME)

$(BONUS_CNAME): $(CLIENT_BOBJ) $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(CLIENT_BOBJ) -o $(BONUS_CNAME)
	
$(BONUS_SNAME): $(SERVER_BOBJ) $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(SERVER_BOBJ) -o $(BONUS_SNAME)
	
clean:
	$(RM) $(OBJ) $(SERVER_OBJ) $(CLIENT_OBJ) $(BOBJ) $(SERVER_BOBJ) $(CLIENT_BOBJ) 

fclean: clean
	$(RM) $(CNAME) $(SNAME) $(BONUS_CNAME) $(BONUS_SNAME)

re: fclean all