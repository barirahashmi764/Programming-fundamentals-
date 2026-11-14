#include<stdio.h>
int sum_divisors(int n){
	int i,sum=0;
	for(i=1;i<=n/2;i++){
		if(n%i==0){
			sum=sum+i;
		}//end if
	}end for
	return sum;		
}end function 
int main(){
	int n,i,j,sum_1=0,sum_2=0,count=0;
	printf("enter a number :");
	scanf("%d",&n);
		
   for(i = 2; i <= n; i++){
        sum_1 = sum_divisors(i);
        j = sum_1;

        if(j >= 1 && j <= n){
            sum_2 = sum_divisors(j);

            if(sum_2 == i && i < j){
                printf("Amicable pair: (%d, %d)\n", i, j);
                count++;
            }//end if(i)
        }    //end if(j)   
}//end for
         if(count==0)
            printf("No Amicable pairs found .\n");
           else
              printf("Total pairs : %d \n ",count);

	
return 0;
}//end main
