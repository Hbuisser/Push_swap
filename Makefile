# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 20:05:16 by hbuisser          #+#    #+#              #
#    Updated: 2021/03/02 14:47:46 by hbuisser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CHECKER = main_checker.c \
	instructions/push.c \
	instructions/swap.c \
	instructions/rotate.c \
	instructions/reverse.c \
	utils.c \
		
OBJS_CHECKER = $(SRCS_CHECKER:%.c=%.o)

SRCS_PUSH = main_push.c \
	algo_push.c \
	instructions/push.c \
	instructions/swap.c \
	instructions/rotate.c \
	instructions/reverse.c \
	hard.c \
	utils.c \
		
OBJS_PUSH = $(SRCS_PUSH:%.c=%.o)

NAME_CHECKER = checker
NAME_PUSH = push_swap

LIBFT =	utils/libft/libft.a
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME_CHECKER) $(NAME_PUSH)

$(NAME_CHECKER): $(OBJS_CHECKER) $(LIBFT)
	gcc $(CFLAGS) -o $(NAME_CHECKER) $(OBJS_CHECKER) $(LIBFT)

$(NAME_PUSH): $(OBJS_PUSH) $(LIBFT)
	gcc $(CFLAGS) -o $(NAME_PUSH) $(OBJS_PUSH) $(LIBFT)

clean:		
	rm -rf $(OBJS_CHECKER)
	rm -rf $(OBJS_PUSH)
	cd utils/libft/ && make $@

fclean:	clean
	rm -rf $(NAME_CHECKER)
	rm -rf $(NAME_PUSH)
	rm -rf $(LIBFT)

re: fclean all

$(LIBFT):
	make bonus -C ./utils/libft