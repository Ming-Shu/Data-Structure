#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int enqueue(int queue[],int rear,int data);
int dequeue(int queue[],int front );
void Show(int queue[],int front ,int rear);

int enqueue(int queue[],int rear,int data)
{
    if (rear> MAX_SIZE)
        printf("\nThe queue is full!!!\n\n");
    else
         printf("Add a (%d)\n",queue[rear++] = data);
        
        return rear;
    
}

int dequeue(int queue[],int front)
{
    if (front > MAX_SIZE)
        printf("-------\nThe queue is empty!!\n-------\n");
    else
        printf("Delete a (%d)\n", queue[front++]);
        
    return front;
}

void Show(int queue[],int front ,int rear)
{
	printf("------------------------\n");
	if(front == rear){
		printf("The queue is empty!!\n\n");
		return;
	}
	while(front!=rear)
					printf("(%d)\n", queue[front++]);			
	printf("\n------------------------\n");				
}

int main(void)
{
	int queue[MAX_SIZE]={0};
	int front=0,rear=0;
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
				rear = enqueue(queue,rear,input);
				break;
			case 2:
				front = dequeue(queue,front);
				break;
			case 3:
				Show(queue,front ,rear);
				break;
			case -1:
				return 0;
			default:
				printf("The select is error!\n");				
		}//switch	
	}//while

	return 0;
}
