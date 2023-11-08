CC				= gcc 
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -pthread -g3	-I./includes 
NAME 	= philo
SRCS	= ./srcs/philo/philosophers.c ./srcs/parsing/parsing.c ./srcs/utils/philosophers_utils.c \
			./srcs/philo/init.c ./srcs/utils/free_utils.c \

OBJS 	= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
				$(RM) $(OBJS)
				 
fclean:	 		clean
				$(RM) $(NAME)

	
re:				fclean all

.PHONY:			all clean fclean re