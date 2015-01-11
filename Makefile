CC = g++
NAME = ft_retro
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lncurses
SRC = Window.class.cpp Entity.class.cpp Monster.class.cpp Wall.class.cpp Player.class.cpp Shoot.class.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $<
	@echo Compipiling object : $<

clean:
	@rm -rf $(OBJ)
	@echo cleaning

fclean: clean
	@rm -rf $(NAME)

re: fclean all
