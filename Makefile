NAME= minitalk
SERVER= server
CLIENT= client
SERVER_B= server_bonus
CLIENT_B= client_bonus
CC= cc
CFLAGS= -Wextra -Werror -Wall

###	MANDATORY ###
SRC_SERVER= src/mt_server.c
SRC_CLIENT= src/mt_client.c
SRC_UTILS=  src/mt_utils.c

OBJ_SERVER= $(SRC_SERVER:.c=.o)
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)
OBJ_UTILS= $(SRC_UTILS:.c=.o)

###	BONUS ###
SRC_SERVER_B= src/mt_server_bonus.c
SRC_CLIENT_B= src/mt_client_bonus.c
SRC_UTILS_B=  src/mt_utils_bonus.c

OBJ_SERVER_B= $(SRC_SERVER_B:.c=.o)
OBJ_CLIENT_B= $(SRC_CLIENT_B:.c=.o)
OBJ_UTILS_B= $(SRC_UTILS_B:.c=.o)


all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o $(SERVER)

bonus: $(SERVER_B) $(CLIENT_B)

$(CLIENT_B): $(OBJ_CLIENT_B) $(OBJ_UTILS_B)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_B) $(OBJ_UTILS_B) -o $(CLIENT_B)

$(SERVER_B): $(OBJ_SERVER_B) $(OBJ_UTILS_B)
	$(CC) $(CFLAGS) $(OBJ_SERVER_B) $(OBJ_UTILS_B) -o $(SERVER_B)

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS) $(OBJ_UTILS_B) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re: fclean all

.PHONY: all clean fclean re
