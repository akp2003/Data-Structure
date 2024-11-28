#include <iostream>
using namespace std;
typedef struct node *np;				

typedef struct node{
	int data;
	np link;
	node(int dt) : data(dt), link(NULL) {}
};

np ptrA = NULL;

np ptrB = NULL;


// merge two sorted linked list
void merge(np ptrA,np ptrB,np *ptrC){
	np curA = ptrA;np curB = ptrB;
	np curC = NULL;
	if (ptrA->data<ptrB->data){
		*ptrC = ptrA;
		curA=ptrA->link;
	}
	if (ptrB->data<=ptrA->data){
		*ptrC = ptrB;
		curB=ptrB->link;
	}
	curC = *ptrC;
	while (curA != NULL && curB != NULL){
		if (curA->data<curB->data){
			curC->link = curA;
			curA=curA->link;
		}else{
			curC->link = curB;
			curB=curB->link;
		}
		curC = curC->link ;
	}
	if (curA==NULL)
		curC->link = curB;
	if (curB==NULL)
		curC->link = curA;
}


int main(int argc, char *argv[])
{
	np A = new node(3); 
	A->link = new node(7); 
	
	np B = new node(5); 
	B->link = new node(300); 
	np C = NULL;
	merge(A,B,&C);
	cout << "   " << C->data<< endl;
	cout << "   " << C->link->data<< endl;
	cout << "   " << C->link->link->data<< endl;
	cout << "   " << C->link->link->link->data<< endl;
	
	//this code is written on earth 
	//by a human!!
	//ARSHAK PARSA :)
}