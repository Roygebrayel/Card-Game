Node* initialize(Node* top)
{
	Top = NULL;
	return Top;
}

bool isEmpty(Node *top)
{
	return(top ==NULL);
}

Node* push (Node top,type val)
{
	Node * tmp = new Node;
	if(tmp == NULL)
		exit(1);
	tmp->data = val
	tmp->next = NULL;
	if(isEmpty(top))
	{
		top = tmp;
		return top;
	}
	tmp->next = top;
	top = tmp;
	return top;
}

Node *pop (Node* top,type &val)//val can be *val so we:
{
	if(isEmpty(top))
		return NULL;
	val = top-> data;          //*val
	Node *tmp;
	tmp = top->next;
	delete top;
	top = tmp;
	return top;
}

void Display(Node* top)
{
	type val;
	while(!isEmpty(top)){
		top = pop(top,val)   //&val
		cout<<val<<" ";
	}
}
