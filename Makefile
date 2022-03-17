# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 10:06:32 by hesayah           #+#    #+#              #
#    Updated: 2022/03/17 16:57:18 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

NAME_BONUS = checker

SRCS =	srcs/main.c \
		srcs/check_args.c \
		srcs/little_algo.c \
		srcs/pre_working.c \
		srcs/algo_utils.c \
		srcs/calibration.c \
		srcs/run.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate_up.c \
		srcs/rotate_down.c \
		srcs/clean_up.c \

SRCS_BONUS =	srcs/checker/main_checker.c \
				srcs/checker/checker.c \
				srcs/checker/gnl/get_next_line.c \
				srcs/checker/gnl/get_next_line_utils.c \
				srcs/checker/ss.c \
				srcs/checker/pa_pb.c \
				srcs/checker/rr.c \
				srcs/checker/rrr.c \
				srcs/check_args.c \
				srcs/little_algo.c \
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

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = libft

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

all : $(NAME)
	$(MAKE) -C $(LIBFT_PATH)
$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(LIB)
	@echo "\033[32m[Job done ;)!]"

bonus : $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_PATH)
$(NAME_BONUS):$(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(FLAGS) $(LIB)
	@echo "\033[32m[Cheker done ;)!]"

clean :
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "\033[32m[Clean-up done]"
	

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "\033[32m[FULL clean-up done]"

re : fclean all