NAME		=	philo
SRC			=	main.c \
				philo.c \
				threads.c \
				utils.c \

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRC:%.c=%.o)
INCLUDES	=	-I ./philo.h

RM			= 	rm -rf

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(NAME): $(OBJS) ./philo.h
	$(info Compiling philo...)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)
	@echo "\033[0;32mAll done ! Have fun philosophing !\033[0m"

clean:
	$(info Cleaning up...)
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft