#include <iostream>
#include <stdio.h>
#include "functions.cpp"
using namespace std;
int main()
{
    cout << "This game will auto play a game of likha between 4 bots and will outcome one loser" << endl;
    Player p1, p2, p3, p4;
    List PlayerList;
    card top;
    card cardEmpty;
    int random;
    card cardArray[53];
    p1 = fillPlayer(p1, "sergio", 0, cardEmpty);
    p2 = fillPlayer(p2, "abbas", 0, cardEmpty);
    p3 = fillPlayer(p3, "roy", 0, cardEmpty);
    p4 = fillPlayer(p4, "georges", 0, cardEmpty);

    initialize(PlayerList);

    AddPlayersInList(p1, p2, p3, p4, PlayerList);
    printH2R(PlayerList);
 
    FillCardStack(&top);
    if (!isEmpty(&top))
        cout << "not empty" << endl;
    cout << "FillCardStack is done succesfully" << endl;
    for (int s = 0; s < 13; s++)
    {
        random = 1 + rand() % 4;
        cout << random << "   ";
    }
   
      shuffleCards(&top,p1,p2,p3,p4 );

      distribute(cardArray,&p1,&p2,&p3,&p4);

   
   
}

