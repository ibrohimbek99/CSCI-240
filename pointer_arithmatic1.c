#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, arr[]= {10,20};
    int *p;
    //Example 1
    p=arr;
    ++*p;
    printf ("arr[0]= %d, arr[1]= %d, *p= %d\n", arr[0], arr[1], *p);
    ////////////////////
    
    //Example 2
    p=arr;
    arr[0]=10;
    arr[1]=20;
    *p++;
    printf ("arr[0]= %d, arr[1]= %d, *p= %d\n", arr[0], arr[1], *p);
    
    
    //Example 3
    p=arr;
    *++p;
    printf ("arr[0]= %d, arr[1]= %d, *p= %d\n", arr[0], arr[1], *p);
    ////////////////////
    
    
    return 0;
}
