#include <iostream>
#include <stdio.h>
#include "PlayerLinkedList.cpp"
#include "queue.cpp"

#include <stdlib.h>
using namespace std;

Player fillPlayer(Player p, string name, int score, card c)
{
    p.name = name;
    p.score = score;
    p.cardInHand[0] = c;
    return p;
}

card fillCard(card c, int val, string type)
{
    c.value = val;
    c.type = type;
    return c;
}

void AddPlayersInList(Player pl1, Player pl2, Player pl3, Player pl4, List &l)
{
    insertAtHead(l, pl4.name, pl4.score);
    insertAtHead(l, pl3.name, pl3.score);
    insertAtHead(l, pl2.name, pl2.score);
    insertAtHead(l, pl1.name, pl1.score);
}

void ADDCardsInList(card c1, List &l)
{
    insertAtHeadCard(l, c1.type, c1.value);
}

void FillCardStack(card *top)
{
    for (int i = 0; i < 13; i++)
    {
        top = push(top, i + 1, "hearts");
    }
    for (int i = 0; i < 13; i++)
    {
        top = push(top, i + 1, "diamonds");
    }
    for (int i = 0; i < 13; i++)
    {
        top = push(top, i + 1, "spades");
    }
    for (int i = 0; i < 13; i++)
    {
        top = push(top, i + 1, "clubs");
    }
    DisplayStack(top);
}
void maxCards(card c1[], card gift[])
{
    card max;
    max.value = 0;
    max.type = " ";

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            if (c1[i].value > max.value)
            {
                max = c1[i];

                // Shift elements to the left
                for (int j = i; j < 13; j++)
                {
                    c1[i] = c1[i + 1];
                }
            }
        }
        gift[j] = max;
    }
}

void gift(Player &p1, Player &p2, Player &p3, Player &p4)
{
    card swap1[3], swap2[3], swap3[3], swap4[3];

    maxCards(p1.cardInHand, swap1);
    maxCards(p2.cardInHand, swap2);
    maxCards(p3.cardInHand, swap3);
    maxCards(p4.cardInHand, swap4);
    int c = 0;
    for (int i = 10; i < 13; i++)
    {
        p1.cardInHand[i] = swap1[c];
        p2.cardInHand[i] = swap2[c];
        p3.cardInHand[i] = swap3[c];
        p4.cardInHand[i] = swap4[c];
        c++;
    }
}




void distribute(card array[],Player *p1,Player *p2,Player *p3,Player *p4){
    int j1=0,j2=0,j3=0,j4=0;
    for(int i = 0;i<52;i++){
        if(i<13){
            p1->cardInHand[j1] = array[i];
            j1++;
        }else
        if(i>=13 && i<26){
            p2->cardInHand[j2] = array[i];
            j2++;
        }else
        if(i>=26 && i<39){
            p3->cardInHand[j3] = array[i];
            j3++;
        }else
        if(i>=39 && i<52){
            p4->cardInHand[j4] = array[i];
            j4++;
        }
    }
}

