#include <stdio.h>
// 1. Function to input and validate festival days
int getValidDays(){
    int n;
    printf("Enter number of festival days (1-7): ");
    scanf("%d", &n);
    while(n < 1 || n > 7){
        printf("Invalid! Enter days between 1 and 7: ");
        scanf("%d", &n);
    }
    return n;
}
// 2. Function to calculate daily sales
float calculateDailySales(int dayNumber){
    int orders, i;
    float amount, total = 0, average, highest = 0;
    printf("\n--- Day %d ---\n", dayNumber);
    printf("Enter number of orders: ");
    scanf("%d", &orders);

    for(i = 1; i <= orders; i++){
       printf("Enter amount for order %d: ", i);
        scanf("%f", &amount);

        while(amount <= 0){
            printf("Invalid amount! Enter again: ");
            scanf("%f", &amount);
        }
        total = total + amount;

        if(i == 1 || amount > highest){
            highest = amount;
        }
    }
	average = total / orders;
    printf("Total sales: Rs. %.2f\n", total);
    printf("Average order amount: Rs. %.2f\n", average);
    printf("Highest order amount: Rs. %.2f\n", highest);

    return total;
}
// 3. Function to find the day with highest sales
int findHighestSalesDay(float dailySales[], int numberOfDays){
    int i, highestDay = 1;
    float highestSales = dailySales[0];

    for(i = 1; i < numberOfDays; i++){
        if(dailySales[i] > highestSales)
        {
            highestSales = dailySales[i];
            highestDay = i + 1;
        }
    }
    return highestDay;
}
// 4. Function to display sales bar chart
void displayBarChart(float dailySales[], int numberOfDays){
    int i, j;
    printf("\n--- DAILY SALES BAR CHART ---\n");
    for(i = 0; i < numberOfDays; i++){
        printf("Day %d: ", i + 1);
        for(j = 1; j <= dailySales[i] / 100; j++){
            printf("*");
        }
        
        printf("\n");
    }
}

int main(){
    int n, i, highestDay;
    float dailySales[7], festivalTotal = 0;

    // Get number of festival days
    n = getValidDays();

    // Process each festival day
    for(i = 1; i <= n; i++){
        dailySales[i - 1] = calculateDailySales(i);

        festivalTotal = festivalTotal + dailySales[i - 1];
    }

    // Display festival summary
    printf("\n===== FESTIVAL SALES SUMMARY =====\n");

    printf("Total festival sales: Rs. %.2f\n", festivalTotal);

    highestDay = findHighestSalesDay(dailySales, n);

    printf("Day with highest sales: Day %d\n", highestDay);

    // Display bar chart
    displayBarChart(dailySales, n);

    return 0;
}

