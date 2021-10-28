#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{ 
	int coef;
	int power;
	struct node *link;
};

struct node *temp,*start=NULL,*ptr,*curptr;


void display()
{
	if (start == NULL)
	printf(" Empty List");
	else
	{
		ptr = start;
		while (ptr != NULL)
		{
			printf("%d:%d  ",ptr->coef,ptr->power);
			ptr = ptr->link;
		}
	}
}
	

void insert_node()
{	int ch = 1;
	while (ch == 1)
	{	
	temp = (struct node*) malloc(sizeof(struct node));
	printf("Enter the coeffcient and power \n");
	scanf("%d%d",&temp->coef,&temp->power);
	printf("%d%d",temp->coef,temp->power);
	temp->link=NULL;
	
	if (start == NULL)
		start = temp;
	else
	if (temp->power > start->power)
	{
		temp->link = start;
		start = temp;
	}
	else
	{
	ptr = start;
	while ((ptr !=NULL) && (temp->power < ptr->power))
	{	curptr = ptr;
		ptr = ptr->link;
	}
	
	if (ptr == NULL)
	{
		curptr->link = temp;
	}
	else
	{
		temp->link = curptr->link;		
		curptr->link = temp;
	}
	}
 	printf("Do u want to continue: 1 for YES, 0 for NO");
	scanf("%d",&ch);
	
	}
	
}

int evaluate()
{	int x,result=0;
	ptr = start;
	printf(" Enter the value of x");
	scanf("%d",&x);
	
	while (ptr !=NULL)
	{	
		result = result + ptr->coef * pow(x,ptr->power);
		ptr = ptr->link;
	}
	printf(" The result of the expression is %d", result);
}


void main()
{
	insert_node();
	//insert_node();
	display();
	evaluate();
}