void throwCard1(Player &P1, Player &P2, Player &P3, Player &P4, card *ctable[])
{

    ctable[0]->type = "diamonds";
    ctable[0]->value = 5;
    for (int i = 0; i < 13; i++)
    {
        int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
        int random = rand() % 13;
        for (int i = 0; i < 13; i++)
        {
            if (P1.cardInHand[i].type == ctable[0]->type)
            {
                if (P1.cardInHand[i].value <= ctable[0]->value)
                {
                    *ctable[0] = P1.cardInHand[i];
                    index1 = i;
                    // i should delete the element from the card in hand array
                }
                else
                {
                    *ctable[0] = P1.cardInHand[i];
                    index1 = i;
                }
            }
            else // if the cards are not of the same type

                if (P1.cardInHand[i].type == "spades" && P1.cardInHand[i].value == 12)
                {
                    *ctable[0] = P1.cardInHand[i];
                    index1 = i;
                }
                else if (P1.cardInHand[i].type == "diamonds" && P1.cardInHand[i].value == 10)
                {
                    *ctable[0] = P1.cardInHand[i];
                    index1 = i;
                }
                else if (P1.cardInHand[i].type == "hearts")
                {
                    *ctable[0] = P1.cardInHand[i];
                    index1 = i;
                }
                else
                {
                    *ctable[0] = P1.cardInHand[random];
                    index1 = i;
                }
        }
            for(int i=index1 ;i<13-(index1+1);i++){
                P1.cardInHand[i]=P1.cardInHand[index1+1];
            }

        // if the cards are of the same types
        for (int i = 0; i < 13; i++)
        {
            if (P2.cardInHand[i].type == ctable[0]->type)
            {
                if (P2.cardInHand[i].value <= ctable[0]->value)
                {
                    *ctable[1] = P2.cardInHand[i];
                    index2 = i;

                    // i should delete the element from the card in hand array
                }
                else
                {
                    *ctable[1] = P2.cardInHand[i];
                    index2 = i;
                }
            }
            else // if the cards are not of the same type

                if (P2.cardInHand[i].type == "spades" && P2.cardInHand[i].value == 12)
                {
                    *ctable[1] = P2.cardInHand[i];
                    index2 = i;
                }
                else if (P2.cardInHand[i].type == "diamonds" && P2.cardInHand[i].value == 10)
                {
                    *ctable[1] = P2.cardInHand[i];
                    index2 = i;
                }
                else if (P2.cardInHand[i].type == "hearts")
                {
                    *ctable[1] = P2.cardInHand[i];
                    index2 = i;
                }
                else
                {
                    *ctable[1] = P2.cardInHand[random];
                    index2 = i;
                }
        }
         for(int i=index2 ;i<13-(index2+1);i++){
                P2.cardInHand[i]=P2.cardInHand[i+1];
            }
        // if the cards are of the same types
        for (int i = 0; i < 13; i++)
        {
            if (P3.cardInHand[i].type == ctable[0]->type)
            {
                if (P3.cardInHand[i].value <= ctable[0]->value)
                {
                    *ctable[2] = P3.cardInHand[i];
                    index3 = i;

                    // i should delete the element from the card in hand array
                }
                else
                {
                    *ctable[2] = P3.cardInHand[i];
                    index3 = i;
                }
            }
            else // if the cards are not of the same type

                if (P3.cardInHand[i].type == "spades" && P3.cardInHand[i].value == 12)
                {
                    *ctable[2] = P3.cardInHand[i];
                    index3 = i;
                }
                else if (P3.cardInHand[i].type == "diamonds" && P3.cardInHand[i].value == 10)
                {
                    *ctable[2] = P3.cardInHand[i];
                    index3 = i;
                }
                else if (P3.cardInHand[i].type == "hearts")
                {
                    *ctable[2] = P3.cardInHand[i];
                    index3 = i;
                }
                else
                {
                    *ctable[2] = P3.cardInHand[random];
                    index3 = i;
                }
        }
        for(int i=index3 ;i<13-(index3+1);i++){
                P3.cardInHand[i]=P3.cardInHand[index3+1];
            }
        // if the cards are of the same types
        for (int i = 0; i < 13; i++)
        {
            if (P4.cardInHand[i].type == ctable[0]->type)
            {
                if (P4.cardInHand[i].value <= ctable[0]->value)
                {
                    *ctable[3] = P4.cardInHand[i];
                    index4 = i;

                    // i should delete the element from the card in hand array
                }
                else
                {
                    *ctable[3] = P4.cardInHand[i];
                    index4 = i;
                }
            }
            else // if the cards are not of the same type

                if (P4.cardInHand[i].type == "spades" && P4.cardInHand[i].value == 12)
                {
                    *ctable[3] = P4.cardInHand[i];
                    index4 = i;
                }
                else if (P4.cardInHand[i].type == "diamonds" && P4.cardInHand[i].value == 10)
                {
                    *ctable[3] = P4.cardInHand[i];
                    index4 = i;
                }
                else if (P4.cardInHand[i].type == "hearts")
                {
                    *ctable[3] = P4.cardInHand[i];
                    index4 = i;
                }
                else
                {
                    *ctable[3] = P4.cardInHand[random];
                    index4 = i;
                }
        }
         for(int i=index4 ;i<13-(index4+1);i++){
                P4.cardInHand[i]=P4.cardInHand[index4+1];
            }
    }
}


