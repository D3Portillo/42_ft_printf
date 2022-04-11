# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 08:06:16 by dcerrito          #+#    #+#              #
#    Updated: 2022/04/11 16:53:54 by dcerrito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
NAME = libftprintf.a
CC = gcc
PACK = ar rcs
FRM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I.
CORE_DIR = core/
CORE_FILES = \
	ft_printf.c
CORE_OBJS = $(patsubst %.c, %.o, $(addprefix $(CORE_DIR), $(CORE_FILES)))
$(NAME): $(CORE_OBJS)
	$(PACK) $(NAME) $(CORE_OBJS)
all: $(NAME)
clean:
	make clean -C $(LIBFT)
	$(FRM) $(CORE_OBJS)
fclean: clean
	make fclean -C $(LIBFT)
	$(FRM) $(NAME)
re: fclean all
.PHONY: re clean fclean all