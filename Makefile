# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selibrah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 11:04:39 by selibrah          #+#    #+#              #
#    Updated: 2020/01/10 18:21:55 by selibrah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rtv1
C = gcc
MLX_PATH = mlx
OPENCL = -framework OpenCL -lmlx  -L  $(MLX_PATH) -I $(MLX_PATH)include -framework OpenGL -framework AppKit -lz

all: $(NAME)

$(NAME): main.c bmp.h
	$(C) $(CFLAGS) $(OPENCL) -o $(NAME) main.c

clean:
	rm -f *.o
	Make clean -C ./mlx
fclean: clean
	rm -f $(NAME)
re: fclean all
