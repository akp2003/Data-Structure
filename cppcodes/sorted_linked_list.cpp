#include <iostream>
using namespace std;

// insert and remove sorted linear list									

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
	if (*ptr==NULL){
		*ptr = temp;
		return;
	}
	if (data <= (*ptr)->data){
		temp->link = *ptr;
		*ptr = temp;
		return;
	}
	np cur = *ptr;
	while (cur->link!=NULL && cur->link->data<data)
		cur = cur->link;
	temp->link=cur->link;
	cur->link=temp;
}

int remove(np *ptr,int data){
	if (*ptr == NULL){
		//cout << "  There is nothing to remove!!!" << endl;
		return -1;
	}
	if ((*ptr)->data == data) {
		int res = (*ptr)->data;
		*ptr = (*ptr)->link;
		return res;
	}
	np cur = (*ptr);
	while (cur->link!=NULL && cur->link->data<data)
		cur = cur->link;
	if (cur->link!=NULL && cur->link->data==data){
		np temp=cur->link->link;
		int res = cur->link->data;
		cur->link=temp;
		return res;
	}else{
		return -2;
	}
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
	
	cout << "  remove 3 :" << remove(&p,3)<<endl;
	print(p);
	
}