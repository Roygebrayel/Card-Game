
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

struct cardHand{
int val;
string type;

cardHand *next;
};
struct QUEUECard{
cardHand* front;
cardHand* rear;
};
bool IsEmpty(QUEUECard q){
return (q.front==NULL);
}
void InitializeQueue(QUEUECard &q){
q.front=NULL;
q.rear=NULL;
}

void Enqueue (QUEUECard&q, int val,string type)
{
cardHand *tmp = new cardHand;
tmp->next=NULL;
tmp->val = val;
tmp ->type = type;
if(IsEmpty(q)) 
{
q.front = tmp;
q.rear = tmp;
return;
}
//insert at rear
q.rear->next = tmp;
tmp ->next = NULL; //already done in the initialisation
q.rear = tmp;
}

void Dequeue (QUEUECard&q, int &val,int & type)
{
cardHand *tmp;
if(IsEmpty(q))
{
cout<<"Empty";
return;
}
val = q.front->val;
string = q.front -> string;

tmp = q.front->next;
delete q.front;
q.front = tmp;
}
// displaying

void PrintQueue(QUEUECard q){
cardHand *cur;
if(IsEmpty(q)){

cout<<"The Queue is empty!!!" <<endl;
return;
}
cout<<"The content of the stack is: "<<endl;
while(!IsEmpty(q)){
Dequeue (q, val,int);
cout << val << "";
cout<<type<<" ";
}
}



