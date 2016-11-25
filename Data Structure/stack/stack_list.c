#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct node { 
    int data; 
    struct node *next; 
}; 

struct node * push(struct node *top,int data);
struct node * pop(struct node *top);
void Show(struct node *top);

struct node * push(struct node *top,int data)
{
	struct node *pNew;
	pNew = (struct node *)malloc(sizeof(struct node));
	
	if (pNew == NULL){
        	printf("\nThe Memory allocation error!!!\n\n");
        	exit(1);
	}else{
		pNew->data =data;
		pNew->next = top;
		top= pNew;
	}
	
        printf("Add a (%d)\n",top->data);
        
        return top;
    
}

struct node * pop(struct node *top)
{
	struct node *pDel;
	if (top == NULL)
		printf("-------\nThe stack is empty!!\n-------\n");
	else{
    		printf("Delete a (%d)\n", top->data);
    		pDel = top;
    		top = top->next;
    		free(pDel);
	}//else      
    return top;
}

void Show(struct node *top)
{
	printf("------------------------\n");
	if(top==NULL){
		printf("The stack is empty!!\n\n");
		return;
	}
 
	while(top!=NULL){
		printf("(%d)\n", top->data);
		top =top->next;
	}								
	printf("------------------------\n");				
}

int main(void)
{
	struct node *top=NULL;
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
				top = push(top,input);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				Show(top);
				break;
			case -1:
				return 0;
			default:
				printf("The select is error!\n");				
		}//switch	
	}//while
	return 0;
}
