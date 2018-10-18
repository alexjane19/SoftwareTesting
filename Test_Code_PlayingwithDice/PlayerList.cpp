#include "PlayerList.h"
#include<string>
#include <sstream>
#include<iostream>

PlayerList::PlayerList()
{
	turns = 0;
	
}

void PlayerList::createListplayer()
{
	ePlayer = new Player[this->numberofplayers];
	for (size_t i = 0; i < (unsigned int)numberofplayers; i++)
	{
		std::string name;

		int typep;
		int ii =i;
        std::stringstream ss;
        std::string s;
        ss << ii;
        ss >> s;
		name = "name_" + s;

//		std::cout << "\nEnter Name Of Player: ";
//		std::cin >> name;
//		std::cout << "\nEnter Type Of Player: \n1.Ordinary Player \n2.Attacking Player \n3.Defensive Player \n4.Dead player worthy\n";
//		std::cin >> typep;
        typep = 1;
		ePlayer[i].name = name;
		ePlayer[i].typeplayer = typep;
		ePlayer[i].num = i + 1;
		ePlayer[i].position = 0;
		ePlayer[i].nTM = 0;
		ePlayer[i].nTS = 0;
		ePlayer[i].nPS = 0;
		ePlayer[i].TD = false;
		ePlayer[i].TM = false;
		ePlayer[i].TS = false;
		ePlayer[i].PS = false;
		ePlayer[i].enter = false;
		ePlayer[i].win = false;
	}
}
PlayerList::~PlayerList()
{
}
