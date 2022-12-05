

// struct of player
struct player{
	int index;
	card cardInHand;


};


//struct of card
struct card
{

	int value;
	string type;
	card *next;
};


//initializing card struct



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

card *push(card top, card val)
{
	card *tmp = new card;
	if (tmp == NULL)
		exit(1);
	tmp->data = value;
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

card *pop(card *top, type &val) // val can be *val so we:
{
	if (isEmpty(top))
		return NULL;
	val = top->data;
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
			  cout
			  << val << " ";
	}
}
