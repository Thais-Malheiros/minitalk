#!----------------------------------------------------------------------------#
#                                NAME                                         #
#!----------------------------------------------------------------------------#

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
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

SRCS_PATH = ./src/
BONUS_PATH = ./bonus/
INCS_PATH = ./include/ ./lib/libft/ ./lib/ft_printf/
BUILD_DIR := ./obj/
LIBFT_DIR := ./lib/libft/
FT_PRINTF_DIR := ./lib/ft_printf/

#!----------------------------------------------------------------------------#
#                               DEFINE                                        #
#!----------------------------------------------------------------------------#

ifdef WITH_BONUS
		NAME_CLIENT := $(NAME_CLIENT_BONUS)
		NAME_SERVER := $(NAME_SERVER_BONUS)
		OBJS := $(OBJS_BONUS)
endif

#!----------------------------------------------------------------------------#
#                                FILES                                        #
#!----------------------------------------------------------------------------#

SRC_CLIENT = $(addprefix $(SRCS_PATH), client.c)
SRC_SERVER = $(addprefix $(SRCS_PATH), server.c)
SRCS_BONUS = $(addprefix $(BONUS_PATH), client_bonus.c server_bonus.c)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), ft_printf.a)
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(BUILD_DIR)%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=$(BUILD_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)
OBJS = $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJS_BONUS)
DEPS = $(OBJS:.o=.d)

#!----------------------------------------------------------------------------#
#                             COMMANDS                                        #
#!----------------------------------------------------------------------------#

MKDIR = mkdir -p
RM = rm -rf
SLEEP = sleep 0.1
CC = cc

#!----------------------------------------------------------------------------#
#                                  FLAGS                                      #
#!----------------------------------------------------------------------------#

CFLAGS = -Wall -Werror -Wextra -g3
DFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
CPPFLAGS = $(addprefix -I ,$(INCS_PATH)) -MMD -MP
LDLIBS = $(LIBFT_DIR)libft.a $(FT_PRINTF_DIR)ft_printf.a
LDFLAGS = -ldl -lglfw -pthread

#!----------------------------------------------------------------------------#
#                             COMPILATION                                     #
#!----------------------------------------------------------------------------#

COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE_CLIENT = $(CC) $(LDFLAGS) $(OBJ_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)
COMP_EXE_SERVER = $(CC) $(LDFLAGS) $(OBJ_SERVER) $(LDLIBS) -o $(NAME_SERVER)

#!----------------------------------------------------------------------------#
#                             FUNCTIONS                                       #
#!----------------------------------------------------------------------------#

define create_dir
		$(MKDIR) $(dir $@)
endef

define bonus
		$(MAKE) WITH_BONUS=TRUE
endef

define comp_objs
		$(COMP_OBJ)
endef

define comp_libft
		printf "$(CYAN)Building libft files\n$(RESET)"
		$(MAKE) -C $(LIBFT_DIR)
endef

define comp_ft_printf
		printf "$(CYAN)Building ft_printf files\n$(RESET)"
		$(MAKE) -C $(FT_PRINTF_DIR)
endef

define comp_exe_client
		$(COMP_EXE_CLIENT)
		printf "$(PURPLE)CLIENT-> $(RESET)$(GREEN)Ready!\n$(RESET)"
endef

define comp_exe_server
		$(COMP_EXE_SERVER)
		printf "$(PURPLE)SERVER-> $(RESET)$(GREEN)Ready!\n$(RESET)"
endef

#!----------------------------------------------------------------------------#
#                              TARGETS                                        #
#!----------------------------------------------------------------------------#

all: $(LIBFT) $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(BUILD_DIR)%.o: %.c
		$(call create_dir)
		$(call comp_objs)

$(NAME_CLIENT): $(OBJ_CLIENT)
		$(call comp_exe_client)

$(NAME_SERVER): $(OBJ_SERVER)
		$(call comp_exe_server)

$(LIBFT):
		$(call comp_libft)

$(FT_PRINTF):
		$(call comp_ft_printf)

clean:
		$(RM) $(BUILD_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)
		$(RM) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

bonus: $(LIBFT) $(FT_PRINTF)
		$(call bonus)

-include $(DEPS)


