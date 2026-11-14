#include<stdio.h>
//funtion to input all the sensor readings hourly
void input(int n ,int n_readings,int temp[n][n_readings]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n_readings;j++){
			printf("Enter reading for sensor %d, hour %d: ", i+1, j+1);
			scanf("%d",&temp[i][j]);
		}
	}
}//end input function

// sensor analysis function
void sensor_analysis(int n ,int n_readings,int temp[n][n_readings]){
	int i,j,sum_t,critical_readings,warning_readings;
	float avg_t;
	for(i=0;i<n;i++){
		sum_t=0;
		avg_t=0;
		int highest = temp[i][0];
        int lowest = temp[i][0];
        critical_readings=0;
		warning_readings=0;
		int current_streak=0;
		int longest_streak=0;
		for(j=0;j<n_readings;j++){
			sum_t=sum_t+temp[i][j];
			//calculating highet temp
			if(temp[i][j] > highest){
               highest = temp[i][j];
              } 
            //calculating lowest temp
            if(temp[i][j] < lowest){
                 lowest = temp[i][j]; 
              }
            //calculating number of critical readings
            if(temp[i][j]>=40){
            	critical_readings++;
			}
			//calculating number of warning readings
			if(temp[i][j]>=35&&temp[i][j]<=39){
				warning_readings++;
			}
			//calculating longest streak 
			if(temp[i][j] >= 35){
                 current_streak++;
            if(current_streak > longest_streak){
                   longest_streak = current_streak;
                  }
                   }
            else{
                   current_streak = 0;
                } 
		}
		avg_t=(float)sum_t/n_readings;
		//Report for sensors
		printf("Sensor %d: Total=%d  Avg=%.2f  Max=%d  Min=%d\n",i+1, sum_t, avg_t, highest, lowest);
        printf("            Critical=%d  Warning=%d  Longest hot streak=%d\n",critical_readings, warning_readings, longest_streak);
        printf("\n");
	}
}
// Sensor number with highest temp average
int Highest_average(int n, int n_readings, int temp[n][n_readings],float *highest_avg){
    int i, j, sum;
    float avg;
    int highest_sensor;

    *highest_avg = -999999;
    highest_sensor = 1;

    for(i = 0; i < n; i++){
        sum = 0;
        for(j = 0; j < n_readings; j++){
             // Calculate sum
             sum=sum+temp[i][j];
        }
        // Calculate average
        avg=(float)sum/n_readings;
        // Compare average with highest_avg
         if(avg>*highest_avg){
         	*highest_avg=avg;
         	highest_sensor=i+1;
		 }
    }
    return highest_sensor;
}

int main(){
	int n , n_readings,result;
	float highest_average;
	printf("enter number of sensors :\n");
	scanf("%d",&n);
	printf("enter number of hourly readings :\n");
	scanf("%d",&n_readings);
	int temp[n][n_readings];
	input(n,n_readings,temp);
	sensor_analysis(n,n_readings,temp);
	result=Highest_average(n,n_readings,temp,&highest_average);
	printf("Highest average : Sensor %d (%.2f)",result,highest_average);
	return 0;
}
