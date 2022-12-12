#include <stdio.h>
#include <string>
# include <iostream>
using namespace std;
struct Node
{
    string data;
	Node* next;
};

struct Queue
{
	Node* front;
	Node* rear;
};

void initialize (Queue &Q)      // if Queue *Q
{
	Q.front = Q.rear = NULL;    //Q->front = Q->rear = NULL;
}

bool isEmpty(Queue Q)
{
	return(Q.front == NULL || Q.rear == NULL);
}

void Enqueue(Queue &Q, int val)
{
	Node* tmp = new Node;
	if(tmp == NULL)
		exit(1);
	tmp->data = val;
	tmp->next = NULL;
	if(isEmpty(Q))
	{
		Q.front = Q.rear= tmp;
		return;
	}
	Q.rear->next = tmp;
	Q.rear = tmp;
}

void Dequeue(Queue &Q,string val)
{
	if(isEmpty(Q))
		return;
	val = Q.front -> data;
	Node* tmp = Q.front->next;
	delete Q.front;
	Q.front = tmp;
}

void Display(Queue Q){
	string x;
	while(isEmpty(Q)==false)
	{
		Dequeue(Q,x);
		cout<<x<<" ";
	}
}
