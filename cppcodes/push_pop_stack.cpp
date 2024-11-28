#include <iostream>
using namespace std;
typedef struct node *node_pointer;				

typedef struct node{
	int data;
	node_pointer link;
};

node_pointer ptr = NULL;

void print(node_pointer p){
	if (p == NULL){
		cout << "  There is nothing to print!!!" << endl;
		return;
	}
	node_pointer next = ptr;
	cout << "  ";
	while (next != NULL){
		cout << next->data << " " ;
		next = next->link;
	}
	cout << endl;
}

void push(int data){
	node *temp = new node();
	temp->data=data;
	temp->link=NULL;
	if (ptr == NULL){
		ptr = temp;
	}else{
		node_pointer next = ptr;
		while (next->link != NULL)
			next = next->link;
		next->link = temp;
	}
}

int pop(){
	if (ptr == NULL){
		cout << "  Stack is empty!!" << endl;
		return -1;
	}else if (ptr->link == NULL){
		// only one element
		int data = ptr->data;
		delete ptr->link;
		ptr = NULL;
		return data;
	}else{
		node_pointer next = ptr;
		while (next->link->link != NULL)
			next = next->link;
		int data = next->link->data;
		delete next->link;
		next->link = NULL;
		return data;
	}
}

int main(int argc, char *argv[])
{
	print(ptr);
	push(12);
	print(ptr);
	push(17);
	print(ptr);
	push(5);
	print(ptr);
	push(-8);
	print(ptr);
	cout << "  poped " << pop() << endl;
	print(ptr);
	cout << "  poped " << pop() << endl;
	print(ptr);
	cout << "  poped " << pop() << endl;
	print(ptr);
	cout << "  poped " << pop() << endl;
	print(ptr);
	cout << pop() << endl;
	print(ptr);
	push(12);
	print(ptr);
	push(167);
	print(ptr);
	push(5);
	print(ptr);
	push(-8);
	print(ptr);
}

