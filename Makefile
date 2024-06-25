# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:57:50 by madamou           #+#    #+#              #
#    Updated: 2024/06/25 18:43:35 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = srcs/

OBJS_DIR = .objets/

OBJS_BONUS_DIR = .objets_bonus/

SRCS_BONUS_DIR = bonus_part/

PARSING = $(addprefix parsing/, parse_map.c parse_map_utils.c parse_map_utils2.c) 

MLX = $(addprefix mlx/, so_long.c  mlx_functions.c print_image.c event.c)

SRCS = main.c  $(PARSING) $(MLX)

SRCS := $(SRCS:%=$(SRCS_DIR)/%)

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

##########################################################################################

PARSING_BONUS = $(addprefix parsing/, parse_map_bonus.c parse_map_utils_bonus.c parse_map_utils2_bonus.c) 

MLX_BONUS = $(addprefix mlx/, so_long_bonus.c  mlx_functions_bonus.c print_image_bonus.c \
			event_bonus.c enemies_bonus.c enemies2_bonus.c final_animations_bonus.c)

SRCS_BONUS = main_bonus.c  $(PARSING_BONUS) $(MLX_BONUS)

SRCS_BONUS := $(SRCS_BONUS:%=$(SRCS_BONUS_DIR)/%)

OBJS_BONUS = $(SRCS_BONUS:$(SRCS_BONUS_DIR)%.c=$(OBJS_BONUS_DIR)%.o)

DIR_DUP = mkdir -p $(@D)

NAME = so_long

BONUS = so_long_bonus

LIBFT = libft.a

LIBMLX = libmlx_Linux.a

GENERATOR = so_long_generator

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

bonus : $(LIBMLX) $(LIBFT) $(BONUS)

$(BONUS) : $(OBJS_BONUS)
	$(CC) $(C_FLAGS) $^ $(INCL) -L ./libft -lft -L ./minilibx-linux -lmlx -lX11 -lXext -o $@

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c
	$(DIR_DUP)
	$(CC) $(C_FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(GENERATOR) :
	make -C ./bonus_part/so_long_map_generator

random : $(GENERATOR) bonus
	./bonus_part/so_long_map_generator/so_long_generator 60x32 12 random.ber
	./so_long_bonus random.ber
	
clean : 
	make clean -C ./libft
	make clean -C ./bonus_part/so_long_map_generator
	make clean -C ./minilibx-linux
	rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR) random.ber

fclean : clean
	make fclean -C ./libft 
	make fclean -C ./bonus_part/so_long_map_generator
	rm -rf $(NAME) $(BONUS) $(GENERATOR)

re : fclean all

.PHONY : all clean fclean re 
