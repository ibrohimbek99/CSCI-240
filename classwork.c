#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int efficient_find_max(int r, int c, int a[][c]);
int inefficient_find_max(int r, int c, int a[][c]);
/* Find the max number of 1 in a 2D array/matrix*/  

void main()
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
                    };
    int r=10, c=10, i, result;
    
    result=efficient_find_max(r, c, a);
    printf ( "\nMax no of 1 is %d \n", result) ;

    //Code for finding average time to call the function enefficient_find_max 100 times
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (i = 0; i < 10000000; i++)
    {
        result = efficient_find_max(r, c, a);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time used for efficient %lf\n", cpu_time_used);
   
       result=inefficient_find_max(r, c, a);
    printf ( "\nMax no of 1 is %d \n", result) ;

    //Code for finding average time to call the function enefficient_find_max 100 times
   
    start = clock();
    for (i = 0; i < 10000000; i++)
    {
        result = inefficient_find_max(r, c, a);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time used for inefficient %lf\n", cpu_time_used);
    return;
}

//student
int efficient_find_max(int r, int c, int a[][c])
{ int i,j=0; /* initializing j here and not in the following loop, because I want it to stay the same number, and not be initialized to 0 again and again. */

for(i=0; i<r; i++){
    while ((a[i][j]==1)&&(j<c)){ /* while the cell is 1 and we are not exceeding the column limit, it will run column by column */
        j++;
    }
   
    
}
return j;
}

int inefficient_find_max(int r, int c, int a[][c])
{
    int i,j, row, col=0, max=0;
    for ( i=0; i<r; i++ )
    {
        for (j=0;j<c;j++)
        {
            if (a[i][j]==1)
                col=col+1;
        }
        if (col>max)
        {
            max=col;
            row=i;
        }
        col=0;
    }
    return max;
}

