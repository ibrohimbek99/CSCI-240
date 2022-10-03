/*
Ibrahim Pulatov
Professor Haque
CSCI 240
Bubble sort algorythm to save the world
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void bubbleSort(int A[], int n);
void swap(int *a, int *b);
FILE * in;

int main() 
{   int vacNum; int VacVLC[SIZE]; int PatVLC[SIZE];
    in =fopen("in.txt", "r");
    fscanf(in, "%d", &vacNum);
    int i, flag;
    flag = 0;
    for(i = 0; i < vacNum; i++){
        fscanf(in, "%d ", &VacVLC[i]);
    }
    for(i = 0; i < vacNum; i++){
        fscanf(in, "%d ", &PatVLC[i]);
    }
    
    bubbleSort(VacVLC, vacNum);
    bubbleSort(PatVLC, vacNum);
    
    for(i = 0; i < vacNum; i++){
        if(VacVLC[i] < PatVLC[i]){
            flag++;
        }
    }
    if(flag >= 1){
        printf("NO");
    }
    else{
        printf("YES");
    }
    
    
    return 0;
}

void bubbleSort(int A[],int n)
{
    int i, j;
    for(i = 0; i < n; i++){
       
       for(j = 0; j < n-1; j++){
           if(A[j] > A[j+1]){
               swap(A+j, A+j+1);
           }
       }
        
    }
    
}

// Swaps the integers pointed to by a and b.
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}