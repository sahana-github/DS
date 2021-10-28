#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*prevptr;
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
void insert()
{
	int value;
	printf("Enter the element for the queue:\n");
	scanf("%d",&value);
	newnode=getnode(value);
	currptr=start;
	start=newnode;
	start->link=currptr;
	printf("ELEMENT INSERTED\n");
}
void delete()
{
	if(start==NULL)
		printf("Queue Underflow\n");
	else if(start->link==NULL)
	{
		currptr=start;
		start=NULL;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
	else
	{
		currptr=start;
		prevptr=NULL;
		while(currptr->link!=NULL)
		{
			prevptr=currptr;
			currptr=currptr->link;
		}
		prevptr->link=NULL;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
}
void display()
{
	if(start==NULL)
		printf("Queue Underflow\n");
	else
	{
        	for(currptr=start;currptr!=NULL;currptr=currptr->link)
			printf("%d ", currptr->data);
	}
}
void main()
{
	int ch;
	while(1)
	{	
		printf("\nPress 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 4 to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Incorrect choice\n");
		}
	}
}
