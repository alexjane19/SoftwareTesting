#pragma once
#include "PlayerList.h"
#include "Board.h"
#include<iostream>
class Game
{
private:
	PlayerList list;
	
public:

	int dice;
	bool endofgame;
	int pouringdice();
	void situationPlayer(int);
	void eachplayerhere(int, int);
	void startGame();
	int taskplayer(int);
	void changepositionplayer();
	Game(int n, int m, int p);
	~Game();
};

