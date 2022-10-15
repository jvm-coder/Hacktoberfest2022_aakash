#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data=d;
		left=right=NULL;
	}
};

Node *prev=NULL;
Node *binarytoll(Node *root)
{
	if(root==NULL) return NULL;
	Node *head=binarytoll(root->left);
	if(prev==NULL)
	head=root;
	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	binarytoll(root->right);
	return head;
}

void traverse(Node *root)
{
	if(root==NULL) return ;
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root=root->right;
	}
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(15);
	root->right=new Node(20);
	root->left->left=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->left->left=new Node(60);
	root->right->left->right=new Node(70);
	Node *temp=binarytoll(root);	
	traverse(temp);
	
		
}
