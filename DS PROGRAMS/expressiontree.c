#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node*left;
    struct node*right;
};
typedef struct node *NODE;
struct stack
{
    int top;
    NODE arr[50];
};

NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)printf("memory full\n");
    return x;
}
void push(struct stack*s,NODE ele)
{
    if(s->top==49)
        printf("stack full\n");
    else
    {
        s->top++;
        s->arr[s->top]=ele;
    }
}

NODE pop(struct stack*st)
{
    NODE x;
    if(st->top==-1)
    {
        printf("stack empty\n");
        return NULL;
    }
    x=st->arr[st->top];
    st->top--;
    return x;
}
void inorder(NODE tree)
{
    if(tree!=NULL)
    {
    inorder(tree->left);
    printf("%c\t",tree->info);
    inorder(tree->right);
    }
}
void postorder(NODE tree)
{
    if(tree!=NULL)
    {
    postorder(tree->left);
    postorder(tree->right);
    printf("%c\t",tree->info);
    }
}
NODE createtree(char postfix[])
{
    NODE tree,temp;
    NODE lc,rc;
    char ch;
    int i;
    struct stack s;
    s.top=-1;
    for(i=0; i<strlen(postfix); i++)
    {
        ch=postfix[i];
        temp=getnode(ch);
        temp->info=ch;
        temp->left=NULL;
        temp->right=NULL;
        if(isdigit(postfix[i]))
        {
            push(&s,temp);
        }
        else
        {
           rc=pop(&s);
           lc=pop(&s);
           temp->right=rc;
           temp->left=lc;
           push(&s,temp);
        }
    }
    tree=pop(&s);
    return tree;
}
float evaluate(NODE tree)
{
    switch(tree->info)
    {
    case '+':return (evaluate(tree->left)+evaluate(tree->right));
    case '-':return (evaluate(tree->left)-evaluate(tree->right));
    case '*':return (evaluate(tree->left)*evaluate(tree->right));
    case '/':return (evaluate(tree->left)/evaluate(tree->right));
    case '^':return (pow(evaluate(tree->left),evaluate(tree->right)));
    case '$':return (pow(evaluate(tree->left),evaluate(tree->right)));
    default: return ((tree->info)-'0');
    }
}
int main()
{
    char postfix[20]="";
    NODE tree; float result;
    printf("enter postfix expression\n");
    scanf("%s",postfix);
    tree=createtree(postfix);
    result=evaluate(tree);
    inorder(tree);
    printf("\n");
    printf("%f\n",result);
    return 0;
}
