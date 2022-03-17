# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 10:06:32 by hesayah           #+#    #+#              #
#    Updated: 2022/03/17 03:12:03 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRCS =	srcs/main.c \
		srcs/check_args.c \
		srcs/pre_working.c \
		srcs/algo_utils.c \
		srcs/calibration.c \
		srcs/run.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate_up.c \
		srcs/rotate_down.c \
		srcs/clean_up.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = libft

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

all : $(NAME)
$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(LIB)
	@echo "\033[32m[Job done ;)!]"

clean :
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "\033[32m[Clean-up done]"
	

fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "\033[32m[FULL clean-up $(NAME) done]"

re : fclean all