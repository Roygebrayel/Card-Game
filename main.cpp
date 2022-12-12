#include <iostream>
#include <stdio.h>
#include "functions.cpp"
using namespace std;
int main(){
    cout<<"This game will auto play a game of likha between 4 bots and will outcome one loser";
    cout<<"ssssss";
    Player player1, player2, player3, player4;
    List PlayerList;
    initializePlayer(player1,"p1",0);
    initializePlayer(player2,"p2",0);
    initializePlayer(player3,"p3",0);
    initializePlayer(player4,"p4",0);

    AddPlayersInList(player1,player2,player3,player4,PlayerList);
    printH2R(PlayerList);
}
