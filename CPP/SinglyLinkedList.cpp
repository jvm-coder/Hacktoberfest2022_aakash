#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	
	int data ;
	Node* p;
};

class LinkedList{
	public :
		Node* head;
		int max_index;
		LinkedList();
		void print();
		void DeleteFromEnd();
		void DeleteFromFront();
		void InsertAtEnd(int v);	
		void InsertAtFront(int v);	
		void InsertAtIndex(int v,int index);	
		void DeleteFromIndex(int index);	
};

LinkedList::LinkedList(){

	head=NULL; 
	max_index=-1;	
}

void LinkedList::print(){
	
	if(head!=NULL){
	
		Node* temp= head;
		while(temp!=NULL)
		{
			cout<<temp->data<<",";
			temp=temp->p;
		}
	cout<<endl;
	
} else cout<<"List is empty"<<endl;
}

void LinkedList::InsertAtFront(int v){
Node* x = new Node;
x->p=head;
x->data=v;
head=x;
max_index++;
}

void LinkedList::InsertAtIndex(int v,int index){
    if(index==0)
        InsertAtFront(v);
   
    else if(index>0 && index<=max_index)
    {
     Node*  new_node = new Node;
     new_node->data=v;
     Node * temp = head;
     for(int i=1;i<index;i++){
        temp = temp->p; 
         }
     new_node->p=temp->p;
     temp->p=new_node; 
     max_index++;
    }
    else cout<<"Index out of range";
}

void LinkedList::InsertAtEnd(int v){
	
	Node* temp = head;
	if(temp!=NULL)
{
	while(temp->p!=NULL)
		temp=temp->p;
	Node* x = new Node;
	temp->p=x;
	x->data=v;
	x->p=NULL;
	max_index++;	
	
}

else InsertAtFront(v);

}


void LinkedList::DeleteFromEnd(){
	if(head!=NULL){	
	if(head->p==NULL)			
	{
		Node * tempP=head; 
		head=NULL;	
		delete tempP;
		max_index--;
	}
	else{
	Node* temp = head;
	Node* temp1=temp->p  ;
	while(temp1->p!=NULL)	{
		temp=temp->p;
		temp1=temp->p;
	}
	temp->p=NULL; delete temp1;
    max_index--;}}
    else cout<<"Nothing to delete!\n";}



void LinkedList::DeleteFromIndex(int index){
	if(head!=NULL){	
	if(index==0)			
		DeleteFromFront();
	else if(index==max_index)
	    	DeleteFromEnd();
	else if(index>0 && index<=max_index){
	Node* temp = head;
	Node* temp1=temp->p  ;
	for(int i=1;i<index;i++)	{
		temp=temp->p;
		temp1=temp->p;
	}
	temp->p=temp1->p; delete temp1;
    max_index--;}
    else cout<<"Index out of range\n";
    }

    else cout<<"Nothing to delete!\n";}


void LinkedList::DeleteFromFront(){
    if(head!=NULL){ 
        Node * temp = head; 
        head=head->p; 
        delete temp;
        max_index--;}
    else cout<<"Nothing to delete!\n";
}




int main(int argc, char** argv) {
	LinkedList L;
	L.InsertAtFront(1);
	L.print();
	L.InsertAtEnd(2);
	L.print();
	L.InsertAtIndex(3,0);
	L.print();
	L.InsertAtIndex(2,1);
	L.print();
	L.DeleteFromIndex(3);
	L.print();
	L.DeleteFromIndex(1);
	L.print();
	L.DeleteFromEnd();
	L.print();
	L.DeleteFromFront();
	L.print();
		
	
	
	return 0;
}
