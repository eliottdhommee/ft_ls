# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edhommee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:49:17 by edhommee          #+#    #+#              #
#*   Updated: 2017/07/24 14:48:08 by edhommee         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME 		= ft_ls

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src/
SRC_NAME	= main.c compare.c dir_tools.c init.c
:q
SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_NAME:.c=.o))

INCLUDES	=  -I ./includes

LIB_DIR		= ./libft/
LIBFT		= $(LIB_DIR)libft.a
LIB_LINK	= -Llibft -lft

all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIB_LINK) -o $(NAME) $(OBJ) -fsanitize=address

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
