#include "Screen.hpp"
#include "Squares.hpp"

int main()
{

	Screen s;
	Squares * c = new Squares('c');
	Squares * d = new Squares('x', -5, 5);
	s.initGame();
	for (int i = 0; i < 10; ++i)
		s.popSquares(new Squares('r'));
	s.pushSquares(c);
	s.pushSquares(d);
	for (int i = 0; i < 10; ++i)
		s.pushSquares(new Squares('t'));
	s.printAll();

	s.killSquares(s.getSquares());
	s.killSquares(s.getLastSquares());
	s.killSquares(c);
	s.printAll();
	s.clearScreen();
	s.printAll();
	s.generateNewWalls();
	s.printAll();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.printAll();

	return 0;
}
