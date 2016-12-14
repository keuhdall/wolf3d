#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#             *#
#*   Updated: 2016/12/12 20:24:41 by lmarques         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = wolf3d

SRC = wolf3d.c \
	  reader.c \
	  tools.c \
	  controls.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft
		make -C minilibx
		mv libft/libft.a .
		mv minilibx/libmlx.a .
		gcc -Wall -Werror -Wextra -c $(SRC)
		gcc -Wall -Werror -Wextra -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
		make -C libft clean
		make -C minilibx clean
		rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
		make -C libft fclean
		make -C minilibx clean
		rm -rf $(NAME)

re : fclean all
