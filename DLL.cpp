

struct Node{
	int data;
	Node* next;
	Node* prev;
};

struct List{
	Node* head;
	Node* rear;
};

void initialize(List &L){
	L.head = NULL;
	L.rear = NULL;
}

List initialize(){
	List L;
	L.head = NULL;
	L.rear = NULL;
	return L;
}

bool isEmpty(List L){
	return(L.head == NULL || rear == NULL)
}

void printH2R(List L)
{
	if(isEmpty(l)){
		cout<<"empty";
		return;
	}
	Node* curr = L.head;
	while(curr!= NULL){
		cout<<curr -> data<<" ";
		curr = curr -> next;
	}
}

void printR2H(List L){
	if(isEmpty(l)){
		cout<<"empty";
		return;
	}
	Node* curr = L.rear;
	while(curr!= NULL){
		cout<<curr -> data<<" ";
		curr = curr -> prev;
	}
}

Node* Search(List L, int val){
	Node* curr;
	if(isEmpty(l)){
		cout<<"empty";
		return;
	}
	curr1 = L.head;
	curr2 = L.rear;
	while(curr1->next != curr2 && curr2->prev != curr1 || curr1 != curr2){
		if(curr1->data == val)
			return curr1;
		if(curr2->data == val)
			return curr2;
		curr1 = curr1->next;
		curr2 = curr2->prev;
	}
	return NULL;
}

void insertAtHead(List &L, int val){
	Node* tmp;
	tmp = new Node;
	if(tmp == NULL)
		exit(1);
	tmp->data = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	if(isEmpty(L))
	{
		L.head = tmp;
		L.rear = tmp;
		return;
	}                    // for rear
	L.head->prev = tmp;  // L.rear -> next = tmp;
	tmp->next=L.head;    // tmp -> prev = L.rear;
	L.head=tmp;          // L.rear = tmp;
}

void insertSorted(List&L,int val)
{
	Node* tmp = new Node;
	if(tmp == NULL)
		exit(1);
	tmp->data = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	if(isEmpty(L))
	{
		L.head = tmp;
		L.rear = tmp;
		return;
	}
	// test is at head
	if(L.head-> data > val)
	{
		L.head->prev = tmp;
		tmp->next=L.head;
		L.head=tmp;
		return;
	}
	if(L.rear-> data < val){
		L.rear -> next = tmp;
		tmp -> prev = L.rear;
		L.rear = tmp;
		return;
	}
	Node* curr = L.head;
	while(curr->next != NULL && curr->next->data < val){
		curr = curr->next;
	}
	tmp->next = curr->next;
	tmp->prev = curr;
	curr->next->prev = tmp;
	curr ->next = tmp
	}
	
	void RemoveNode(List L, int val){
		Node *tmp,*curr;
		if(isEmpty(L))
	{
		cout<<"empty";
		return;
	}
	//if at head 
	if(L.head-> data == val){
		tmp = L.head->next;
		tmp-> prev = NULL;
		delete L.head;
		L.head = tmp;
		return;
	}
	//if at rear
	if(L.head-> data == val){
		tmp = L.rear;
		L.rear->next = NULL;
		delete L.rear;
		L.rear = tmp;
		return
		return;
	}
	curr = L.head;
	while(curr!=NULL && curr-> data != val)
		curr = curr->next;
	if(curr == NULL){
		cout<<"not found";
		return;
	}
	curr->next->prev = curr->prev;
	curr->prev->next = curr->next;
	delete curr;
	}
	
		

		


		

































