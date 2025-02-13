NAME= minitalk
SERVER= server
CLIENT= client
CC= cc
CFLAGS= -Wextra -Werror -Wall

SRC_SERVER= src/mt_server.c
SRC_CLIENT= src/mt_client.c
SRC_UTILS=  src/mt_utils.c

OBJ_SERVER= $(SRC_SERVER:.c=.o)
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)
OBJ_UTILS= $(SRC_UTILS:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o $(SERVER)

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
