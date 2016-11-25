#include <stdio.h>
#include <stdlib.h>
struct node { 
    int data; 
    struct node *right,*left; 
}; 

struct node *createNode(void);
struct node *insertNode(struct node *tree,int inData);
struct node *seachNode(struct node *tree,int value);
struct node *findParent(struct node *tree,int value);
void print_PreOrder(struct node * tree);
void print_InOrder(struct node * tree);
void print_PostOrder(struct node * tree);
void displayAll(struct node *tree);
void destroyTree(struct node * tree);
struct node *deleteNode(struct node *tree,int value);

struct node *createNode(void)
{
	struct node *pNew;
  	pNew =(struct node *)malloc(sizeof(struct node));
  	
  	if(pNew==NULL){
  		printf("malloc failed!\n");
  		exit(1);
	}	  
	pNew->data=-1;
	pNew->left=NULL;   
    	pNew->right=NULL;   
	return pNew;   
}

struct node *insertNode(struct node *tree,int inData)
{  
    if(tree==NULL){
    	tree = createNode();
		tree->data=inData;
	}else if(inData<=tree->data){
			tree->left = insertNode(tree->left,inData);
	}else{
			tree->right = insertNode(tree->right,inData);
	}
   return tree;
}

struct node *seachNode(struct node *tree,int value)
{
	if(tree==NULL){
    	printf("\nValue does not exist in tree!\n");
    	return NULL;
	}else if(value==tree->data){
		printf("\nValue found\n");	
	}else if(value<tree->data){
			tree= seachNode(tree->left,value);
	}else{
			tree= seachNode(tree->right,value);
	}
	return tree;
}

struct node *findParent(struct node *tree,int value)
{
	struct node *parent=tree;
	while(tree!=NULL)
	{
		if(value==tree->data)
			return parent;
		else
			parent=tree; /*save parent pointer*/
			
		if(value<tree->data)
			tree = tree->left;
		else
			tree = tree->right;	
	}//while	
	return NULL;
}

void print_PreOrder(struct node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_PreOrder(tree->left);
        print_PreOrder(tree->right);
    }

}

void print_InOrder(struct node * tree)
{
    if (tree)
    {
        print_InOrder(tree->left);
        printf("%d\n",tree->data);
        print_InOrder(tree->right);
    }
}

void print_PostOrder(struct node * tree)
{
    if (tree)
    {
        print_PostOrder(tree->left);
        print_PostOrder(tree->right);
        printf("%d\n",tree->data);
    }
}

void displayAll(struct node *tree)
{
	struct node *head =tree;
	if (!tree){
		printf("\nNo any Data exist in tree!\n\n");
		return;	
	}	
	printf("------------------------\n");
	printf("Pre-Order\n");
	print_PreOrder(head);
	printf("------------------------\n");
	printf("In-Order\n");
	print_InOrder(head);
	printf("------------------------\n");
	printf("Post-Order\n");
	print_PostOrder(head);
	printf("------------------------\n\n");	
}

void destroyTree(struct node * tree)
{
    if (tree)
    {
        destroyTree(tree->left);
        destroyTree(tree->right);
        free(tree);
    }
}


struct node *deleteNode(struct node *tree,int value)
{
	struct node *parent,*ptrDel,*replace;
	int pos;
	parent = findParent(tree,value);/* find previous point*/
	if(parent==NULL){
		printf("\nValue does not exist in tree!\n");
    	return NULL;
	}	
	if(parent->left->data==value){
		ptrDel = parent->left;
		pos=0;
	}else if(parent->right->data==value){
		ptrDel =parent->right;
		pos=1;
	}else{
		ptrDel = parent;
	}//else
	
	if( ptrDel->left == NULL && ptrDel->right == NULL){/*Delete end leaf*/
		if(pos)
				parent->right = NULL;
		else	
				parent->left = NULL;
		free(ptrDel);		
	}else if(ptrDel->left==NULL){	/*Non-left tree*/
		if(parent==ptrDel)
			tree = tree->right;
		else{
			if(pos)
				parent->right = ptrDel->right;
			else	
				parent->left = ptrDel->right;					
		}//else	
		free(ptrDel);		
	}else if(ptrDel->right==NULL){	/*Non-Right tree*/
		if(parent==ptrDel)
			tree = tree->left;
		else{
			if(pos)
				parent->right = ptrDel->left;
			else	
				parent->left = ptrDel->left;	
		}//else		
		free(ptrDel);	
	}else{	/* left tree and Right tree is exist*/
		replace = ptrDel->left; /*point to left side of child node*/
		parent = ptrDel;
		printf("ptrDel->data:%d\n\n",ptrDel->data);
		printf("ptrDel->left->data:%d\n\n",ptrDel->left->data);
		while(replace->right!=NULL)/*find maximum key node in riggt side*/
		{
			printf("replace->data:%d\n\n",replace->data);
			parent = replace;
			replace = replace->right;
		}//while 
		ptrDel->data = replace->data;
		if(parent->left == replace)
			parent->left = replace->left;
		else
			parent->right = replace->left;
		free(replace);
	}//else		
		return tree;	
}

int main(void)
{
	struct node * root=NULL,*tree=NULL;
	int select=0,input=0;
	
	while(1)
	{
		printf("(1)Insert\n");
		printf("(2)Delete\n");
		printf("(3)Displaye\n");
		printf("(4)Search\n");
		printf("(5)Clean Data\n");
		printf("(-1)Leave program\n\n");
		printf("Please select a option:");
		scanf("%d", &select);
		switch(select){
			case 1:
				printf("Please input the number to insert :");
				scanf("%d",&input);
				root = insertNode(root,input);
				break;
			case 2:
				printf("Please input the number to delete :");
				scanf("%d",&input);
				root = deleteNode(root,input);
				break;
			case 3:
				displayAll(root);
				break;
			case 4:
				printf("Please input the number to search :");
				scanf("%d",&input);
				tree = seachNode(root,input);
				if(tree)
					printf("Value:%d\n\n",tree->data);
				break;	
			case 5:
				printf("The Data is empty\n\n");
				destroyTree(root);
				root=NULL;
				break;
			case -1:
				return 0;
			default:
				printf("The select is error!\n");				
		}//switch	
	}//while
	return 0;
}
