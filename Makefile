# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 17:03:19 by kwang             #+#    #+#              #
#    Updated: 2021/10/26 17:03:22 by kwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/main.c \
		src/map_parser.c \
		src/map_utils.c \
		src/file_validator.c \
		src/error_handler.c \
		src/mlx_handler.c \
		src/initializers.c \
		src/utils.c \
		src/render_utils.c \
		src/cache_utils.c \
		src/player_cache_handler.c \
		src/static_cache_handler.c \
		src/player_handler.c \
		src/key_handler.c \
		src/image_selector.c \
		src/offset_handler.c \
		src/display.c \
		src/ss_handler.c \
		src/ss_utils.c \
		src/movement_utils.c \
		src/mapping_handler.c \
		src/collection_handler.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I/usr/include/ -Imlx_linux

MLXFLAGS = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lbsd

INCLUDES = includes

LIBFTDIR = libft

LIBFT = $(LIBFTDIR)/libft.a

MLX = mlx_linux/libmlx_Linux.a

NAME = so_long

all : $(NAME)

$(LIBFT) :
	@make -C $(LIBFTDIR) all

$(MLX) :
	@make -C mlx_linux

$(NAME) : $(OBJS) $(INCLUDES)/so_long.h $(LIBFT) $(MLX)
	@echo "Creating $(NAME).."
	@echo "Your display variable is $$DISPLAY"
	@$(CC) $(CFLAGS) -o $@ $^ $(MLXFLAGS)

bonus : ${NAME}

clean :
	@echo "Cleaning all .o files.."
	@make -C mlx_linux clean
	@make -C $(LIBFTDIR) clean
	@rm -f $(OBJS)

fclean : clean
	@echo "Cleaning $(NAME)"
	@make -C $(LIBFTDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re