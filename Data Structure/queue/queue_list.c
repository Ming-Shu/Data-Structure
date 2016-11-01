#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data; 
    struct node *next; 
}; 

struct node *enqueue(struct node * rear,int data);
struct node *dequeue(struct node * front );
void Show(struct node *front );

struct node *enqueue(struct node * rear,int data)
{
	struct node *pNew;
  	pNew =(struct node *)malloc(sizeof(struct node));
  	
	printf("Add a (%d)\n",pNew->data= data);
    pNew->next=NULL; 
    if(rear!=NULL)
    	rear->next =pNew;
    rear = pNew;
    
	return rear;
    
}

struct node *dequeue(struct node * front)
{
   struct node *pDel;
   
	if(front==NULL){
	    printf("-------\nThe queue is empty!!\n-------\n");	
	    return front;
	}

     	
    printf("Delete a (%d)\n", front->data);
    
    pDel = front;
    front = front->next;
	free(pDel);   
    return front;
}

void Show(struct node *front)
{
	printf("------------------------\n");
	if(front == NULL){
		printf("The queue is empty!!\n\n");
		return;
	}
	while(front!=NULL){
		printf("(%d)\n", front->data);
		front = front->next;						
	}
		
	printf("\n------------------------\n");				
}

int main(void)
{
	struct node * front=NULL,*rear=NULL;
	int select=0,input=0;
	
	while(1)
	{
		printf("(1)Enqueue a one value\n");
		printf("(2)Dequeue a one value\n");
		printf("(3)Show all queue  value\n");
		printf("(-1)Leave program\n\n");
		printf("Please select a option:");
		scanf("%d", &select);
		switch(select){
			case 1:
				printf("please input any a value :");
				scanf("%d",&input);
				rear = enqueue(rear,input);
				if(front==NULL)
						front = rear;
				break;
			case 2:
				front = dequeue(front);
				break;
			case 3:
				Show(front);
				break;
			case -1:
				return 0;
			default:
				printf("The select is error!\n");				
		}//switch	
	}//while

	return 0;
}
