#include<iostream>
#include "Game.h"
using namespace std;

int convertcharstoint(char ch[]){

    int a=0;
    int po = 1;
    for(int i=0; ch[i] !=0; i++)
    {
        int c = ch[i] - '0';
        a = a * po;
        a+=c;
        po*= 10;
    }
    return a;
}

int main(int argc, char* argv[])
{
    int n,m,p;
    n = convertcharstoint(argv[1]);
    m = convertcharstoint(argv[2]);
    p = convertcharstoint(argv[3]);

	Game Game1(n,m,p);
	Game1.startGame();

	//system("pause");
	return 0;

}


