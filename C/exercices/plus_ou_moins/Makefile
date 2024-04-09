NAME = EXEC
CC = gcc
S_DIR = ./src/
I_DIR = ./includes
SRCS = $(S_DIR)plus_ou_moins_v1.c\
		$(S_DIR)plus_ou_moins_v2.c\
		$(S_DIR)main_plus_ou_moins.c\
		$(S_DIR)ft_strlen.c\
		$(S_DIR)ft_bzero.c

OBJS = $(SRCS:.c=.o)
RM = rm -rf

%.o :	%.c
	$(CC) -I$(I_DIR) -o $@ -c $<

$(NAME) :	$(OBJS)
	$(CC) -o $@ $^

all :	$(NAME)
		
clean:
		$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all