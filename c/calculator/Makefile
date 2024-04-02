CC			:=	gcc

INCLUDE_DIR	:=	include/
SOURCE_DIR	:=	src/
OBJECT_DIR	:=	obj/
CFLAGS		:=	-Wall -Wextra -Werror
IFLAGS		:=	-I$(INCLUDE_DIR)
LFLAGS		:=	-lm

INCLUDES	:=	$(addprefix $(INCLUDE_DIR), calculator.h)
SOURCES		:=	$(addprefix $(SOURCE_DIR), main.c)
OBJECTS		:=	$(patsubst $(SOURCE_DIR)%.c,$(OBJECT_DIR)%.o, $(SOURCES))

NAME		:=	calculator

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJECT_DIR) $(OBJECTS) Makefile $(INCLUDES)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJECTS) $(LFLAGS)

$(OBJECT_DIR):
	mkdir $@

$(OBJECT_DIR)%.o:	$(SOURCE_DIR)%.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean		:
	rm -f $(OBJECTS)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean
	make --no-print-directory $(NAME)
