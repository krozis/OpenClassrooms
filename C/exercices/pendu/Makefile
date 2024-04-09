NAME = EXEC
CC = gcc
S_DIR = ./src/
L_DIR = ./src/lib/
I_DIR = ./includes
SRCS =	$(L_DIR)ft_alpha_test.c\
		$(L_DIR)ft_bzero.c\
		$(L_DIR)ft_empty_buff.c\
		$(L_DIR)ft_putstr.c\
		$(L_DIR)ft_strdup.c\
		$(L_DIR)ft_strlen.c\
		$(L_DIR)ft_toupper.c\
		$(S_DIR)main_pendu.c\
		$(S_DIR)pendu.c\
		$(S_DIR)one_player.c\
		$(S_DIR)two_players.c\
		$(S_DIR)play_game.c\
		$(S_DIR)display_pendu.c

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