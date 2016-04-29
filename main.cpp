#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <queue>
#include <iterator>
#include <stdio.h>

using namespace std;

void shuffle(Card tab[]);
void letThemFight(Card tab[]);


int main(int argc, char *argv[])
{
	srand(time(NULL));

	Card cards[52];
 for(int i=0;i<52;i++)
 {
 	cout<<cards[i].display()<<endl;
 };
cout<<"\n\n\n\n";
cout<<"po tasowaniu:\n\n";

 shuffle(cards);

 for(int i=0;i<52;i++)
 {
 	cout<<cards[i].display()<<cards[i].value()<<endl;
 };

 letThemFight(cards);

}

void shuffle(Card tab[])
{
	Card aux;
	int x,z;
	for(int i=0;i<100;i++)
	{
		x=rand()%52;
		z=rand()%52;
		aux=tab[x];
		tab[x]=tab[z];
		tab[z]=aux;
	};
};

void letThemFight(Card tab[])
{
	queue <Card> player1;
	queue <Card> player2;
	queue <Card> drawPlayer1;
	queue <Card> drawPlayer2;
	int stop;

	for(int i=0;i<52;i++)
	{
		player1.push(tab[i++]);
		player2.push(tab[i]);
	}

	while(!player1.empty() && !player2.empty())
	{
		cout<<"...\n";
		cout<<"player1 value="<<player1.front().value();
		cout<<"\nplayer2 value="<<player2.front().value();
		cout<<endl;

		if(player1.front().value()>player2.front().value())
		{
			cout<<"\nplayer1>player2\n";
			player1.push(player1.front());
			player1.push(player2.front());
			player1.pop();
			player2.pop();
		}
		else
			if(player2.front().value()>player1.front().value())
			{
				cout<<"player2>player1\n";
				player2.push(player1.front());
				player2.push(player2.front());
				player2.pop();
				player1.pop();
			}
			else
			{
				stop=0;
				while(player1.front().value()==player2.front().value() || stop==0)
				{
					cout<<"draw\n";
					cout<<"wykladanie kart na wojne\n";
					for(int i=0;i<3;i++)
					{
						drawPlayer1.push(player1.front());
						player1.pop();
						drawPlayer2.push(player2.front());
						player2.pop();
					}
					cout<<"gora wojny:\n";
					cout<<"gracz1draw="<<drawPlayer1.back().value();
					cout<<"\ngracz2draw="<<drawPlayer2.back().value();
					if(drawPlayer1.back().value()>drawPlayer2.back().value())
					{
						stop++;
						cout<<"player1 zgarnia wojne\n";
						for(int x=0;x<3;x++)
						{
							player1.push(drawPlayer1.front());
							drawPlayer1.pop();
							player1.push(drawPlayer2.front());
							drawPlayer2.pop();
							if(player1.empty() || player2.empty())
								break;
						}
					}
					else
						if(drawPlayer2.back().value()>drawPlayer1.back().value())
						{
							stop++;
							cout<<"player2 zgarnia wojne\n";
							for(int x=0;x<3;x++)
							{
								player2.push(drawPlayer1.front());
								drawPlayer1.pop();
								player2.push(drawPlayer2.front());
								drawPlayer2.pop();
								if(drawPlayer2.empty() || drawPlayer1.empty())
									break;
							}
						}
						else
							cout<<"remis w wojnie\n";	
				}		
			}
			if(player1.empty())
				cout<<"\nplayer2 has won\nCONGRATULATIONS!!!\n";
			else
				if(player2.empty())
					cout<<"\nplayer1 has won\nCONGRATULATIONS!!!\n";
	}
}
