#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define SIZE 100
int s[SIZE], top=-1;

void push(int elem)
{
s[++top]=elem;
}

int pop()
{
return(s[top--]);
}

void main()
{
char pofx[50],ch;
int i=0,op1,op2;
printf("read the postfix expression\n");
scanf("%s",pofx);
while((ch=pofx[i++])!='0')
{
if(isdigit(ch))
push(ch-'0');
else
{
op2=pop();
op1=pop();

switch(ch)
{
case '+' : push(op1 + op2); break;
case '-' : push(op1 + op2); break;
case '*' : push(op1 + op2); break;
case '/' : push(op1 + op2); break;
case '%' : push(op1 + op2); break;
}
}
}
printf("postfx expression: %s\n", pofx);
printf("result = %d\n", s[top]);
}
