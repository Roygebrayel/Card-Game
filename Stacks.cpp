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

card *push(card *top, int val)
{
	card *tmp = new card;
	if (tmp == NULL)
		exit(1);
	tmp->value = val;
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

card *pop(card *top, int &val) // val can be *val so we:
{
	if (isEmpty(top))
		return NULL;
	val = top->value;
	card *tmp;
	tmp = top->next;
	delete top;
	top = tmp;
	return top;
}

// Display function

void Display(card *top)
{
	int value;
	while (!isEmpty(top))
	{
		top = pop(top, value);
			  cout << value << " ";
	}
}
