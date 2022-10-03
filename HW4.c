/*
Ibrokhimbek Pulatov
CSCI-240
Addition of Polynominals
10/1/2021
*/



#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct link
{
    int coef;
    int expo;
    struct link *next;
};
typedef struct link node;
//this has been taken as a global variable since multiple functions will read from file
FILE * in;


//Take two inputs from the file (coef and expo) and create the node
node * getnode()
{
    node *newnode;
    newnode = (node *) malloc( sizeof(node)) ;
    
    
    fscanf(in, "%d", &(newnode -> coef));
    fscanf(in, "%d", &(newnode -> expo));
    
    
    newnode -> next = NULL;
    return newnode;
}

node * create_poly (node *p )
{
    int ch, i;
    node *temp,*newnode;
    //read from file to know the number of nodes to added in this polynomial
    fscanf(in, "%d", &ch);

    //Then run a loop that many times and inside call the getnode function and  
    //add the node at the end of the current link list
    for(i = 0; i < ch; i++){
        
        if(p == NULL)
        {
            temp = getnode();
            p = temp;
        }
        else
        {
            temp->next = getnode();
            temp = temp->next;
        }
    }
    
    return p;
}

//Display the values (coef and expo) in the nodes of the link list pointed by p 
void display (node *p)
{
    node *newnode = p;
    if(newnode -> next != NULL){
        printf("%dX^%d-->", newnode -> coef, newnode -> expo);
        newnode = newnode -> next;
        display(newnode);
    }

    else 
    printf("%dX^%d-->END\n\n", newnode -> coef, newnode -> expo);

    
}

// Add the content of p1 and p2 (polynomial addition) and print the result
void add_poly(node *p1, node *p2)
{
    //node *newnode;
    node *newnode = (node*)malloc(sizeof(node)), *p = newnode;
    
    while(1)
    {
        if( p1 == NULL || p2 == NULL ){
            break;
        }
        else{
            if (p1 -> expo == p2 -> expo){
                newnode -> coef = p1 -> coef + p2 -> coef;
                newnode -> expo = p1 -> expo;
                 
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
            else if(p1 -> expo < p2 -> expo){
                newnode -> expo = p2 -> expo;
                newnode -> coef = p2 -> coef;
              
                p2 = p2 -> next;
            }
            else if (p1 -> expo > p2 -> expo){
                newnode -> expo = p1 -> expo;
                newnode -> coef = p1 -> coef;
               
                p1 = p1 -> next;
            
        }
        
        }
        newnode->next = (node*)malloc(sizeof(node));
        newnode = newnode->next;
        // newnode->next = NULL;
    }
    if(p1 != NULL){
        newnode->next = p1;
    }
    if(p2 != NULL){
        newnode->next = p2;
    }
    
    display(p);
    //print the rest of elements of the other link list (which has still more nodes)
    return;
}

void main()
{
    in =fopen("in.txt", "r");
    node *poly1 = NULL ,*poly2 = NULL;
    
    poly1 = create_poly (poly1);
    poly2 = create_poly (poly2);
    
    printf("\nDisplaying Polynomial 1: ");
    display (poly1);
    printf("\nDisplaying Polynomial 2: ");
    display (poly2);
    printf("\nResultant Polynomial : ");
    add_poly(poly1, poly2);
    return;
}

//If we assume that poly 1 has r elements and poly 2 has c elements, the Big O for the function would be O(r+c)