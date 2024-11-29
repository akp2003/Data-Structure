#include <iostream>
using namespace std;

typedef struct ttree *tp;
typedef struct ttree{
	bool lt;
	tp left_child;
	char data;
	bool rt;
	tp right_child;
	ttree(char dt) : data(dt), lt(true), rt(true){}
};

tp root= new ttree('R');

void printNode(tp node){
	cout << " " << node->data << " [label=\"<l> " << node->lt<<"|<m>"<< node->data <<"|<r> "<< node->rt <<"\"]; " << endl;
	if (node->left_child!=NULL){						
		cout <<" "<< node->data << ":l" << " -> " << node->left_child->data << ":m";							
		if (node->lt){
			cout << " [style=dotted]" << endl;
		}else{		
			cout <<endl;				
			if (node != node->left_child)
				printNode(node->left_child);
		}
	}
	if (node->right_child!=NULL){						
		cout <<" " << node->data << ":r" << " -> " << node->right_child->data<<":m";							
		if (node->rt){
			cout << " [style=dotted]" << endl;
		}else{		
			cout <<endl;				
			if (node != node->right_child)
				printNode(node->right_child);
		}
	}
}
void printTTree(tp root){
	cout << "digraph Gr {" << endl;
	cout << "node [shape=record];" << endl;
	printNode(root);
	cout << "}" << endl;
}

tp insucc(tp tree){
	tp temp = tree->right_child;
	if (!tree->rt)
		while(!temp->lt)
			temp = temp->left_child;
	return temp;
}

tp inprev(tp tree){
	tp temp = tree->left_child;
	if (!tree->lt)
		while(!temp->rt)
			temp = temp->right_child;
	return temp;
}

tp insert_new_left(tp node,char data){
	tp temp = new ttree(data);
	temp->left_child = node->left_child;
	temp->right_child = node;
	temp->lt=node->lt;
	
	node->lt =false;
	node->left_child=temp;
	return temp;
}

tp insert_new_right(tp node,char data){
	tp temp = new ttree(data);
	temp->left_child = node;
	temp->right_child = node->right_child;
	temp->rt=node->rt;
	
	node->rt =false;
	node->right_child=temp;
	return temp;
}

tp insert_left(tp node,char data){									
	tp temp = insert_new_left(node,data);
	// fix previous
	tp prev=inprev(temp);
	if (prev->rt)
		prev->right_child=temp;
	return temp;
}

tp insert_right(tp node,char data){
	tp temp = insert_new_right(node,data);
	// fix succ
	tp succ=insucc(temp);
	if (succ->lt)
		succ->left_child=temp;
	return temp;
}

int main()
{
	// set root
	root->lt=1;
	root->left_child=root;
	root->right_child=root;
	root->rt=0;
	//
	//printTTree(root);
	
	//cout << " " << insucc(root)->data;
	/*
	tp A =insert_new_left(root,'A');
	tp B =insert_new_left(A,'B');
	tp C =insert_new_right(A,'C');
	tp D =insert_new_left(B,'D');
	tp E =insert_new_right(B,'E');
	tp F =insert_new_left(C,'F');
	tp G =insert_new_right(C,'G');
	tp H =insert_new_left(D,'H');
	tp I =insert_new_right(D,'I');
	
	tp A =insert_left(root,'A');
	tp B =insert_left(A,'B');
	tp C =insert_right(A,'C');
	tp D =insert_left(B,'D');
	tp E =insert_right(B,'E');
	tp F =insert_left(C,'F');
	tp G =insert_right(C,'G');
	tp H =insert_left(D,'H');
	tp I =insert_right(D,'I');
	*/
	
	tp A =insert_left(root,'A');
	tp B =insert_right(A,'B');
	tp C =insert_left(B,'C');
	tp D =insert_right(B,'D');
	tp E =insert_left(D,'E');
	tp F =insert_right(D,'F');
	tp X =insert_right(B,'X');
	printTTree(root);
	
}