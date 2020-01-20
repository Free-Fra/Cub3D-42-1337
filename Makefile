# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 19:39:32 by mlasrite          #+#    #+#              #
#    Updated: 2020/01/20 14:25:17 by mlasrite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = cub3d.c Utils/bitmap.c Raycasting/drawing.c  Raycasting/sprite.c Utils/ft_split.c Utils/get_info.c Utils/get_next_line_utils.c \
		Utils/get_next_line.c Raycasting/hori_verti.c Raycasting/calcul_wall.c Configuration/config_1.c \
		Configuration/config_2.c Configuration/config_3.c Configuration/config_4.c Utils/get_info_sprite.c \
		Configuration/config_5.c cub3d_2.c

OBJS = cub3d.o bitmap.o drawing.o ft_split.o get_info.o sprite.o get_next_line_utils.o \
		get_next_line.o hori_verti.o calcul_wall.o config_1.o \
		config_2.o config_3.o config_4.o get_info_sprite.o config_5.o cub3d_2.o

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c  $(SRCS) 
	gcc $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
