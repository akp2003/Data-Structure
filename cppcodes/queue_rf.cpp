#include <iostream>
using namespace std;
// linear queue 
// rear = first
// front = last

typedef struct node *np;				

typedef struct node{
	int data;
	np link;
	node(int dt) : data(dt), link(NULL) {}
};

np p = NULL;

void print(np ptr){
	if (ptr == NULL){
		cout << "  There is nothing to print!!!" << endl;
		return;
	}
	np next = ptr;
	cout << "  ";
	while (next != NULL){
		cout << next->data << " " ;
		next = next->link;
	}
	cout << endl;
}

void insert(np *ptr,int data){
	np temp = new node(data); 
	temp->link=*ptr;
	*ptr = temp;
}

int remove(np *ptr){
	if (*ptr == NULL){
		//cout << "  There is nothing to remove!!!" << endl;
		return -1;
	}
	if ((*ptr)->link == NULL) {
		int res = (*ptr)->data;
		*ptr = NULL;
		return res;
	}
	np cur = *ptr;
	while (cur->link->link!=NULL)
		cur = cur->link;
	int res = cur->link->data;
	cur->link = NULL;
	return res;
}

int main(int argc, char *argv[])
{
	print(p);
	insert(&p,5);
	print(p);
	insert(&p,6);
	print(p);
	insert(&p,6);
	print(p);
	insert(&p,4);
	print(p);
	
	cout << "  remove " << remove(&p)<<endl;
	print(p);
	cout << "  remove " << remove(&p)<<endl;
	print(p);
	cout << "  remove " << remove(&p)<<endl;
	print(p);
	cout << "  remove " << remove(&p)<<endl;
	print(p);
	cout << "  remove " << remove(&p)<<endl;
	print(p);
	
	print(p);
	insert(&p,5);
	print(p);
	insert(&p,9);
	print(p);
	insert(&p,3);
	print(p);
	
	cout << "  remove " << remove(&p)<<endl;
	print(p);
	
	insert(&p,7);
	print(p);
}