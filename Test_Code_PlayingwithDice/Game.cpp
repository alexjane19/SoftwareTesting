#include "Game.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <stdlib.h>
using namespace std;
Board board1;
Game::Game(int n, int m, int p)
{
	endofgame = false;
	dice = 0;
//	int n, m, p;
//	std::cout << "\nEnter the number of rows and columns: ";
//	std::cin >> n;
	board1.n = n;
	board1.createBoard();
//	std::cout << "\nEnter the number of Players: ";
//	std::cin >> m;
	list.numberofplayers = m;
	list.createListplayer();
//	std::cout << "\nEnter the number of traps and powers: ";
//	std::cin >> p;

	for (int i = 0; i < p; i++)
	{
		int wid, hei;
		char typehh[3] = "TR" ;
		wid = (rand()) % n;
		hei = (rand()) % n;
//		cout<<wid<<" - "<<hei;

//		std::cout << "\nEnter the width of trap or power: ";
//		cin >> wid;
//		std::cout << "\nEnter the height of trap or power: ";
//		cin >> hei;
//		std::cout << "\nEnter the type of trap or power: (TR,TS,TD,TG,TM,PB,PN,PS)\n";
//		cin.get();
//		cin.get(typehh,3,'\n');
		if (!(board1.setTypeHome(wid, hei, typehh)))
			i--;
	}
//		std::cin >> p;

	//system("cls");
}
void Game::startGame()
{
	while (endofgame == false)
	{
		srand((unsigned int)time(0));
		
		std::cout << "\n[" << list.ePlayer[list.turns].name << "]" << "'s turn to play" << std::endl;
		
		dice = pouringdice();

		std::cout << "[" << list.ePlayer[list.turns].name << "]" << "=" << dice<<std::endl;

		if (list.ePlayer[list.turns].enter == true)
		{
			if (list.ePlayer[list.turns].TS == true)
			{
				dice /= 2;
				list.ePlayer[list.turns].nTS--;
				if (list.ePlayer[list.turns].nTS == 0)
					list.ePlayer[list.turns].TS = false;
			}

			if (list.ePlayer[list.turns].TM == true)
			{
				dice *= -1;
				list.ePlayer[list.turns].nTM--;
				if (list.ePlayer[list.turns].nTM == 0)
					list.ePlayer[list.turns].TM = false;
			}
			if (list.ePlayer[list.turns].PS == true)
			{
				dice *= 2;
				list.ePlayer[list.turns].nPS--;
				if (list.ePlayer[list.turns].nPS == 0)
					list.ePlayer[list.turns].PS = false;
			}
			try{
				if (dice == 6)
				{
					if ((list.ePlayer[list.turns].position + dice) <= (board1.n*board1.n) &&
						(list.ePlayer[list.turns].position + dice) > 0)
					{

						board1.clearPrewHplayer(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num);
						list.ePlayer[list.turns].position += dice;
						std::cout << "[" << list.ePlayer[list.turns].name << "]" << "move to " << list.ePlayer[list.turns].position
							<< std::endl;
						situationPlayer(board1.typeofplayerin(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num));
						std::cout << board1.nameoftrap;
						eachplayerhere(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num - 1);
					}
					dice = 6;


					if (list.ePlayer[list.turns].TD == true)
					{
						list.ePlayer[list.turns].TD = false;
						int dic = 0;
						throw dic;
					}



				}
				else if (dice < 6)
				{
					if ((list.ePlayer[list.turns].position + dice) <= (board1.n*board1.n) &&
						(list.ePlayer[list.turns].position + dice) >0)
					{
						board1.clearPrewHplayer(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num);
						list.ePlayer[list.turns].position += dice;
						std::cout << "[" << list.ePlayer[list.turns].name << "]" << " move to " << list.ePlayer[list.turns].position
							<< std::endl;
						situationPlayer(board1.typeofplayerin(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num));
						std::cout << board1.nameoftrap << std::endl;
						eachplayerhere(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num - 1);
					}

				}
			}
			catch (int di)
			{
				dice = di;
			}

		}
		
		if (dice == 6 && list.ePlayer[list.turns].enter == false)
		{
			list.ePlayer[list.turns].position = 1;
			list.ePlayer[list.turns].enter = true;
			situationPlayer(board1.typeofplayerin(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num));
			std::cout << board1.nameoftrap << std::endl;
			eachplayerhere(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num - 1);
		}

		if (list.ePlayer[list.turns].position == (board1.n*board1.n))
		{
			list.ePlayer[list.turns].win = true;
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " has won the game\n";
			endofgame = true;
		}

		if (list.ePlayer[list.turns].typeplayer == 2 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
			dice = 6;
		}
		if (list.ePlayer[list.turns].enter == true && list.ePlayer[list.turns].typeplayer == 4 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
			board1.printboard();
			changepositionplayer();
		}
		if (dice != 6)
		{
			board1.printboard();
			//system("pause");
			//system("cls");
			list.turns++;
			if (list.numberofplayers <= list.turns)
				list.turns = 0;

			if (list.ePlayer[list.turns].TD == true)
			{
				list.ePlayer[list.turns].TD = false;
				list.turns++;
			}
		}
		board1.printboard();
		for(int stop=0;stop<10000;stop++);
	}
}
int Game::pouringdice()
{
	int menuofdice;
	int tdice = 0;
	while (1)
	{
		try
		{
//			std::cout << "\n1.Manually Dice\n2.Random Dice\n";
//			std::cin >> menuofdice;
//			if (menuofdice > 2 || menuofdice <= 0)
//				throw "\ntou bayad vared koni adade 1 ya 2\n";
//			if (menuofdice == 1)
//			{
//				std::cout << "\nvared kon yek adad bin 1 ta 6: ";
//				std::cin >> tdice;
//				if (tdice > 6 || tdice <= 0)
//				{
//					std::cout << "\nvared kon yek adad bin 1 ta 6: ";
//					std::cin >> tdice;
//				}
//			}
//			if (menuofdice == 2)
//			{
				while (tdice == 0)
				{
					tdice = rand() % 7;
				}
//			}
			return tdice;
		}
		catch (const char* exp)
		{
			std::cout << exp;
			cout << endl;
			continue;
		}
	}
	
}
void Game::situationPlayer(int situ)
{
	bool b = false;
	bool bs = false;

	switch (situ)
	{
	case 1:
		if (list.ePlayer[list.turns].typeplayer == 3 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
		}
		else
		{
			board1.clearPrewHplayer(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num);
			list.ePlayer[list.turns].enter = false;
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is reset" << std::endl;
		}
		break;
	case 2:
		if (list.ePlayer[list.turns].typeplayer == 3 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
		}
		else
		{
			list.ePlayer[list.turns].TS = true;
			list.ePlayer[list.turns].nTS = 2;
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is slowed" << std::endl;
		}
		break;
	case 3:
		if (list.ePlayer[list.turns].typeplayer == 3 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
		}
		else
		{
			list.ePlayer[list.turns].TD = true;
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Off" << std::endl;
		}
		break;
	case 4:
		if (list.ePlayer[list.turns].typeplayer == 3 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
		}
		else
		{
			int accidentplace;
			while (1)
			{
				accidentplace = rand() % list.ePlayer[list.turns].position;
				if (accidentplace != 0)
					break;
			}
			board1.clearPrewHplayer(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num);
			list.ePlayer[list.turns].position = accidentplace;
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " goes random location" << std::endl;
			situationPlayer(board1.typeofplayerin(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num));
			eachplayerhere(list.ePlayer[list.turns].position, list.turns);
		}
		break;
	case 5:
		if (list.ePlayer[list.turns].typeplayer == 3 && taskplayer(list.ePlayer[list.turns].typeplayer) == 1)
		{
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is Lucky" << std::endl;
		}
		else
		{
			list.ePlayer[list.turns].TM = true;
			list.ePlayer[list.turns].nTM = 2;
			std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is with inverter" << std::endl;
		}
		break;
	case 6:
		int numpalyer;
		while (!b)
		{
			try
			{
				cout << "\nshomare bazikoni ke mikhahid be aghab befrestid ra benevisid: ";
				std::cin >> numpalyer;
				if (numpalyer > list.numberofplayers && numpalyer == 0)
					throw "\nChonin bazikoni vojod nadarad";
				if (numpalyer == list.ePlayer[list.turns].num)
					throw "\ntou nemitoni khodet ro harekat bedi";
				if (list.ePlayer[numpalyer - 1].enter == false)
					throw "\nin bazikon biron az bazi hast";

				int newposback = (rand() % list.ePlayer[numpalyer - 1].position);
				board1.clearPrewHplayer(list.ePlayer[numpalyer - 1].position, list.ePlayer[numpalyer - 1].num);
				list.ePlayer[numpalyer - 1].position = (newposback == 0) ? newposback + 1 : newposback;
				std::cout << "[" << list.ePlayer[list.turns].name << "]" << " send " << list.ePlayer[numpalyer - 1].name <<
					" back by " << list.ePlayer[numpalyer - 1].position << std::endl;
				board1.typeofplayerin(list.ePlayer[numpalyer - 1].position, list.ePlayer[numpalyer - 1].num);
				eachplayerhere(list.ePlayer[numpalyer - 1].position, numpalyer - 1);
				b = true;
			}
			catch (const char* exp)
			{
				std::cout << exp;
				cout << endl;
				continue;
			}
		}
		break;
	case 7:
		int numpalyers;
		while (!bs)
		{
			try
			{
				cout << "\nshomare bazikoni ke mikhahid be tale befrestid ra benevisid: ";
				std::cin >> numpalyers;
				if (numpalyers > list.numberofplayers && numpalyers == 0)
					throw "\nChonin bazikoni vojod nadarad";
				if (numpalyers == list.ePlayer[list.turns].num)
					throw "\ntou nemitoni khodet ro harekat bedi";
				if (list.ePlayer[numpalyers - 1].enter == false)
					throw "\nin bazikon biron az bazi hast";
				if (board1.lenthtrap > 0)
				{
					int *desttrap = new int[board1.lenthtrap];
					for (int i = 0; i < board1.lenthtrap; i++)
					{
						desttrap[i] = ((board1.traps[i] - list.ePlayer[numpalyers - 1].position) < 0) ?
							-1 * (board1.traps[i] - list.ePlayer[numpalyers - 1].position) :
							(board1.traps[i] - list.ePlayer[numpalyers - 1].position);
					}

					for (int j = 0; j < board1.lenthtrap; j++)
					{
						for (int i = 0; i<board1.lenthtrap - 1 - j; i++)

						if (desttrap[i]>desttrap[i + 1]){
							int t = desttrap[i + 1];
							desttrap[i + 1] = desttrap[i];
							desttrap[i] = t;

							t = board1.traps[i + 1];
							board1.traps[i + 1] = board1.traps[i];
							board1.traps[i] = t;
						}

					}

					board1.clearPrewHplayer(list.ePlayer[numpalyers - 1].position, list.ePlayer[numpalyers - 1].num);
					if (desttrap[0] == desttrap[1])
						list.ePlayer[numpalyers - 1].position = ((board1.traps[0] - list.ePlayer[numpalyers - 1].position) < 0) ?
						board1.traps[0] : board1.traps[1];
					else
						list.ePlayer[numpalyers - 1].position = board1.traps[0];

					cout << "[" << list.ePlayer[list.turns].name << "]" << " send " << list.ePlayer[numpalyers - 1].name <<
						"to nearest trap at " << list.ePlayer[numpalyers - 1].position << std::endl;

					situationPlayer(board1.typeofplayerin(list.ePlayer[numpalyers - 1].position, list.ePlayer[numpalyers - 1].num));
					bs = true;
				}
			}
			catch (const char* exp)
			{
				std::cout << exp;
				cout << endl;
				continue;
			}
		}
		break;
	case 8:
		list.ePlayer[list.turns].PS=true;
		list.ePlayer[list.turns].nPS = 2;
		std::cout << "[" << list.ePlayer[list.turns].name << "]" << " is speed" << std::endl;
		break;
	default:
		break;
	}
}
void Game::eachplayerhere(int posnewplayer, int numnewplayer)
{
	for (int i = 0; i < list.numberofplayers; i++)
	{
		if (list.ePlayer[i].position == posnewplayer && i != numnewplayer)
		{
			if (list.ePlayer[i].typeplayer == 3 && taskplayer(list.ePlayer[i].typeplayer) == 1)
			{
				std::cout << "[" << list.ePlayer[i].name << "]" << " is Lucky" << std::endl;
				list.ePlayer[numnewplayer].enter = false;
				std::cout << "[" << list.ePlayer[i].name << "]" << " killed " << list.ePlayer[numnewplayer].name << std::endl;
				list.ePlayer[numnewplayer].PS = false;
				list.ePlayer[numnewplayer].TD = false;
				list.ePlayer[numnewplayer].TM = false;
				list.ePlayer[numnewplayer].TS = false;
				list.ePlayer[numnewplayer].nPS = 0;
				list.ePlayer[numnewplayer].nTM = 0;
				list.ePlayer[numnewplayer].nTS = 0;

			}
			else
			{
				list.ePlayer[i].enter = false;
				std::cout << "[" << list.ePlayer[numnewplayer].name << "]" << " killed " << list.ePlayer[i].name << std::endl;
				list.ePlayer[i].PS = false;
				list.ePlayer[i].TD = false;
				list.ePlayer[i].TM = false;
				list.ePlayer[i].TS = false;
				list.ePlayer[i].nPS = 0;
				list.ePlayer[i].nTM = 0;
				list.ePlayer[i].nTS = 0;
			}
		}
			
	}
}
int Game::taskplayer(int typeplayer)
{
	int task;
	switch (typeplayer)
	{
	case 1:
		return 0;
		break;
	case 2:
		task = rand() % 2;
		return task;
		break;
	case 3:
		task = rand() % 2;
		return task;
		break;
	case 4:
		task = rand() % 4;
		return task;
		break;
	default:
		return 0;
		break;
	}
}
void Game::changepositionplayer()
{
	bool b = false;
	int yesno;
	std::cout<<"\nAya tou mikhay estefade koni az in shans ke jaye khodet ro ba yeki dige avaz koni? 1.Yes or 2.No\n";
	cin >> yesno;
	if (yesno == 1)
	{
		
		int numpalyer;
		while (!b)
		{
			try
			{
				cout << "\nshomare bazikoni ke mikhahid jaye khodet ra ba on avaz koni benvisid: ";
				std::cin >> numpalyer;
				if (numpalyer > list.numberofplayers && numpalyer == 0)
					throw "\nChonin bazikoni vojod nadarad";
				if (numpalyer == list.ePlayer[list.turns].num)
					throw "\nin makan jaye khodeton hast";
				if (list.ePlayer[numpalyer - 1].enter == false)
					throw "\nin bazikon biron az bazi hast";

				int changepos = list.ePlayer[list.turns].position;
				list.ePlayer[list.turns].position = list.ePlayer[numpalyer-1].position;
					list.ePlayer[numpalyer-1].position = changepos;

				board1.clearPrewHplayer(list.ePlayer[numpalyer - 1].position, list.ePlayer[numpalyer - 1].num);
				board1.clearPrewHplayer(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num);
				std::cout << "[" << list.ePlayer[list.turns].name << "]" << " change his position with " << 
					list.ePlayer[numpalyer - 1].name << list.ePlayer[numpalyer - 1].position << std::endl;

				board1.typeofplayerin(list.ePlayer[numpalyer - 1].position, list.ePlayer[numpalyer - 1].num);
				board1.typeofplayerin(list.ePlayer[list.turns].position, list.ePlayer[list.turns].num);

				board1.printboard();
				b = true;
			}
			catch (const char* exp)
			{
				std::cout << exp;
				cout << endl;
				continue;
			}
		}
	}
}
Game::~Game()
{
}
 
