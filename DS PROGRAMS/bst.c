#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*left;
    struct node*right;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)printf("memory full\n");
    return x;
}
NODE maketree(int ele)
{
    NODE root=getnode();
    root->info=ele;
    root->left=NULL;
    root->right=NULL;
    return root;
}
NODE setleft(NODE p,int ele)
{
    NODE c;
    if(p->left!=NULL)
    {
        printf("left child already exists\n");
        return p;
    }
    c=getnode();
    c->info=ele;
    c->left=NULL;
    c->right=NULL;
    p->left=c;
    return p;
}
NODE setright(NODE p,int ele)
{
    NODE c;
    if(p->right!=NULL)
    {
        printf("right child already exists\n");
        return p;
    }
    c=getnode();
    c->info=ele;
    c->left=NULL;
    c->right=NULL;
    p->right=c;
    return p;
}
void inorder(NODE tree)
{
    if(tree!=NULL)
    {
    inorder(tree->left);
    printf("%d\t",tree->info);
    inorder(tree->right);
    }
}
int main()
{
    NODE tree;
    int ele;
    NODE p,c;
    printf("enter root\n");
    scanf("%d",&ele);
    tree=maketree(ele);
    printf("enter ele\n");
    scanf("%d",&ele);
    while(ele!=-1)
    {
         p=tree;
         c=tree;
    while(c!=NULL)
    {
        p=c;
        if(ele<p->info)
            c=p->left;
        else
            c=p->right;
    }
    if(p->info>ele)
        p=setleft(p,ele);
    else
        p=setright(p,ele);
        scanf("%d",&ele);
    }
    inorder(tree);
    return 0;
}
