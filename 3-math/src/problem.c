
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define DEFAULT_OPERATION "add"
#define DEFAULT_SCALAR 0
#define DEFAULT_FILE_A  "../data/a.dat"
#define DEFAULT_FILE_B   "../data/b.dat"

int PRINTV_SIGDIGITS = 2; /* DEFAULT*/

// Usage: ./mysolution [add|sub|mul|div] [fileA] [fileB] [scalar]
int main(int argc, char *argv[])
{
    char *op = argv[1];//DEFAULT_OPERATION;

    vector *a = v_read(argv[2]);//(DEFAULT_FILE_A); // TODO: Change to command line argument - fileA
    vector *b = v_read(argv[3]);//(DEFAULT_FILE_B); // TODO: Change to command line argument - fileB
    float c = atof(argv[4]);//atof(argv[4]); //DEFAULT_SCALAR;           // TODO: Change to command line argument - scalar
    /*Debugging
    printf("The value of argv[1] is %s\n",argv[1]);
    printf("The value of argv[2] is %s\n",argv[2]);
    printf("The value of argv[3] is %s\n",argv[3]);
    printf("The value of argv[4] is %s\n",argv[4]);
    printf("The value of c is %f\n",c);
    */

    // v_print(a); // Utility functions are implemented for you in this problem.

    // TODO: Change operation to command line argument
    // Change operation based on argument
    vector *result; // = v_add(a,b);
    //v_print(result);
    if (strcmp(op,"add") == 0)
    {
        result = v_add(a, b);
        v_print(result);
    }
    else if (strcmp(op,"mul")  == 0)
    {
         result = v_mul(a, c);
         v_print(result);
    }
    else if (strcmp(op,"sub")  == 0)
    {
        result = v_sub(a, b);
        v_print(result);
    }
    else if (strcmp(op,"div")  == 0)
    {
        result = v_div(a, c);
        v_print(result);
    }

    //v_print(result);

    // Cleanup
    v_destroy(a);
    v_destroy(b);
    // v_destroy(result);

    return 0;
}