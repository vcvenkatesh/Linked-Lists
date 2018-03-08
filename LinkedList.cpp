# Linked-Lists
#Insert node at start , after or end nodes of the linked list.

#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};

void insert_first(struct node **root,int data){
	struct node *n_node = (struct node*)malloc(sizeof(struct node));
	n_node->data=data;
	struct node *ele = *root;
	if(ele == NULL){
		n_node->next=NULL;
	}
	else{
		n_node->next=*root;
	}
	*root = n_node;
}

void insert_after(struct node **root1,struct node *root,int d1,int data){
	struct node *n_node = (struct node*)malloc(sizeof(struct node));
	n_node->data=data;
	if(root==NULL){
		n_node->next = *root1;
		*root1=n_node;
		return;
	}
	while(root->data !=d1 && root->next != NULL){
		root=root->next;
	}
	if(root->next== NULL){
		cout<<"Can't find "<<d1<<" in the linked list"<<endl;
	}
	else{
		n_node->next = root->next;
		root->next = n_node;
	}
}

void insert_end(struct node **root1,struct node *root,int data){
	struct node *n_node = (struct node*)malloc(sizeof(struct node));
	n_node->data = data;
	if(root==NULL){
		n_node->next=*root1;
		*root1=n_node;
		return;
	}
	while(root->next != NULL){
		root=root->next;
	}
	root->next=n_node;
	n_node->next=NULL;
}

void print_ll(struct node *root){
	while(root != NULL){
		cout<<root->data<<" ";
		root=root->next;
	}
}

int main(){
	struct node *root = NULL;
	insert_first(&root,2);
	insert_first(&root,4);
	insert_after(&root,root,4,8);
	insert_end(&root,root,6);
	print_ll(root);
	return 0;
}
