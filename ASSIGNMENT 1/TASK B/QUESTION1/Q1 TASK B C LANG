#include<stdio.h>
int  main(){
	int N,nights,season ;
	char roomtype;
	int i,finalprice,discount,hotelrev=0;
	
	printf("enter number of costumers:");
    scanf("%d",&N);
	
	for(i=0;i<N;i++){
		finalprice=0;
		discount=0;
	    printf("\nEnter number of nights: ");
        scanf("%d", &nights);

        printf("Enter room type:\n");
        printf("a= Standard\n");
        printf("b= Deluxe\n");
        printf("c = Suite\n");
        scanf(" %c", &roomtype);

        printf("Enter season:\n");
        printf("1 = Peak\n");
        printf("2 = Off-peak\n");
        scanf("%d", &season);
        switch(season){
		   case 1: 
             {
			   switch(roomtype){
			   
                 case 'a': 
                  finalprice=finalprice+(nights*5000);
                  break;
                  case 'b':
                     finalprice=finalprice+(nights*8000);
                     break;
                     case 'c':
                     	finalprice=finalprice+(nights*12000);
                     	break;
						 }
             }
                     break;
            case 2: {
				        switch(roomtype){
				         case 'a': 
				             finalprice=finalprice+(nights*3000);
				          break;
				          case 'b': 
				              finalprice=finalprice+(nights*5000);
				           break;
				           case 'c':
				        	 finalprice=finalprice+(nights*8000);
				        	 break;
				          }
				        	}
			        break;
                     }
            if(nights>7){
			
              discount=finalprice*15/100;
              finalprice=finalprice-discount;
			  }
			  printf("The final price is %d\n",finalprice);
			  
			  hotelrev=hotelrev+finalprice;
			  
	}
		
	    printf("TOTAL HOTEL REVENUE :%d",hotelrev);
	    
		

return 0;
	
	
	
	}
