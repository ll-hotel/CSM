NAME	= maze
SRC		= $(addprefix src/, main.c)

CFLAGS	:=	-Wall -Wextra -Werror
IFLAGS	:=	-Iinclude
LFLAGS	:=	


all:
	@echo 'Choose your OS:'
	@echo ' - windows'
	@echo ' - linux'

windows: $(NAME).exe

linux: $(NAME)

$(NAME).exe: $(SRC)
	gcc $(CFLAGS) $(IFLAGS) -o $@ $(SRC) $(LFLAGS)

$(NAME): $(SRC)
	gcc $(CFLAGS) $(IFLAGS) -o $@ $(SRC) $(LFLAGS)

clean:
	rm -f $(NAME) $(NAME).exe
