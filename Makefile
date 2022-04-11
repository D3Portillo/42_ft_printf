# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 08:06:16 by dcerrito          #+#    #+#              #
#    Updated: 2022/04/11 21:49:49 by dcerrito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/
LIBFT_NAME = libft.a
CC = gcc
PACK = ar rcs
FRM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I.
CORE_DIR = core/
CORE_FILES = \
	ft_printf.c 	\
	ft_putnbr_base.c \

CORE_OBJS = $(patsubst %.c, %.o, $(addprefix $(CORE_DIR), $(CORE_FILES)))
LIBFT_LIB = $(addprefix $(LIBFT), $(LIBFT_NAME))
$(NAME): $(CORE_OBJS)
	@make all -C $(LIBFT)
	@mv $(LIBFT_LIB) $(NAME) ||:
	$(PACK) $(NAME) $(CORE_OBJS)
all: $(NAME)
clean:
	@make clean -C $(LIBFT)
	$(FRM) $(CORE_OBJS)
fclean: clean
	make fclean -C $(LIBFT)
	$(FRM) $(NAME)
re: fclean all
.PHONY: re clean fclean all