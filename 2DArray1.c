#include <stdio.h>
#include <stdlib.h>

/* Demo: 2-D array is an array of arrays */
void main( )
{
    int s[4][2] = {
                    { 5, 6 },
                    { 8, 23 },
                    { 22, 9 },
                    { 90, 4 }
                } ;
    int i ;
    for ( i = 0 ; i <= 3 ; i++ )
    {
        printf ( "\nAddress of %d th 1-D array = %u", i, s[i] ) ;
        printf ( "\nAddress of %d th 1-D array = %u", i, *(s+i) ) ;
    }
    return;
}