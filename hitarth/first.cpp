#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000 // Define the size of the array

// Bubble Sort
void bubbleSort(int arr[], int n) {
   clock_t start, end;
   double cpu_time_used;
   
   start = clock();
   
   for(int i = 0; i < n-1; i++) {     
       for (int j = 0; j < n-i-1; j++) { 
           if (arr[j] > arr[j+1]) {
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
       }
   }
   
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("Bubble Sort took %f seconds to execute \n", cpu_time_used);
}

// Selection Sort
void selectionSort(int arr[], int n) {
   clock_t start, end;
   double cpu_time_used;
   
   start = clock();
   
   for(int i = 0; i < n; i++) {
      int min = i;
      for(int j = i+1; j < n; j++)
         if(arr[j] < arr[min])
            min = j;
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
   }
   
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("Selection Sort took %f seconds to execute \n", cpu_time_used);
}

int main() {
   int arr[SIZE];

   // Generate random numbers
   srand(time(0));
   for(int i = 0; i < SIZE; i++) {
      arr[i] = rand() % SIZE;
   }
   
   // Perform sorting
   bubbleSort(arr, SIZE);
   selectionSort(arr, SIZE);
   
   return 0;
}