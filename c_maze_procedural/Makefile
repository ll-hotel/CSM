NAME = maze.exe
SRC = $(addprefix src/, main.c)

CFLAGS		:=	-Wall -Wextra -Werror
IFLAGS		:=	-Iinclude
LFLAGS		:=	


all: $(NAME) 


$(NAME): $(SRC)
	gcc $(CFLAGS) $(IFLAGS) -o $@ $(SRC) $(LFLAGS)
	

clean:
	rm $(NAME)

