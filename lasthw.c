#include <stdio.h>
#include <pthread.h>

// size of array
#define MAX 16

// maximum number of threads
#define MAX_THREAD 4

int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int sum[4] = { 0 };
int part = 0;

void* sum_array(void* arg)
{

	// Create a thread_part variable, that can keep part number for each thread
	int thread_part = part++;

   // TODO
   // Implement a loop to calculate sum portion for each thread
	int i;
	for ( i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++)
	{
        	sum[thread_part]= sum[thread_part]+ a[i]; // sum[thread_part] will store the summation for each thread
	}
   

}

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];
	int i;
	int summy = 0;
	// Creating 4 threads
	//TODO
	for (i = 0; i < MAX_THREAD; i++)
	{
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
	}
	// joining 4 threads i.e. waiting for all 4 threads to complete
	//TODO
	for (i = 0; i < MAX_THREAD; i++)
	{
        pthread_join(threads[i], NULL);
	}

	// adding sum of all 4 parts
	int total_sum = 0;
	//TODO
	//Create a loop to sum all thread summation
	for (i = 0; i < MAX_THREAD; i++)
	{
        total_sum = total_sum+ sum[i];
	}
	printf("The sum using the new algorithm: %d \n", total_sum);
	
	for (i = 0; i < MAX; i++)
	{
        summy = summy+ a[i];
	}
	printf("The sum using the simple algorithm: %d \n", summy);

	return 0;
}