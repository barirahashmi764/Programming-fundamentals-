#include<stdio.h>
#include<string.h>
//function to display the menu to the user
void displayMenu(){
    printf("\n===== UNIVERSITY LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}
//function to register a new member
void registerMember(char name[], int *studentID, int *memberType){
	printf("Enter Member Name :\n");
	scanf(" %[^\n]", name);
	printf("Enter Student ID :\n");
	scanf("%d",studentID);
	printf("Enter member type : \n 1-Faculty \n 2-Student \n");
	scanf("%d",memberType);
	//validating member type
	while(*memberType<1||*memberType>2){
	printf("Enter member type : \n 1-Faculty \n 2-Student \n");
	scanf("%d",memberType);
	}
}
//function to display the available books
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[],int totalBooks){
	int i;
    for(i=0;i<totalBooks;i++){
    	printf("| %d \t|    %s \t        |   %d |\n",bookIDs[i],bookTitles[i],availableCopies[i]);
	}
}
//function to boorow books
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[],
int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType){
	int bookID;
    int days;
    int i;
    int found = 0;
    int index=-1;
	printf("Enter Book ID you want to borrow :\n");
	scanf("%d",&bookID);
	printf("Enter days you want to borrow it for :\n");
	scanf("%d",&days);
	//validating days
	while(days<=0){
		printf("Invalid!\n");
		printf("Enter days you want to borrow it for :\n");
	    scanf("%d",&days);
	}
	//finding the book to borrow
	for(i=0;i<totalBooks;i++){
		if(bookID==bookIDs[i]){
			index=i;
			break;
		}
	}
	//checking if the bookid for borrowing is wrong
	if(index==-1){
		printf("Invalid Book ID !\n");
		return;
	}
	//checking to see available copies
	if(availableCopies[index]==0){
		printf("Sorry! No available copies.\n");
		return;
	}
	//checking borrow limit 
	if(*borrowedCount>=3){
		printf("You have reached the limit !\n");
		return;
	}
	//updating data
	borrowedBookIDs[*borrowedCount]=bookID;
	(*borrowedCount)++;
	availableCopies[index]--;
}
//function to return a book
float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int
borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine){
	int bookID;
    int i;
    int index = -1;
    int borrowIndex = -1;
    float fine = 0;
    int days;
    printf("Enter the actual number of days the book was kept:\n");
    scanf("%d", &days);
//validating days
    while(days <= 0){
    printf("Invalid days! Enter again:\n");
    scanf("%d", &days);
       }
    printf("Enter the Book ID you want to return :\n");
    scanf("%d",&bookID);
	//finding the bookid
    for(i=0;i<totalBooks;i++){
    	if(bookID==bookIDs[i]){
    		index=i;
    		break;
		}
	}
	//checking if the book id matched the borrowed bookid
	for(i=0;i<*borrowedCount;i++){
		if(bookID==borrowedBookIDs[i]){
			borrowIndex=i;
			break;
		}
	}
	
	if(index == -1){
    printf("Invalid Book ID!\n");
    return 0;
     }
 //checking if found 
    if(borrowIndex == -1){
    printf("You have not borrowed this book!\n");
    return 0;
       }
      //updating borrowbookid array  
	for(i = borrowIndex; i < *borrowedCount - 1; i++){
    borrowedBookIDs[i] = borrowedBookIDs[i+1];
          }
          //checking member type
   if(memberType == 1){
        if(days > 30){
        fine = (days - 30) * 10;
      }
    }
     else if(memberType == 2){
             if(days > 14){
        fine = (days - 14) * 20;
      }
    }
    char code[20];
    printf("Enter membership code:\n");
    scanf("%19s", code);

    if(strcmp(code, "LIB2026") == 0){
          fine = fine * 0.5;
       }
       *totalFine = *totalFine + fine;
	//updating 
	availableCopies[index]++;
	(*borrowedCount)--;
	return fine;
}
//function to display member record
void displayMemberRecord(char name[], int studentID, int memberType, int
                          borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver){
                	printf("Member Name: %s\n", name);
                    printf("Student ID: %d\n", studentID);
                    if(memberType==1)
                    	printf("Faculty \n");
					else 
					    printf("Student \n");
					
                printf("Currently Borrowed Books:\n");
                if(borrowedCount == 0){
                  printf("No books currently borrowed.\n");
                    }
                else{
                for(int i = 0; i < borrowedCount; i++){
                   printf("Book ID: %d\n", borrowedBookIDs[i]);
                     }
                  }
                  printf("Total fine charged before waiver : %.2f\n",totalFine);
                  printf("Final fine payable after waiver : %.2f\n",fineAfterWaiver);
}
//main function 
int main(){
   int bookIDs[]={101,102,103,104};
   char bookTitles[][50]={"Programming in C","Data Structures","Database System","Computer Networks"};
   int availableCopies[]={5,3,0,4};
   int totalBooks=4;
   int choice;
   char name[50];
   int studentID;
   int memberType;
   int borrowedBookIDs[3];
   int borrowedCount = 0;
   float totalFine = 0;
   float fineAfterWaiver = 0;

   do{
   	  displayMenu();
      scanf("%d",&choice);
   switch(choice){
   	case 1 :
   		registerMember(name,&studentID,&memberType);
   		break;
   	case 2 :
   		displayBooks(bookIDs,bookTitles,availableCopies,totalBooks);
   		break;
   	case 3 :
   		borrowBook(bookIDs,bookTitles,availableCopies,totalBooks,borrowedBookIDs,&borrowedCount,memberType);
        break;
    case 4 :
    	fineAfterWaiver += returnBook(bookIDs,availableCopies,totalBooks,borrowedBookIDs,&borrowedCount,memberType,&totalFine);
        break;
    case 5 :
    	displayMemberRecord(name,studentID,memberType,borrowedBookIDs,borrowedCount,totalFine,fineAfterWaiver);
        break;
    case 6 :
    	printf("Exiting !");
    	break;
    default :
        printf("Invalid Case !");	
   }
   }while(choice!=6);
return 0;
}
