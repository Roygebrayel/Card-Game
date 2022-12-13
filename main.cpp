#include <iostream>
#include <stdio.h>
#include "functions.cpp"
using namespace std;
int main(){
    cout<<"This game will auto play a game of likha between 4 bots and will outcome one loser";
    Player p1,p2,p3,p4;
    List PlayerList;
    card top;
    p1 = initializePlayer(p1,"sergio",0);
    p2 = initializePlayer(p2,"abbas",0);
    p3 = initializePlayer(p3,"roy",0);
    p4 = initializePlayer(p4,"georges",0);

    initialize(PlayerList);
        
    AddPlayersInList(p1,p2,p3,p4,PlayerList);
    printH2R(PlayerList);
     cout<<"hello1"<<endl;
    FillCardStack(&top);
    cout<<"FillCardStack is done succesfully"<<endl;
    DisplayStack(&top);
}
