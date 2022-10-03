/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

main( )
{
    int s[4][2] = {
                    { 5, 6 },
                    { 8, 23 },
                    { 22, 9 },
                    { 90, 4 }
                } ;
    int i, j ;
    for ( i = 0 ; i <= 3 ; i++ )
    {
        printf ( "\n" ) ;
        for ( j = 0 ; j <= 1 ; j++ )
            printf ( "%d ", *( *( s + i ) + j ) ) ;
    }
}
/* Output:
5 6 
8 23 
22 9 
90 4 
*/

