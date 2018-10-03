#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    //Allows you to generate random number
    // Marsel: For what?
    srand((unsigned int) time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1); // Scanf for reading an int...

    //Create a new array of n1 ints
    int *a1 = malloc(sizeof(int) * n1);

    for (int i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = realloc(a1, sizeof(int) * n2);

    //If the new array is a larger size, set all new members to 0. Reason: don't want to use uninitialized variables.

    if (n1 < n2) {
        for (int *j = a1 + n1; j < a1 + n2; j++) {
            *j = 0;
        }
    }


    for (int i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}