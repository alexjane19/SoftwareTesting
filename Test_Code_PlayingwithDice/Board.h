#pragma once
#include "BoardCell.h"
#include "Game.h"
class Board :
	public BoardCell
{
	friend class Game;
private:
	BoardCell **boardGame;
	int *traps;
	int lenthtrap,
		count;
	int n;
	std::string nameoftrap;
public:
	Board();
	~Board();
	bool setTypeHome(int, int, char*);
	void setTraps(int , int);
	int typeofplayerin(int,int);
	void printboard();
	void createBoard();
	void removetrap(int, int);
	void clearPrewHplayer(int, int);
};

