#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/10 10:11:22 by fbaudet-          #+#    #+#              #
#    Updated: 2015/01/10 20:51:42 by fbaudet-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro
CFLAGS = -Wall -Werror -Wextra -O3
SRC = Entity.class.cpp Monster.class.cpp Player.class.cpp Shoot.class.cpp \
	Wall.class.cpp Screen.class.cpp Squares.class.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
LFLAGS = -lncurses



all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.cpp
	g++ $(CFLAGS) -o $@ -c $^

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re