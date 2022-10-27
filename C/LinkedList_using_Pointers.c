#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*head,*nod;
void createLL(int n){
    struct Node *node,*temp;
    int num,i;
    head = (struct Node*) malloc(sizeof(struct Node));
    if (head==NULL){
        printf("mem connot be allocated");
    }
    else{
        printf("Data in node 1:");
        scanf("%d",&num);
        head->data = num;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++){
            node=(struct Node*) malloc(sizeof(struct Node));
            if (node==NULL){
                printf("mem cannot be allocated");
                break;
            }
            else{
                printf("Data in node %d:",i);
                scanf("%d",&num);
                node->data=num;
                node->next=NULL;
                temp->next=node;
                temp=temp->next;
            }
        }
    }
    nod=head;
}
void printLL(struct Node *nod){
  struct Node* node=nod;
  printf("The Linked list is\n"); 
  while(node){
     printf("%d->",node->data);
     node=node->next;
  }
  printf("NULL");
}
int main(){
    int num;
    printf("Enter the number of nodes in linked list:");
    scanf("%d",&num);
    printf("\n");
    
    createLL(num);
    printLL(head);
    return 0;
}
