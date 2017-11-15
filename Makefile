TARGET	= cryptopals
SRC	= main.c crypto.c
INC	= inc/
OBJ	= $(FILES:.c=.o)
CC	= gcc
CFLAGS  = -Wall -Werror -Wextra

.PHONY = all clean fclean re

all: $(TARGET)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(TARGET)

re: fclean all

$(TARGET):
	@$(CC) $(CFLAGS) $(SRC) -I $(INC)
