NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

SRC = philosophers.c \
	  process_part/begin_information.c \
	  process_part/process_philo.c \
	  utils/utils_0.c \
	  utils/utils_begin.c \
	  utils/utils_process_0.c \
	  utils/utils_process_1.c \
	  utils/utils_process_2.c

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} philosophers.h Makefile
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

bonus: ${NAME_BONUS}

%.o:%.c
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re