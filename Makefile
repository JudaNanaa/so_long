# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:57:50 by madamou           #+#    #+#              #
#    Updated: 2024/06/19 21:16:37 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = srcs/

PARSING = $(addprefix parsing/, parse_map.c parse_map_utils.c parse_map_utils2.c) 

SRCS = main.c  mlx_functions.c $(PARSING)

OBJS_DIR = .objets/

SRCS := $(SRCS:%=$(SRCS_DIR)/%)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

DIR_DUP = mkdir -p $(@D)

NAME = so_long

LIBFT = libft.a

LIBMLX = libmlx_Linux.a

all : $(LIBMLX) $(LIBFT) $(NAME)

$(LIBMLX) :
	make -C ./minilibx-linux

$(LIBFT) :
	make -C ./libft 

INCL = -I/usr/include -Imlx -I$(libft) -I./includes
$(NAME) : $(OBJS)
	$(CC) $(C_FLAGS) $^ $(INCL) -L ./libft -lft -L ./minilibx-linux -lmlx -lX11 -lXext -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(DIR_DUP)
	$(CC) $(C_FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean : 
	make clean -C ./libft 
	make clean -C ./minilibx-linux
	rm -rf $(OBJS_DIR)

fclean : clean
	make fclean -C ./libft 
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re 
