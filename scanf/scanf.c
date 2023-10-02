#include <stdio.h>

int main()
{
    char name[50], location[50] ;
    printf("Enter your name:\n");
    scanf("%s", name);
    printf("Where are you from?\n");
    scanf("%s", location);

    printf("Welcome, %s from %s.\n", name, location);
    return 0;
}
