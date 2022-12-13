#include <iostream>
#include <stdio.h>
#include "PlayerLinkedList.cpp"
#include "queue.cpp"
using namespace std;

Player initializePlayer(Player p,string name, int score){
    p.name = name;
    p.score = score;
    return p;
 }

 void AddPlayersInList(Player pl1,Player pl2,Player pl3,Player pl4,List &l){
    insertAtHead(l,pl4.name,pl4.score);
    insertAtHead(l,pl3.name,pl3.score);
    insertAtHead(l,pl2.name,pl2.score);
    insertAtHead(l,pl1.name,pl1.score);
}

void FillCardStack(card* top){
    for(int i=0;i<13;i++){
        top = push(top,i+1,"hearts");
    }
    for(int i=0;i<13;i++){
        top = push(top,i+1,"diamonds");
    }
    for(int i=0;i<13;i++){
        top = push(top,i+1,"spades");
    }
    for(int i=0;i<13;i++){
        top = push(top,i+1,"clubs");
    }
}