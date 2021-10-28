#include <stdio.h>
#include<time.h>
void main(){
    long int N1 ,N2;
     printf("Enter the range");
	scanf("%ld %ld",&N1,&N2);
    clock_t t;
    long int len = N2-N1+1,i ,j, r , temp;
    long int num[len];
    //Fill array with desired numbers
    for( temp=0,i=N1; temp<len; i++,temp++ )
        num[temp] = i;

    srand( time(NULL) );  //seed rand()

    //Fisher–Yates shuffle algorithm
    for( i=len-1; i>0; i-- ){
        r = rand()%i;   //pop random number
        //swaping using temp
        temp = num[i];
        num[i] = num[r];
        num[r] = temp;
    }

    /*Random Numbers b/w N1-N2 are stored in Array num*/

    //print the array
    for( i=0; i<len; i++ )
        printf("%ld\n",num[i]);

      t = clock();
    for(i=N2-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(num[j]>num[j+1])
	{
           temp=num[j];
           num[j]=num[j+1];
           num[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<N2;i++)
 {
      printf(" %ld",num[i]);
      } 
  t =clock() - t;
      double time_taken = ((double)t)/CLOCKS_PER_SEC;
  
     printf("\n\nfun() took %f seconds to execute \n\n", time_taken); 
  }

