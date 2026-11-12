#include <stdio.h>
int main(){
    int rows, cols;
    // 1. Input seating plan
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of seats per row: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0){
        printf("Invalid seating dimensions.");
        return 0;
    }//end if

    int seats[rows][cols];
    printf("Enter seating status (0 = Free, 1 = Booked):\n");
    for (int i = 0; i < rows; i++){
        printf("Row %d:\n", i);
        for (int j = 0; j < cols; j++){
            scanf("%d", &seats[i][j]);
            while (seats[i][j] != 0 && seats[i][j] != 1)
            {
                printf("Enter 0 or 1: ");
                scanf("%d", &seats[i][j]);
            }//end while
        }//end for(j)
    }//end for(i)
    // 2. Display seating arrangement
    printf("\nSeating Arrangement:\n");
    printf("   ");
    for (int j = 0; j < cols; j++)
        printf("%d ", j);
    printf("\n");
    for (int i = 0; i < rows; i++){
        printf("R%d ", i);
        for (int j = 0; j < cols; j++){
            if (seats[i][j] == 0)
                printf("_ ");
            else
                printf("X ");
        }//end for(j)
        printf("\n");
    }//end for(i)
    // 3. Seat availability report
    int totalFree = 0;
    printf("\nFree seats per row: ");
    for (int i = 0; i < rows; i++){
        int count = 0;
        for (int j = 0; j < cols; j++){
            if (seats[i][j] == 0)
                count++;
        }//end for(j)
        printf("%d ", count);
        totalFree += count;
    }//end for(i)
    printf("\nTotal free seats: %d\n", totalFree);

    // 4. Input group size
    int k;
    printf("\nEnter number of customers: ");
    scanf("%d", &k);

    while (k <= 0 || k > cols){
        printf("Invalid group size. Enter again: ");
        scanf("%d", &k);
    }//end while
    // 5. Search for consecutive seats
    int mid = rows / 2;
    int found = 0;
    int allocatedRow = -1;
    int startSeat = -1;
    for (int d = 0; d < rows && found == 0; d++){
        // Search lower row number first
        for (int side = 0; side < 2 && found == 0; side++){
            int r;
            if (side == 0)
                r = mid - d;
            else
                r = mid + d;
            // Skip invalid rows and duplicate middle row
            if (r < 0 || r >= rows || (d == 0 && side == 1))
                continue;
            int consecutive = 0;
            for (int j = 0; j < cols; j++){
                if (seats[r][j] == 0){
                    consecutive++;
                    if (consecutive == k){
                        allocatedRow = r;
                        startSeat = j - k + 1;
                        found = 1;
                        break;
                    }//end if for consecutive
                }//end if for seats
                else{
                    consecutive = 0;
                }//end else
            }//end for(j)
        }//end for(side)
    }//end for(d)

    // 6. Confirm booking
    if (found == 1){
        printf("\nGroup of %d seated in Row %d, seats %d to %d\n",
               k, allocatedRow, startSeat, startSeat + k - 1);
        // Update seats only after finding a suitable block
        for (int j = startSeat; j < startSeat + k; j++){
            seats[allocatedRow][j] = 1;
        }
        // Display updated seating arrangement
        printf("\nUpdated Seating Arrangement:\n");
        printf("   ");
        for (int j = 0; j < cols; j++)
            printf("%d ", j);

        printf("\n");

        for (int i = 0; i < rows; i++){
            printf("R%d ", i);
            for (int j = 0; j < cols; j++){
                if (seats[i][j] == 0)
                    printf("_ ");
                else
                    printf("X ");
            }
            printf("\n");
        }
        // Calculate remaining free seats
        totalFree = 0;
        printf("\nRemaining free seats per row: ");
        for (int i = 0; i < rows; i++){
            int count = 0;
            for (int j = 0; j < cols; j++){
                if (seats[i][j] == 0)
                    count++;
            }
            printf("%d ", count);
            totalFree += count;
        }
        printf("\nTotal remaining free seats: %d\n", totalFree);
    }
    else{
        printf("\nSorry! No consecutive seats available for this group.\n");
        printf("Seating plan remains unchanged.\n");
    }
    return 0;
}

