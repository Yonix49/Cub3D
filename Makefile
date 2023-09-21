# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:25:26 by mhajji-b          #+#    #+#              #
#    Updated: 2023/09/21 15:40:05 by mhajji-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./SRCS

SRCS = cub3D.c ft_split.c get_map.c get_next_line_utils.c get_next_line.c parsing.c parsing2.c \
       parsing3.c utils_1.c utils_2.c utils_3.c check_colors.c classique_utils.c get_maps.c check_compass.c \
       free_all/free1.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

NAME = cub3D

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cd minilibx-linux && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/
	@echo "\033[1;32mCompilation terminée avec succès.\033[0m"

clean:
	cd minilibx-linux && make clean
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
