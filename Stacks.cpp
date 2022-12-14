#include <stdio.h>
# include <iostream>
using namespace std;

//struct of card
struct card
{
	int value;
	string type;
	card *next;
};

 void initialize(card *&top)
{
	top = NULL;
	
}

// is empty function

bool isEmpty(card *top)
{
	return (top == NULL);
}

// push function

card *push(card *top, int val, string type)
{
	card *tmp = new card;
	if (tmp == NULL)
		exit(1);
	tmp->value = val;
	tmp->type = type;
	tmp->next = NULL;
	if (isEmpty(top))
	{
		top = tmp;
		return top;
	}
	tmp->next = top;
	top = tmp;
	return top;
}

// pop function

card *pop(card *top, int &val, string &type) // val can be *val so we:
{
	if (isEmpty(top))
		return NULL;
	val = top->value;
	type = top-> type;
	card *tmp;
	tmp = top->next;
	delete top;
	top = tmp;
	return top;
}

// Display function

void DisplayStack(card* top)
{
	int value;
	string type;
	int i = 1;
	for(int j = 0;j<52;j++)
	{
		top = pop(top, value, type);
		
		cout <<"card "<<i<<": "<< value << " of " << type << endl;
		i++;
	}
}
