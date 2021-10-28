#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr;
NODE *getnode(int value)
{
	newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
		printf("Memory was not allocated\n");
	else
	{
		newnode->data=value;
		newnode->link =NULL;
		return newnode;	
	}
}
void push()
{
	int value;
	printf("Enter the element for the stack:\n");
	scanf("%d",&value);
	newnode=getnode(value);
	currptr=start;
	start=newnode;
	start->link=currptr;
	printf("ELEMENT PUSHED\n");
}
void pop()
{
	if(start==NULL)
		printf("Stack Underflow\n");
	else
	{
		currptr=start;
		start=start->link;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
}
void display()
{
	if(start==NULL)
		printf("Stack Underflow\n");
	else
	{
        	for(currptr=start;currptr!=NULL;currptr=currptr->link)
			printf("%d\n", currptr->data);
	}
}
void top()
{
    if(start==NULL)
        printf("Stack Underflow\n");
	else
        printf("%d\n",start->data);
}
void main()
{
	int ch;
	while(1)
	{	
		printf("Press 1 to push\nPress 2 to pop\nPress 3 to display\nPress 4 for top element\nPress 5 to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: top();
				break;
			case 5: exit(0);
			default: printf("Incorrect choice\n");
		}
	}
}
