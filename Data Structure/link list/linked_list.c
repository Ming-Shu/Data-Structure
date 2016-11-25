#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data; 
    struct node *next; 
}; 

struct node *createNode(void);
struct node *insertNode(struct node *head,struct node *current,int data);
struct node *seachNode(struct node *head,int data);
void displayAll(struct node *head);
struct node *deleteNode(struct node *head,struct node *current);
int listLength(struct node *head);

struct node *createNode(void)
{
	struct node *pNew;
  	pNew =(struct node *)malloc(sizeof(struct node));
  	
  	if(pNew==NULL){
  		printf("malloc failed!\n");
  		exit(1);
	  }	  
	pNew->data=-1;  
    	pNew->next=NULL;   
	return pNew;   
}

struct node *insertNode(struct node *head,struct node *current,int data)
{
	struct node *newNode;
	newNode = createNode();
	newNode->data=data;  
   	newNode->next=NULL;  
    
	if(current==NULL){
    		newNode->next = head;/*if insert node in front of head*/
    		head = newNode;
	}else{
		if(current->next=NULL)
			current->next = newNode;
		else
		{
			newNode->next = current->next ;
			current->next = newNode;
		}		
	}
	return head;
}

struct node *seachNode(struct node *head,int data)
{
	while(head!=NULL&&head->data!=data)
		head=head->next;
	return head;
}

void displayAll(struct node *head)
{
	printf("------------------------\n");
	while(head!=NULL)
	{
		printf("(%d)\n",head->data);
		head=head->next;
	}
	printf("\n------------------------\n\n");	
}

struct node *deleteNode(struct node *head,struct node *current)
{
	struct node *previous=head;
	
	if(current==NULL)
	{
		printf("\n NO any Data!\n\n");
		return head;
	}
		
	if(current==head){/*if delete node is head*/
    		head = head->next;
	}else{
		while(previous->next!=current)
			previous = previous->next;
			
		if(current->next==NULL)
			previous ->next = NULL;
		else
		{
			previous ->next = current->next ;
		}		
	}
	free(current);
   return head;
}

int listLength(struct node *head)
{
	int num=0;
	while(head!=NULL)
	{
		head=head->next;
		num++;		
	}
	return num;
}

int main(void)
{
	struct node * head=NULL,*current=NULL;
	int select=0,input=0;
	
	while(1)
	{
		printf("(1)Insert\n");
		printf("(2)Delete\n");
		printf("(3)Displaye\n");
		printf("(4)Size\n");
		printf("(-1)Leave program\n\n");
		printf("Please select a option:");
		scanf("%d", &select);
		switch(select){
			case 1:
				printf("Please input the number to insert :");
				scanf("%d",&input);
				head = insertNode(head,current,input);
				break;
			case 2:
				printf("Please input the number to delete :");
				scanf("%d",&input);
				head = deleteNode(head,seachNode(head,input));
				break;
			case 3:
				displayAll(head);
				break;
			case 4:
				printf("The list length is %d\n\n",listLength(head));
				break;
			case -1:
				return 0;
			default:
				printf("The select is error!\n");				
		}//switch	
	}//while
	return 0;
}
