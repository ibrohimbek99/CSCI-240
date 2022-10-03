#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int inefficient_find_max(int r, int c, int a[][c]);
/* Find the max number of 1 in a 2D array/matrix*/

void main( )
{
    int a[10][10] = {
                        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                    } ;
    
    int r=10, c=10, i, result;
    
    result=inefficient_find_max(r, c, a);
    printf ( "\nMax no of 1 is %d \n", result) ;
    
    //Code for finding average time to call the function enefficient_find_max 100 times
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (i = 0; i < 10000000; i++)
    {
        result = inefficient_find_max(r, c, a);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time used %lf\n", cpu_time_used);
   
    return;
}

//student
int inefficient_find_max(int r, int c, int a[][c])
{
    int i, j, row, col = 0, max = 0;
    //write code here
    
    return max;
}