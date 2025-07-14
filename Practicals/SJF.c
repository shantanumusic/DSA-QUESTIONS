// Code for cpu scheduling from ARRIVAL time , Burst Time , CT , TAT , WT
#include<stdio.h>
#include<conio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
       if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
void main(){
    int size = 5;
    int processId[5] = {1,2,3,4,5};
    int arrivalTime [5] = {0,2,4,6,8};
    int burstTime [5] = {3,6,4,5,2};
    int completionTime [size];
    int turnAroundTime [size];
    int waitingTime [size];

    // SORT OF BT
   selectionSort(burstTime, 5);
    

    // Calculation of Completion Time
    int sum = 0;
    for (int i = 0; i < size; i++)

    {
        sum = sum + burstTime[i];
        completionTime[i] = sum;
        //printf("\n Completion Time is \n");
        // printf("\n%d\n" , completionTime[i]);
    }

    // Calculation of Turnaround Time
    int TAT = 0;
    for (int i = 0; i < size; i++)
    {
      TAT = completionTime[i] - arrivalTime[i];
      turnAroundTime[i] = TAT;
      // printf("\n Turnaorund Time is \n");
    //   printf("\n%d\n" , turnAroundTime[i]);

    }
    // Calculation of Waiting  Time
    int WT = 0;
    for (int i = 0; i < size; i++)
    {
      WT = turnAroundTime[i] - burstTime[i];
      waitingTime[i] = WT;
      // printf("\n Waiting Time is \n");
    //   printf("\n%d\n" , waitingTime[i]);

    }

    // Chart Printing
    printf("Pid\tAT\tBT\tCT\tTAT\tWT\t\n");

   for (int i = 0; i < 5; i++)
   {
      printf("%d\t%d\t%d\t%d\t%d\t%d\t", processId[i], arrivalTime[i],burstTime[i],completionTime[i],turnAroundTime[i],waitingTime[i]);
      printf("\n");
   }
   
    
    
    





}