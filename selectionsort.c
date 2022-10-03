#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

void selectionSort(int A[], int n);
FILE * inp;
int Sum(int A[], int n);
void printArray(int A[], int n);

int main() 
{   int monsterNum; int ghost[SIZE]; int alien[SIZE]; int unsorted[SIZE];
    inp=fopen("inp.txt", "r");
    fscanf(inp, "%d", &monsterNum);
    int i,j = 0, m =0;
    for(i = 0; i < monsterNum; i++){
        fscanf(inp, "%d ", &unsorted[i]);
    }
    
    for (i = 0; i < monsterNum; i++) {
    if (unsorted[i] % 2 != 0) {
      ghost[j] = unsorted[i];
      j++;
    }
    else{
        alien[m] = unsorted[i];
        m++;
    }
  }
    selectionSort(ghost, j);
    selectionSort(alien, m);
    printArray(alien, m);
    printf("%d ", Sum(alien, m));
    printArray(ghost, j);
    printf("%d ", Sum(ghost, j));
    
    
    
    
    return 0;
}

void selectionSort(int A[], int n) 
{
    int i,j,temp;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++ ){
            if(A[i] > A[j]){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int Sum(int A[], int n)
{
    int i, sum=A[0];
    for(i=1; i< n; i++){
        sum += A[i];
    }
    return sum;
}

void printArray(int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}