#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int push(int stack[],int top,int data);
int pop(int stack[],int top);
void Show(int stack[],int top);

int push(int stack[],int top,int data)
{
    if (top == MAX_SIZE)
        printf("\nThe stack is full!!!\n\n");
    else
         printf("Add a (%d)\n",stack[top++] = data);
        
        return top;
    
}

int pop(int stack[],int top)
{
    if (top == 0)
        printf("-------\nThe stack is empty!!\n-------\n");
    else
        printf("Delete a (%d)\n", stack[--top]);
        
    return top;
}

void Show(int stack[],int top)
{
	printf("------------------------\n");
	if(top==0){
		printf("The stack is empty!!\n\n");
		return;
	}
 
	while(!top==0)
					printf("(%d)\n", stack[--top]);				
	printf("------------------------\n");				
}

int main(void)
{
	int stack[MAX_SIZE]={0};
	int top = 0;//No any stack
	int select=0,input=0;
	
	while(1)
	{
		printf("(1)Push a one value\n");
		printf("(2)Pop a one value\n");
		printf("(3)Show all stack value\n");
		printf("(-1)Leave program\n\n");
		printf("Please select a option:");
		scanf("%d", &select);
		switch(select){
			case 1:
				printf("please input any a value :");
				scanf("%d",&input);
				top = push(stack,top,input);
				break;
			case 2:
				top=pop(stack,top);
				break;
			case 3:
				Show(stack,top);
				break;
			case -1:
				return 0;
			default:
				printf("The select is error!\n");				
		}//switch	
	}//while

	return 0;
}
