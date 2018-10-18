#pragma once
#include<string>
class Player
{
protected:
	
public:
	std::string name;
	int num,
		position,
		nTS,
		nTM,
		nPS;
	bool enter,
		win;
	bool TS,
		 TD,
	 	 TM,
		 PS;
	int typeplayer;
	Player(){}
	~Player(){}
};
