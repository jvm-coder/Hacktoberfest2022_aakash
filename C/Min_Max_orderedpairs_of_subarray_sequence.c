/*
   Using this code, you can read a sequence of numbers and find the 
   ordered pair (minimum value in subarray,maximum value in subarray)
   for the subarrays having user given size within the sequence length.
   WE will get a vector having these ordered pairs.
   
   For better understanding, refer the output for this code for a user
   defined sequence of length 6 and subarray of size 3 :- 

   Please enter no of element : 6
   Please enter the elements : 3
   2
   5
   4
   1
   9
   Please enter the size of sub array : 3

   OutPut : { (2,5) (2,5) (1,5) (1,9) }

   Here, first subarray(3,2,5) is taken and ordered pair(2,5) is got.
   Then, subarray(2,5,4) is taken and ordered pair(2,5) is got and so on.
   Each new subarray is considered by releasing the first element in the previous
   subarray and taking in the next element after the previous subarray.
*/

#include <stdio.h>

typedef struct queue5
{
    int data[40];
    int front;
    int rear;
    int limit;
}queue;

void enqueue(queue *aQueue,int data);
void dequeue(queue *aQueue);

int main(){
    int  i=0,s=0,j=0,mn=0,mnit=0,min,max,k,n,output[40][2];
    printf("Please enter no of element : ");
    scanf("%d",&n);
    int a[n];
    printf("Please enter the elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Please enter the size of sub array : ");
    scanf("%d",&k);
    queue aQueue={.front=0,.rear=0,.limit=k};
    // Min Max from sub array finder
    for(i=0;i<((n-k)+1);){
        if(s<k){
            enqueue(&aQueue,a[j]);
            j++;
            s++;
        }
        if(s==k){
            if(mn==0){
                min=aQueue.data[1]>aQueue.data[2]?aQueue.data[2]:aQueue.data[1];
			    max=aQueue.data[1]<aQueue.data[2]?aQueue.data[2]:aQueue.data[1];
                mn=3;
            }else{
                min = min>aQueue.data[mn]?aQueue.data[mn]:min;
			    max = max<aQueue.data[mn]?aQueue.data[mn]:max;
                if( mn==k ){
                    mnit=0;
                    mn=0;
                    output[i][0]=min;
                    output[i][1]=max;
                    dequeue(&aQueue);
                    i++;
                    s--;
                }else
                    mn++;
            }
        }
    }
    printf("\n OutPut : { ");
    for (i=0;i<((n-k)+1);i++){
        printf("(%d,%d) ",output[i][0],output[i][1]);
    }
    printf("}\n");
}

void enqueue(queue *aQueue,int data){
    if((aQueue->rear%aQueue->limit)+1!=aQueue->front){
        aQueue->rear=(aQueue->rear%aQueue->limit)+1;
        if(aQueue->front==0)
            aQueue->front++;
        aQueue->data[aQueue->rear]=data;
    }else
        printf("Queue is Full!\n");
}

void dequeue(queue *aQueue){
    if(aQueue->front!=0){
        int poped=aQueue->data[aQueue->front];
        aQueue->front=(aQueue->front%aQueue->limit)+1;
    }else
        printf("Queue is Empty!\n");
}