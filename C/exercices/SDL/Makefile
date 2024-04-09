NAME = EXEC
CC = gcc
CFLAGS = -lSDL2
S_DIR = ./src/
L_DIR = ./src/lib/
I_DIR = ./includes
SRCS =	$(S_DIR)SDL_main.c\
		$(S_DIR)SDL_test.c

OBJS = $(SRCS:.c=.o)
RM = rm -rf

%.o :	%.c
	$(CC) -I$(I_DIR) -o $@ -c $< 

$(NAME) :	$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

all :	$(NAME)
		
clean:
		$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all