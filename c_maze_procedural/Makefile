LINUX = linux/
WINDOWS = windows/
SOURCE_DIR		=	src/
LINUX_SOURCES	=	$(addprefix $(LINUX)$(SOURCE_DIR), \
					app_cleanup.c \
					app_execute.c \
					app_init.c \
					app_loop.c \
					app_log.c \
					app_on_event.c \
					app_render.c \
					main.c \
					)
WINDOWS_SOURCES	=	$(addprefix $(WINDOWS)$(SOURCE_DIR), \
					main.c \
					)

OBJECT_DIR		=	obj/
LINUX_OBJECTS	=	$(patsubst $(LINUX)$(SOURCE_DIR)%.c,$(LINUX)$(OBJECT_DIR)%.o, $(LINUX_SOURCES))
WINDOWS_OBJECTS	=	$(patsubst $(WINDOWS)$(SOURCE_DIR)%.c,$(WINDOWS)$(OBJECT_DIR)%.o, $(WINDOWS_SOURCES))

CFLAGS			:=	-Wall -Wextra -Werror
LINUX_IFLAGS	:=	-I$(LINUX)include
WINDOWS_IFLAGS	:=	-I$(WINDOWS)include
LFLAGS			:=	-lSDL2

NAME	= maze

all:
	@echo 'Choose your OS:'
	@echo ' - windows'
	@echo ' - linux'

windows: $(NAME).exe

linux: $(NAME)

$(NAME).exe: $(WINDOWS_OBJECTS)
	gcc $(CFLAGS) $(WINDOWS_IFLAGS) -o $@ $(WINDOWS_OBJECTS) $(LFLAGS)

$(NAME): $(LINUX_OBJECTS)
	gcc $(CFLAGS) $(LINUX_IFLAGS) -o $@ $(LINUX_OBJECTS) $(LFLAGS)

$(LINUX)$(OBJECT_DIR)%.o:	$(LINUX)$(SOURCE_DIR)%.c | $(OBJECT_DIR)$(LINUX)
	gcc $(CFLAGS) $(LINUX_IFLAGS) -o $@ -c $<

$(WINDOWS)$(OBJECT_DIR)%.o:	$(WINDOWS)$(SOURCE_DIR)%.c | $(OBJECT_DIR)$(WINDOWS)
	gcc $(CFLAGS) $(WINDOWS_IFLAGS) -o $@ -c $<

$(OBJECT_DIR)%:
	mkdir -p $(OBJECT_DIR)
	mkdir $@

clean:
	rm -rf $(OBJECT_DIR)

fclean:	clean
	rm -f $(NAME) $(NAME).exe

re:	fclean
	@make --no-print-directory all

