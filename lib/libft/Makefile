#!----------------------------------------------------------------------------#
#                                NAME                                         #
#!----------------------------------------------------------------------------#

NAME= libft.a
.DEFAULT_GOAL := all
.PHONY: all clean fclean re
.SILENT:

#!----------------------------------------------------------------------------#
#                              COLORS                                         #
#!----------------------------------------------------------------------------#

CYAN = \033[0;36m
GREEN = \033[0;32m
PURPLE = \033[0;35m
RED = \033[31m
WHITE = \033[37m
YELLOW = \033[33m
RESET = \033[0m

#!----------------------------------------------------------------------------#
#                                PATH                                         #
#!----------------------------------------------------------------------------#

SRCS_PATH = src/
BUILD_DIR = obj/

#!----------------------------------------------------------------------------#
#                                FILES                                        #
#!----------------------------------------------------------------------------#

SRCS = $(addprefix $(SRCS_PATH), \
				ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isascii.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putendl_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strncmp.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strnstr.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_toupper.c \
				ft_tolower.c)
OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)

#!----------------------------------------------------------------------------#
#                             COMMANDS                                        #
#!----------------------------------------------------------------------------#

MKDIR =mkdir -p
RM = rm -rf
SLEEP = sleep 0.1
CC = cc
AR = ar -rcs

#!----------------------------------------------------------------------------#
#                                  FLAGS                                      #
#!----------------------------------------------------------------------------#

CFLAGS = -Wall -Werror -Wextra
DFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
LDLIBS = -lft -ldl -lglfw -pthread

#!----------------------------------------------------------------------------#
#                             COMPILATION                                     #
#!----------------------------------------------------------------------------#

COMP_OBJ = $(CC) $(CFLAGS) -c $< -o $@
COMP_LIB = $(AR) $(NAME) $(OBJS)

#!----------------------------------------------------------------------------#
#                             FUNCTIONS                                       #
#!----------------------------------------------------------------------------#

define create_dir
		$(MKDIR) $(dir $@)
endef

define comp_objs
		$(COMP_OBJ)
endef

define comp_lib
		$(COMP_LIB)
endef

#!----------------------------------------------------------------------------#
#                              TARGETS                                        #
#!----------------------------------------------------------------------------#

all: $(NAME)

$(BUILD_DIR)%.o: %.c
		$(call create_dir)
		$(call comp_objs)

$(NAME): $(OBJS)
		$(call comp_lib)

clean:
		$(RM) $(BUILD_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

-include $(DEPS)


