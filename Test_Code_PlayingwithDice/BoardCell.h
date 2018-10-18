#pragma once
class BoardCell
{
protected:
	//static enum TypeHomes{ N,TR, TS, TD, TG,TM ,PB,PN,PS};

public:
	int numberHome,
		typeHome;
	//TypeHomes type;
	char *typeHomeC;
	BoardCell(){}
	~BoardCell(){}
};

