##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##


GRAY		=	'\033[1;30m'
RED			=	'\033[1;31m'
GREEN 		= 	'\033[1;32m'
YELLOW		=	'\033[1;33m'
BLUE		=	'\033[1;34m'
PURPLE		=	'\033[1;35m'
CYAN		=	'\033[1;36m'
WHITE		=	'\033[1;37m'

RESET		=	'\033[0m'

NAME = libclist.a

SRC 	=	chained_list_concat.c		\
			chained_list_create.c 	\
			chained_list_data_destructor.c	\
			chained_list_destroy.c	\
			chained_list_exec.c	\
			chained_list_find.c	\
			chained_list_print.c	\
			chained_list_remove.c	\
			chained_list_build.c	\

CRIT_LIST	=	tests/test_list_init.c \
				tests/test_list_concat.c \
				tests/test_list_data_destructor.c \
				tests/test_list_destroy.c \
				tests/test_list_exec.c \
				tests/test_list_find.c \
				tests/test_list_print.c \
				tests/test_list_remove.c \
				tests/test_list_build.c \

CRIT = $(CRIT_LIST)

OBJ = 	$(SRC:%.c=%.o)

CFLAGS = -W -Wall -Wextra -Iinclude

CRITFLAGS = -lcriterion --coverage

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e '['$(BLUE)'built'$(RESET)']:'$(GRAY)' $(notdir $^) -> .o'$(RESET)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e '['$(GREEN)'Compiled'$(RESET)']'

lib: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -e '['$(GREEN)'Lib Compiled'$(RESET)']'

debug: $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS) -g3
	@echo -e '['$(GREEN)'Debug mode'$(RESET)']'

tests_run:
	@gcc -o unit-tests $(SRC) $(CRIT) $(CFLAGS) $(CRITFLAGS)
	@echo -e '['$(GREEN)'Launch tests'$(RESET)']'
	@./unit-tests

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f unit-tests
	@rm -f *~
	@rm -f #*#
	@rm -f *.gcno*
	@rm -f *.gcda*
	@echo -e '['$(YELLOW)'Cleaned'$(RESET)']'

fclean: clean
	@rm -f $(NAME)
	@echo -e '['$(YELLOW)'Fcleaned'$(RESET)']'

re: fclean all

.PHONY: all clean fclean re
