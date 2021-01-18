SRC = algorithm.c print_space.c value_processing.c kernel.c init_tripple.c main.c store_data.c sort_struct.c check_data.c checkout_dict.c fill_numbers_data.c free_function.c ft_putstr.c ft_split.c check_value.c to_alg.c 

HED = ft.h

OBJ = ${SRC:.c=.o}

NAME = rush-02

GCC = @gcc -Wall -Wextra -Werror

RM = @rm -f

.c.o: 
	${GCC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${GCC} -o ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader *.c

re: fclean all

.PHONY: all clean fclean re
