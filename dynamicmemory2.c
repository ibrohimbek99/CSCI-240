#include <stdio.h>
#include <stdlib.h>

/* Allocate memory for an int. */

void main()
{
    int *ptr1 = (int*) malloc(10*sizeof (int));  //allocating 10 integer. So, ptr can be used as an array. You should cast as malloc return void type pointer
    int *ptr2;
    int i;
    if (ptr1 == NULL)
    {
      printf("Could not allocate memory\n");
      exit(-1);
    }
    else
    {
        printf("Memory allocated successfully. See the data: \n");
        for(i=0; i<10; i++)
        {
            printf("%d  ", ptr1[i]); //it will print garbage values
        }
    }

    ptr2 = (int*) calloc(10, sizeof (int));

    if (ptr2 == NULL)
    {
      printf("Could not allocate memory\n");
      exit(-1);
    }
    else
    {
        printf("Memory allocated successfully. See the data after calloc: \n");
        for(i=0; i<10; i++)
        {
            printf("%d  ", ptr2[i]); //it will print 0 for all elements
        }
    }
    free(ptr1);
    free(ptr2);
    return;
}
