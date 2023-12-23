NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_dectohex.c \
	  ft_putnbr.c \
	  ft_putunbr.c

OBJECTS = ${SOURCES:.c=.o}

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

all : ${NAME}

clean :
	rm -rf ${OBJECTS}

fclean : clean
	rm -rf ${NAME}

re : fclean all
