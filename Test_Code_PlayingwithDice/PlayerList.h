#pragma once
#include "Player.h"
class PlayerList :
	public Player
{
	friend class Game;
private:
	Player * ePlayer;
	int numberofplayers;
	int turns;

public:
	void createListplayer();
	PlayerList();
	~PlayerList();
	
};

