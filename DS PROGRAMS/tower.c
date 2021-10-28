#include<stdio.h>
void toh(int n, char source, char space, char destination)

{
if(n==1)
{
printf("move disk from %c to %c\n", source, destination);
}
else
{
toh(n-1, source, destination, space);
printf("move disk from %c to %c\n", source, destination);
toh(n-1, space, source, destination);
}
}
void main()
{
int n=3;
toh(n, 'A','B','c');
}
