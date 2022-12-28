# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:57:25 by ipresno-          #+#    #+#              #
#    Updated: 2022/12/28 12:46:39 by ipresno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c actions.c stacks.c init_list.c index.c moves.c errors.c
ALGO_SRC = algorithm_utils.c big_sort.c medium_sort.c small_sort.c
OBJ_DIR = obj/
ALGO_DIR = algorithm/
ALL_SRCS = $(SRC) $(addprefix $(ALGO_DIR), $(ALGO_SRC))

OBJ_SRC = $(SRC:.c=.o)
OBJ_ALGO = $(ALGO_SRC:.c=.o)
OBJS = $(OBJ_SRC) $(OBJ_ALGO)

ALGO_PATH = $(OBJ_SRC:%=$(ALGO_DIR)%)
SRC_PATH = $(SRC) $(ALGO_PATH)

ALGO_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(OBJ_ALGO))
OBJ_PATH =		$(addprefix $(OBJ_DIR), $(OBJ_ALGO)) $(ALGO_OBJ_PATH)

CC = -Wall -Wextra -Werror

LIBFT_A = libft.a
LIBF_DIR = Libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME):
	@echo $(CURSIVE)$(GRAY) "     - Creating object directory..." $(NONE)
	@mkdir -p $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(CC) -c $(ALL_SRCS)
	@echo $(CURSIVE)$(GRAY) "     - Moving object files to $(OBJ_DIR)..." $(NONE)	
	@mv $(OBJS) $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling Libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(CC) $(LIBFT) $(addprefix $(OBJ_DIR), $(OBJS)) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBF_DIR) clean
	@echo "   - Clean"

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean
	@echo "   - All clean" $(NONE)

re: fclean all

.PHONY: clean fclean all re