/* CSCI-240
   Ibrokhimbek Pulatov
   Recursive Binary Search
   9/21/2022
   */

// EXPLANATION FOR BIG O GIVEN BELOW
#include <stdio.h>
#include <stdlib.h>

int RbinarySearch(int target, int A[], int left, int right);
int Power(int base, int power);
int crazySum(int n);


// A recursive binary search function. It returns 
// location of target in given array A[left..right] is present, 
// otherwise -1 
int RbinarySearch(int target, int A[], int left, int right) {
   
    //base case
    if(left > right){
        return -1;
    }
    // There is no search space so target isn't found.
    
    
    // Calculate the middle of the search space.
    int center;
    if(right>=1){
    center = (left+(right-1)/2);
    // If the element is present at the middle itself
    if (target== A[center])
        return center;
    
    // If target is smaller than mid, then it can only be present in left half of the search space
    else if (target< A[center])
        return RbinarySearch(target, A, left, (center-1));

    // Else, target can only be present in the right half of the search space 
   else if (target>A[center])
        return RbinarySearch(target,A, (center+1), right);
    }//else
    return -1;
}

int Power(int base, int power){
    if (power == 0) // base case
        return 0;
   else  if (power == 1) // base case
        return base;
    else
    return base * Power(base, (power-1)); //recursion
}

int crazySum(int n){
    if (n==0) // base case
    return 0;
   else if(n==1) //base case
    return 1;
    else
    return Power(n,n) + crazySum(n-1); //recursion
   
}

int main(void) 
{ 
    int arr[20]; 
    int numberofelements, target, result, n_crazy_sum;
    
    FILE *in = fopen("input.txt","r");

    if(in != NULL)
    {
        //getting the number of elements from the file
        fscanf(in, "%d", &numberofelements);
        
        //getting all the elements from the file and storing them in the array
        for(int i = 0; i < numberofelements; i++)
        {
            fscanf(in, "%d", &arr[i]);
        }
        
        //getting the target number from the file
        fscanf(in, "%d", &target);
        
        result = RbinarySearch(target, arr, 0, numberofelements - 1); 
        if(result == -1)
        {
            printf("Element is not present in array\n"); 
        }
        else
        {
            printf("Element is present at index %d\n", result);
        } 
    }
    
    
    fscanf(in, "%d", &n_crazy_sum); // takes input for crazysum from file
    printf("Result of crazy sum: %d\n", crazySum(n_crazy_sum));
    
    return 0; 
}
/* 3) Big O for the function would be O(logn) because I cut the array by half and keep cutting it by half, until the base case is not reached. */