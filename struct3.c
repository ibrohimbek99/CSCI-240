#include <stdio.h>
#include <stdlib.h>
struct employee{
    char name[20];
    float salary;
    int id;
};
void main ()
{
    struct employee a={"Sunny", 1000.00, 1234};
    struct employee * temp;
    temp=&a;
    printf("%s  %f  %d\n", a.name, a.salary, a.id);
    printf("%s  %f  %d\n", temp->name, temp->salary, temp->id);
    return;
}