#include <stdio.h>
#include <stdlib.h>

int main()
{
    char athleteF[50];
    char athleteL[50];
    char distance[50];
    char shoes[50];

    printf("Favorite Athlete: ");
    scanf("%s%s", athleteF, athleteL);
    printf("Distance: ");
    scanf("%s", distance);
    printf("Shoes: ");
    scanf("%s", shoes);

    printf("My favorite athlete is %s %s\n", athleteF, athleteL);
    printf("I want to run a %s\n", distance);
    printf("The shoes i wear currently is %s \n", shoes);

    return 0;
}
