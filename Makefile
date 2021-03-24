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

SRCS = main.c \
	instructions/swap_and_push.c \
		
OBJS = $(SRCS:%.c=%.o)

LIBFT	=	utils/libft/libft.a

NAME = checker

CFLAGS = -g -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:		
			rm -rf $(OBJS)
			cd utils/libft/ && make $@

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(LIBFT)

re:			fclean all

$(LIBFT):
			make bonus -C ./utils/libft