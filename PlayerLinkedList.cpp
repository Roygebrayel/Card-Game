# include <iostream>
# include <stdio.h>
using namespace std;

struct Player{
	string name;
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
		cout<<curr ->name<<" ";
		curr = curr -> next;
	}
}

Player* Search(List L, string val){
	Player* curr1;
	Player* curr2;
	if(isEmpty(L)){
		cout<<"empty";
		return;
	}
	curr1 = L.head;
	curr2 = L.rear;
	while(curr1->name != curr2->name && curr2->prev != curr1 || curr1 != curr2){
		if(curr1->name == val)
			return curr1;
		if(curr2->name == val)
			return curr2;
		curr1 = curr1->next;
		curr2 = curr2->prev;
	}
	return NULL;
}

void insertAtHead(List &L, string val){
	Player* tmp;
	tmp = new Player;
	if(tmp == NULL)
		exit(1);
	tmp->name = val;
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

void insertAtRear(List& L, string val) {
	Player* tmp;
	tmp = new Player;
	if (tmp == NULL)
		exit(1);
	tmp->name = val;
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
	
	void RemovePlayer(List L, int val){
		Player *tmp,*curr;
		if(isEmpty(L))
	{
		cout<<"empty";
		return;
	}
	//if at head 
	if(L.head->name == val){
		tmp = L.head->next;
		tmp-> prev = NULL;
		delete L.head;
		L.head = tmp;
		return;
	}
	//if at rear
	if(L.head->Player.neme == val){
		tmp = L.rear;
		L.rear->next = NULL;
		delete L.rear;
		L.rear = tmp;
		return;
	}
	curr = L.head;
	while(curr!=NULL && curr->Player.name != val)
		curr = curr->next;
	if(curr == NULL){
		cout<<"not found";
		return;
	}
	curr->next->prev = curr->prev;
	curr->prev->next = curr->next;
	delete curr;
	}