void shuffleCards(card *sc, Player &p1, Player &p2, Player &p3, Player &p4)
{
    card *cp1[13];
    card *cp2[13];
    card *cp3[13];
    card *cp4[13];
     int j = 0;
      int j1 = 0;
       int j2 = 0;
        int j3 = 0;
    for (int i = 0; i < 52; i++)
    {

 

        if (i < 13)
        {

 

            cp1[j] = pop(sc, sc->value, sc->type);
            j++;
        }
        else if (i >= 13 && i < 26)
        {

 

            cp2[j1] = pop(sc, sc->value, sc->type);
            j1++;
        }
        else if (i >= 26 && i < 39)
        {

 

            cp3[j2] = pop(sc, sc->value, sc->type);
            j2++;
        }
        else if (i >= 39 && i < 52)
        {

 

            cp4[j3] = pop(sc, sc->value, sc->type);
            j3++;
        }
    }
    cout<<"hello"<<endl;
    int random;
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    while (i1 < 13 || i2 < 13 || i3 < 13 || i4 < 13)
    {
        random = 1 + rand() % 4;

 

        if (random == 1)
        {
            if (i1 < 13)
            {
                p1.cardInHand[i1] = *cp1[c1];
                c1++;
                i1++;
            }
            else if (i2 < 13)
            {
                p2.cardInHand[i2] = *cp1[c1];
                c1++;
                i2++;
            }
            else if (i3 < 13)
            {
                p2.cardInHand[i3] = *cp1[c1];
                c1++;
                i3++;
            }
            else if (i4 < 13)
            {
                p2.cardInHand[i4] = *cp1[c1];
                c1++;
                i4++;
            }
        }
        else if (random == 2)
        {
            if (i1 < 13)
            {
                p1.cardInHand[i1] = *cp2[c2];
                c2++;
                i1++;
            }
            else if (i2 < 13)
            {
                p2.cardInHand[i2] = *cp2[c2];
                c2++;
                i2++;
            }
            else if (i3 < 13)
            {
                p2.cardInHand[i3] = *cp2[c2];
                c2++;
                i3++;
            }
            else if (i4 < 13)
            {
                p2.cardInHand[i4] = *cp2[c2];
                c2++;
                i4++;
            }
        }
        else if (random == 3)
        {
            if (i1 < 13)
            {
                p1.cardInHand[i1] = *cp3[c3];
                c3++;
                i1++;
            }
            else if (i2 < 13)
            {
                p2.cardInHand[i2] = *cp3[c3];
                c3++;
                i2++;
            }
            else if (i3 < 13)
            {
                p2.cardInHand[i3] = *cp3[c3];
                c3++;
                i3++;
            }
            else if (i4 < 13)
            {
                p2.cardInHand[i4] = *cp3[c3];
                c3++;
                i4++;
            }
        }
        else if (random == 4)
        {
            if (i1 < 13)
            {
                p1.cardInHand[i1] = *cp4[c4];
                c4++;
                i1++;
            }
            else if (i2 < 13)
            {
                p2.cardInHand[i2] = *cp4[c4];
                c4++;
                i2++;
            }
            else if (i3 < 13)
            {
                p2.cardInHand[i3] = *cp4[c4];
                c4++;
                i3++;
            }
            else if (i4 < 13)
            {
                p2.cardInHand[i4] = *cp4[c4];
                c4++;
                i4++;
            }
        }
    }
    cout<<"helloooo"<<endl;
}
