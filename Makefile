TARGET	= cryptopals
SRC	= main.c crypto.c
OBJ	= $(FILES:.c=.o)
CC	= gcc
CFLAGS  = -Wall -Werror -Wextra

.PHONY = all clean fclean re

all: $(NAME)

clean:
	@rm -rf ./bin

fclean:
	@rm -f $(TARGET)

re: fclean all

$(NAME):
	@mkdir -p ./bin
	@$(CC) $(CFLAGS) -c $^
	@ar rc $@ *.o
	@ranlib $@
	@mv *.o ./bin
