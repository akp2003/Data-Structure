#include <iostream>
using namespace std;

// insert and remove sorted circular list									

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
	do{
		cout << next->data << " " ;
		next = next->link;
	}while (next != ptr);
	cout << endl;
}

void insert(np *ptr,int data){
	np temp = new node(data); 
	//insert in empty
	if (*ptr==NULL){
		temp->link=temp;
		*ptr = temp;
		return;
	}
	//insert first
	if ((*ptr)->data>=data){
		np cur = *ptr;
		while (cur->link!=*ptr)
			cur = cur->link;
		//cur is last
		temp->link=*ptr;
		cur->link=temp;
		*ptr=temp;
		return;
	}
	//insert middle
	np cur = *ptr;
	while (cur->link!=*ptr){
		if (cur->link->data>=data){
			temp->link=cur->link;
			cur->link=temp;
			return;
		}
		cur = cur->link;
	}
	//insert end
	temp->link=*ptr;
	cur->link=temp;
}

int remove(np *ptr,int data){
	if (*ptr == NULL){
		//cout << "  There is nothing to remove!!!" << endl;
		return -1;
	}
	//only one element
	if ((*ptr)->link==*ptr && (*ptr)->data==data){
		*ptr=NULL;
		return data;
	}
	// remove first
	if ((*ptr)->data==data){
		np cur = *ptr;
		while (cur->link!=*ptr)
			cur = cur->link;
		//cur is last
		cur->link=(*ptr)->link;
		*ptr=(*ptr)->link;
		return data;
	}
	// remove middle
	np cur = *ptr;
	while (cur->link!=*ptr){
		if (cur->link->data==data){
			cur->link=cur->link->link;
			return data;
		}
		cur = cur->link;
	}
	return -2;
}

int main(int argc, char *argv[])
{
	print(p);
	insert(&p,5);
	print(p);
	insert(&p,7);
	print(p);
	insert(&p,9);
	print(p);
	insert(&p,4);
	print(p);
	insert(&p,90);
	print(p);
	insert(&p,32);
	print(p);
	
	cout << "  remove 5 :" << remove(&p,5)<<endl;
	print(p);
	cout << "  remove 6 :" << remove(&p,6)<<endl;
	print(p);
	cout << "  remove 7 :" << remove(&p,7)<<endl;
	print(p);
	cout << "  remove 9 :" << remove(&p,9)<<endl;
	print(p);
	cout << "  remove 30 :" << remove(&p,30)<<endl;
	print(p);
	cout << "  remove 3000 :" << remove(&p,3000)<<endl;
	print(p);
	cout << "  remove 32 :" << remove(&p,32)<<endl;
	print(p);
	cout << "  remove 90 :" << remove(&p,90)<<endl;
	print(p);
	cout << "  remove 4 :" << remove(&p,4)<<endl;
	print(p);
	
	insert(&p,5);
	print(p);
	insert(&p,9);
	print(p);
	insert(&p,3);
	print(p);
	insert(&p,10);
	print(p);
	
	cout << "  remove 3 :" << remove(&p,3)<<endl;
	print(p);
	cout << "  remove 4 :" << remove(&p,4)<<endl;
	print(p);
	cout << "  remove 10 :" << remove(&p,10)<<endl;
	print(p);
}