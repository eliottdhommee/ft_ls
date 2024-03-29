# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edhommee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:49:17 by edhommee          #+#    #+#              #
#*   Updated: 2017/08/20 16:42:04 by edhommee         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME 		= ft_ls

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src/
SRC_NAME	= cmp.c cmptime.c dir_tools.c get_long.c get_rights.c init.c main.c\
			  print.c stat_getters.c
SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_NAME:.c=.o))

INCLUDES	=  -I ./includes -I ./libft/includes

LIB_DIR		= ./libft/
LIBFT		= $(LIB_DIR)libft.a
LIB_LINK	= -Llibft -lft

all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIB_LINK) -o $(NAME) $(OBJ)

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
