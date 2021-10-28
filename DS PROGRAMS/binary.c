#include<stdio.h>

int bs(int a[], int key, int low, int high)
{
int mid;
if(low>high)
return -1;
else
{
mid=(low+high)/2;
if(key==a[mid])
return(mid);
if(key<a[mid])
bs(a,key,low,mid-1);
else
bs(a,key,mid+1,high);
}
}

void main()
{
int i, n, pos, key, a[10];
printf("enter the array size\n");
scanf("%d",&n);
printf("enter the array elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the key element\n");
scanf("%d",&key);
pos=bs(a,key,0,n-1);
if(pos==-1)
printf("elements not found\n");
else
printf("elements found at %d location", pos);
}
