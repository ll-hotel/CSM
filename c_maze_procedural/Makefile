MAKE	:=	@make --no-print-directory
CC		:=	gcc

WINDOWS	:=	windows/
LINUX	:=	linux/

SOURCE_DIR	=	$(SYSTEM)src/
OBJECT_DIR	=	$(SYSTEM).obj/

WINDOWS_SOURCES	:=	main.c

LINUX_SOURCES	:=	app_cleanup.c \
					app_execute.c \
					app_init.c \
					app_loop.c \
					app_log.c \
					app_on_event.c \
					app_render.c \
					main.c

OBJECTS			=	$(patsubst %.c,$(OBJECT_DIR)%.o, $(SOURCES))
DEPS			=	$(OBJECTS:.o=.d)

CFLAGS		:=	-Wall -Wextra -Werror
IFLAGS		=	-I$(SYSTEM)include
LFLAGS		:=	-lSDL2

NAME		=	maze

.PHONY: all
all:
ifeq ("$(SYSTEM)","")
	@echo -e "Choose your system:\n - windows\n - linux"
else
	$(MAKE) $(NAME)
endif

-include $(DEPS)

.PHONY: windows
windows:
	$(MAKE) SYSTEM=$(WINDOWS) SOURCES="$(WINDOWS_SOURCES)" NAME=$(NAME).exe

.PHONY: linux
linux:
	$(MAKE) SYSTEM=$(LINUX) SOURCES="$(LINUX_SOURCES)"

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJECTS) $(LFLAGS)

$(OBJECT_DIR)%.o:	$(SOURCE_DIR)%.c | $(OBJECT_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(OBJECT_DIR):
	mkdir -p $@

.PHONY: clean
clean:
ifneq ("$(wildcard $(LINUX)$(OBJECT_DIR))","")
	rm -rf $(LINUX)$(OBJECT_DIR)
endif
ifneq ("$(wildcard $(WINDOWS)$(OBJECT_DIR))","")
	rm -rf $(WINDOWS)$(OBJECT_DIR)
endif

.PHONY: fclean
fclean:	clean
	rm -f $(NAME) $(NAME).exe

.PHONY: re
re:	fclean
	$(MAKE) all
