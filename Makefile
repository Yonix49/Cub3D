# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:25:26 by mhajji-b          #+#    #+#              #
#    Updated: 2023/09/27 13:50:23 by mhajji-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJS_DIR = objs
SRCS_DIR = $(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir))
SRCS =	mlx_init.c\
		calcul.c\
		get_player_pos.c\
		set_images.c\
		display.c\
		key_press.c\
		free1.c\
		get_next_line.c\
		get_next_line_utils.c\
		check_colors.c\
		check_compass.c\
		get_maps.c\
		map_parsing.c\
		map_parsing_2.c\
		parsing2.c\
		path_finding.c\
		classique_utils.c\
		ft_split.c\
		utils_1.c\
		utils_2.c\
		utils_3.c\
		utils_4.c\
		utils_5.c\
		utils_6.c\
		cub3D.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

DEPS = $(OBJS:.o=.d)

NAME = cub3D
NORM = norminette

########################### COMPILATION AND FLAGS ###########################

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -MMD #-fsanitize=address

##################################### COLOR ##################################

COLOUR_PURPLE = \033[0;35m
COLOUR_END = \033[0m

##################################### MAIN ###################################

all: $(NAME)

##################################### MANDATORY ##############################

-include $(DEPS)

$(NAME): $(OBJS)
	cd minilibx-linux && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/
	@echo "\033[1;32mCompilation terminée avec succès.\033[0m"

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $<

$(OBJS_DIR):
	mkdir -p $@
	@echo "\n\t$(COLOUR_PURPLE)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

clean:
	cd minilibx-linux && make clean
	$(RM) $(OBJS) $(OBJSBONUS) $(DEPS)

fclean: clean
	$(RM) $(NAME) $(BONUS) $(DEPS)

norm:
	@echo "$(COLOUR_PURPLE)***CHECK NORM FILES***$(COLOUR_END)"
	@$(NORM)
	
re: fclean all

.PHONY: all clean fclean re