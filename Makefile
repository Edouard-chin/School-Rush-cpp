#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/10 10:11:22 by fbaudet-          #+#    #+#              #
#    Updated: 2015/01/10 10:11:22 by fbaudet-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro
CFLAGS = -Wall -Werror -Wextra
SRC = ft_retro.cpp
OBJ = $(SRC:.cpp=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CFLAGS) -o $@ -c $^

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re