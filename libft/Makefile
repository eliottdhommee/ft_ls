# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edhommee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:49:17 by edhommee          #+#    #+#              #
#*   Updated: 2017/05/21 00:03:06 by edhommee         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src/
SRC_NAME	= ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_atoi.c\
		ft_strdup.c ft_strclr.c ft_putendl.c ft_putnbr.c ft_strcpy.c\
		ft_strncpy.c ft_strcat.c ft_memset.c ft_bzero.c ft_isdigit.c\
		ft_memcpy.c ft_memccpy.c ft_isalpha.c ft_isalnum.c ft_toupper.c\
		ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
		ft_strncmp.c ft_striter.c ft_itoa.c ft_strstr.c ft_strnstr.c\
		ft_memcmp.c ft_memmove.c ft_memchr.c ft_strncat.c ft_strchr.c\
		ft_strrchr.c ft_isascii.c ft_isprint.c ft_strlcat.c ft_strsub.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
		ft_strmap.c ft_striteri.c ft_strequ.c ft_strnequ.c ft_strjoin.c\
		ft_strmapi.c ft_strsplit.c ft_strtrim.c ft_lstnew.c ft_lstdelone.c\
		ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_reverse.c\
		ft_memcpy_rev.c get_next_line.c ft_printf.c pf_buffering.c\
		pf_charstostr.c pf_convgetters.c pf_convtobuffer.c pf_init.c\
		pf_nbrtostr.c pf_normaltobuffer.c pf_putconvtobuffer.c pf_setapos.c\
		pf_setprecision.c pf_toolkit.c ft_wchartoa.c ft_itoa_base.c\
		ft_strlowcase.c ft_strndup.c

SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_NAME:.c=.o))

INCLUDES	= -I ./includes/

all: $(NAME)

$(NAME): obj $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

obj:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/ft_printf/

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
