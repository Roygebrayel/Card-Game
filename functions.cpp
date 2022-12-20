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

void shuffle(card *c, card c1[], int length)
{
    card *temp;
    card*tmp;
    tmp->value = 0;
    tmp->type = "";
    temp->value = 0;
    temp->type = "";
    int randomIndex ;

    for (int i = 0; i < 52; i++)
    {
        temp = pop(c, c->value, c->type);

        c1[i] = *temp;
    }
    for (int j = 0; j < length; j++)
    {
        randomIndex = rand() % length;
        *tmp = c1[j];
        c1[j] = c1[randomIndex];
        c1[randomIndex] = *tmp;
    }
    for (int i = 0; i < length; i++)
    {
        cout << c1[i].value << " " << c1[i].type << endl;
    }
}
