#include<stdio.h>
void selectionsort();
int a[30],n;
void main()
{
int i;
printf("enter size of array:");
scanf("%d",&n);
printf("enter array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
selectionsort();
printf("after sorting\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);

}
 void selectionsort()
{
int i,j,min,temp;
for(i=0;i<n;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[min])
min=j;
}
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
