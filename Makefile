TARGET	= cryptopals
SRC	= $(wildcard source/set1/*.c)
COM	= $(wildcard common/*.c)
INC	= ./include/
OBJ	= $(FILES:.c=.o)
CC	= gcc
CFLAGS  = -Wall -Wextra

.PHONY = all clean fclean re

all: $(TARGET)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(TARGET)
	@rm -f a.out

re: fclean all

$(TARGET):
	@$(CC) $(CFLAGS) $(SRC) $(COM) -I $(INC)
