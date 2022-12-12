# include <iostream>
# include <stdio.h>
using namespace std;

struct card
{

	int value;
	string type;
	card *next;
};

struct Player{
	string name;
	int score;
	card cardInHand;
	Player* next;
	Player* prev;
};

struct List{
	Player* head;
	Player* rear;
};

void initialize(List &L){
	L.head = NULL;
	L.rear = NULL;
}

bool isEmpty(List L){
	return(L.head == NULL || L.rear == NULL);
}

void printH2R(List L)
{
	if(isEmpty(L)){
		cout<<"empty";
		return;
	}
	Player* curr = L.head;
	while(curr!= NULL){
		cout<<curr ->name<<" "<<curr->score<<" "<<endl;
		curr = curr -> next;
	}
}

Player* Search(List L, string name){
	Player* curr1;
	Player* curr2;
	if(isEmpty(L)){
		cout<<"empty";
		return NULL;
	}
	curr1 = L.head;
	curr2 = L.rear;
	while(curr1->name != curr2->name && curr2->prev != curr1 || curr1 != curr2){
		if(curr1->name == name)
			return curr1;
		if(curr2->name == name)
			return curr2;
		curr1 = curr1->next;
		curr2 = curr2->prev;
	}
	return NULL;
}

void insertAtHead(List &L, string name, int &score){
	Player* tmp;
	tmp = new Player;
	if(tmp == NULL)
		exit(1);
	tmp->name = name;
	tmp->score = score;
	tmp->next = NULL;
	tmp->prev = NULL;
	if(isEmpty(L))
	{
		L.head = tmp;
		L.rear = tmp;
		return;
	}                    
	L.head->prev = tmp;  
	tmp->next=L.head;    
	L.head=tmp;          
}

void insertAtRear(List& L, string name, int score) {
	Player* tmp;
	tmp = new Player;
	if (tmp == NULL)
		exit(1);
	tmp->name = name;
	tmp->score = score;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (isEmpty(L))
	{
		L.head = tmp;
		L.rear = tmp;
		return;
	}
	L.rear->next = tmp;
	tmp->prev = L.rear;
	L.rear = tmp;
}
	
	void RemovePlayer(List L, string name){
		Player *tmp,*curr;
		if(isEmpty(L))
	{
		cout<<"empty";
		return;
	}
	//if at head 
	if(L.head->name == name){
		tmp = L.head->next;
		tmp-> prev = NULL;
		delete L.head;
		L.head = tmp;
		return;
	}
	//if at rear
	if(L.head->name == name){
		tmp = L.rear;
		L.rear->next = NULL;
		delete L.rear;
		L.rear = tmp;
		return;
	}
	curr = L.head;
	while(curr!=NULL && curr->name != name)
		curr = curr->next;
	if(curr == NULL){
		cout<<"not found";
		return;
	}
	curr->next->prev = curr->prev;
	curr->prev->next = curr->next;
	delete curr;
	}