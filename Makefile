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

NAME = my_paint

SRC_ALL =	main.c					\
			src/window_manager.c	\
			src/event_manager.c		\
			src/resize.c			\
			src/text_color.c		\
			src/text_tool.c			\
			src/new_cursor.c		\

SRC_BUTTON = src/button/button_manager.c	\
			src/button/click_menu.c 		\
			src/button/click_file.c	\
			src/button/click_brush_tool.c \
			src/button/click_brush.c \
			src/button/hover.c		\
			src/button/button_creation.c \
			src/button/sub_button_creation.c \
			src/button/save_manager.c \
			src/button/color_menu_creation.c \
			src/button/click_color_rg.c \
			src/button/click_color_ba.c \
			src/button/click_help.c \
			src/button/open_file.c 		\

SRC_CANVAS = src/canvas/canvas_display.c		\
			src/canvas/brush_create.c		\
			src/canvas/canvas_create.c	\
			src/canvas/canvas_draw.c 		\
			src/canvas/canvas_fill.c 		\
			src/canvas/canvas_modules.c 	\
			src/canvas/get_corners.c 		\
			src/canvas/pixel_color.c 		\
			src/canvas/pixel_manip.c 		\
			src/canvas/spectrum.c 	\
			src/canvas/canvas_draw_test.c 	\

SRC_STRING =	src/strings/my_strlen.c		\
				src/strings/my_strcmp.c		\
				src/strings/string_main.c	\
				src/strings/my_strcat.c		\
				src/strings/nbr_to_str.c	\

SRC_MATH = src/math/math_modules.c \
			src/math/math_pow_sqrt.c \

SRC_LIST =	src/lists/chained_list_concat.c		\
			src/lists/chained_list_create.c 	\
			src/lists/chained_list_data_destructor.c	\
			src/lists/chained_list_destroy.c	\
			src/lists/chained_list_exec.c	\
			src/lists/chained_list_find.c	\
			src/lists/chained_list_print.c	\
			src/lists/chained_list_remove.c	\
			src/lists/chained_list_build.c	\

CRIT_LIST	=	tests/list/test_list_init.c \
				tests/list/test_list_concat.c \
				tests/list/test_list_data_destructor.c \
				tests/list/test_list_destroy.c \
				tests/list/test_list_exec.c \
				tests/list/test_list_find.c \
				tests/list/test_list_print.c \
				tests/list/test_list_remove.c \
				tests/list/test_list_build.c \

CRIT_STRING	=	 \

SRC_PAINT = $(SRC_ALL) $(SRC_BUTTON) $(SRC_CANVAS)
SRC = $(SRC_PAINT) $(SRC_LIST) $(SRC_STRING) $(SRC_MATH)

SRC_CRIT = $(SRC_LIST) $(SRC_STRING)

CRIT = $(CRIT_LIST) $(CRIT_STRING)

OBJ = 	$(SRC:%.c=%.o)

CFLAGS = -W -Wall -Wextra -Iinclude

LDFLAGS = -lcsfml-graphics -lcsfml-system -lm

CRITFLAGS = -lcriterion --coverage

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e '['$(BLUE)'built'$(RESET)']:'$(GRAY)' $(notdir $^) -> .o'$(RESET)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e '['$(GREEN)'Compiled'$(RESET)']'

debug: $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS) -g3
	@echo -e '['$(GREEN)'Debug mode'$(RESET)']'

tests_run:
	@gcc -o unit-tests $(SRC_CRIT) $(CRIT) $(CFLAGS) $(CRITFLAGS)
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
