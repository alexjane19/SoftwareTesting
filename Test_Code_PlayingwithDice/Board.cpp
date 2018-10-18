#include "Board.h"
#include<iostream>
#include<string.h>
Board::Board()
{
	lenthtrap = 0;
	count = 1;
}
void Board::createBoard()
{
	boardGame = new BoardCell*[n];
	for (int i = 0; i < n; i++)
		boardGame[i] = new BoardCell[n];
	for (size_t i = 0; i < (unsigned int)this->n; i++)
	{
		if ((i % 2) == 0)
		for (size_t j = 0; j < (unsigned int)this->n; j++)
		{
			boardGame[i][j].numberHome = count;
			boardGame[i][j].typeHome = 0;
			//boardGame[i][j].type = N;
			boardGame[i][j].typeHomeC = "__";
			count++;
		}
		if ((i % 2) == 1)
		for (int j = this->n - 1; j >= 0; j--)
		{
			boardGame[i][j].numberHome = count;
			boardGame[i][j].typeHome = 0;
			//boardGame[i][j].type = N;
			boardGame[i][j].typeHomeC = "__";
			count++;
		}
	}
}
bool Board::setTypeHome(int widthx, int heighty, char*typehome)
{
	int comp;
	char *ch[8]{"TR", "TS", "TD", "TG", "TM", "PB", "PN", "PS"};
	for (size_t i = 0; i < 8; i++)
	{
		if (strcmp(typehome, ch[i]) == 0)
		{
			comp = i+1;
			break;
		}
			
	}
	
	int width = widthx - 1, height = heighty-1;
	if (boardGame[width][height].numberHome == this->n*this->n)
		return false;
	if (boardGame[width][height].numberHome == 1)
		return false;
	if (width<this->n && height<this->n)
	switch (comp)
	{
	case 1:
		boardGame[width][height].typeHome = 1;
		//boardGame[width][height].type = TR;
		boardGame[width][height].typeHomeC = "TR";
		setTraps(width,height);
		return true;
		break;
	case 2:
		boardGame[width][height].typeHome = 2;
		//boardGame[width][height].type = TS;
		boardGame[width][height].typeHomeC = "TS";
		setTraps(width, height);
		return true;
		break;
	case 3:
		boardGame[width][height].typeHome = 3;
		//boardGame[width][height].type = TD;
		boardGame[width][height].typeHomeC =  "TD";
		setTraps(width, height);
		return true;
		break;
	case 4:
		boardGame[width][height].typeHome = 4;
		//boardGame[width][height].type = TG;
		boardGame[width][height].typeHomeC =  "TG";
		setTraps(width, height);
		return true;
		break;
	case 5:
		boardGame[width][height].typeHome = 5;
		//boardGame[width][height].type = TM;
		boardGame[width][height].typeHomeC =  "TM";
		setTraps(width, height);
		return true;
		break;
	case 6:
		boardGame[width][height].typeHome = 6;
		//boardGame[width][height].type = PB;
		boardGame[width][height].typeHomeC ="PB";
		return true;
		break;
	case 7:
		boardGame[width][height].typeHome = 7;
		//boardGame[width][height].type = PN;
		boardGame[width][height].typeHomeC = "PN";
		return true;
		break;
	case 8:
		boardGame[width][height].typeHome = 8;
		//boardGame[width][height].type = PS;
		boardGame[width][height].typeHomeC = "PS";
		return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}
void Board::setTraps(int wid,int hei)
{
	if (lenthtrap >= 1)
	{
		lenthtrap++;
		int i;
		int *traps1;
		traps1 = traps;
		traps = new int[lenthtrap];
		for (i = 0; i < lenthtrap-1; i++)
			traps[i] = traps1[i];
		traps[i] = boardGame[wid][hei].numberHome;
		delete[] traps1;
	}

	if (lenthtrap == 0)
	{
		lenthtrap++;
		traps = new int[lenthtrap];
		traps[lenthtrap - 1] = boardGame[wid][hei].numberHome;
	}

}
int Board::typeofplayerin(int pos,int numplayer)
{
	int i, j;
	for ( i = 0; i <  this->n; i++)
	{
		for (j = 0; j <  this->n; j++)
		{
			if (boardGame[i][j].numberHome == pos)
				break;
		}
		if (boardGame[i][j].numberHome == pos)
			break;
	}
	char *charplayer=new char[2];
	switch (numplayer)
	{
	case 1:
		charplayer = "01";
		break;
	case 2:
		charplayer = "02";
		break;
	case 3:
		charplayer = "03";
		break;
	case 4:
		charplayer = "04";
		break;
	case 5:
		charplayer = "05";
		break;
	default:
		break;
	}
	switch (boardGame[i][j].typeHome)
	{
	case 0:
		nameoftrap = " @ __\n";
		boardGame[i][j].typeHomeC = charplayer;
		break;
	case 1:
		nameoftrap = " @ TR\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		removetrap(i, j);
		return 1;
		break;
	case 2:
		nameoftrap = " @ TS\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		removetrap(i, j);
		return 2;
		break;
	case 3:
		nameoftrap = " @ TD\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		removetrap(i, j);
		return 3;
		break;
	case 4:
		nameoftrap = " @ TG\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		removetrap(i, j);
		return 4;
		break;
	case 5:
		nameoftrap = " @ TM\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		removetrap(i, j);
		return 5;
		break;
	case 6:
		nameoftrap = " @ PB\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		return 6;
		break;
	case 7:
		nameoftrap = " @ PN\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		return 7;
		break;
	case 8:
		nameoftrap = " @ PS\n";
		boardGame[i][j].typeHome = 0;
		boardGame[i][j].typeHomeC = charplayer;
		//boardGame[i][j].type = N;
		return 8;
		break;
	default:
		break;
	}
	return 0;
}

void Board::removetrap(int wid, int hei)
{
	if (lenthtrap > 0)
	{
		lenthtrap--;
		int i, j;
		int *traps1;
		traps1 = traps;
		traps = new int[lenthtrap];
		for (i = 0, j = 0; i < lenthtrap + 1; i++)
		if (traps1[i] != boardGame[wid][hei].numberHome)
		{
			traps[j] = traps1[i];
			j++;
		}
		delete[] traps1;
	}

	if (lenthtrap == 0)
	{
		delete[] traps;
	}
}
void Board::clearPrewHplayer(int pos, int numplayer)
{
	int i, j;
	for (i = 0; i < this->n; i++)
	{
		for (j = 0; j < this->n; j++)
		{
			if (boardGame[i][j].numberHome == pos)
				break;
		}
		if (boardGame[i][j].numberHome == pos)
			break;
	}
	boardGame[i][j].typeHomeC = "__";
}


void Board::printboard()
{
	for (size_t i = 0; i < (unsigned int)this->n; i++)
	{
		for (size_t j = 0; j < (unsigned int)this->n; j++)
			std::cout<<boardGame[i][j].typeHomeC<<"  ";

		std::cout << std::endl;
	}
}
Board::~Board()
{

}
