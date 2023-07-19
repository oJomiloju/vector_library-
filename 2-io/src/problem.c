/**
 * PROJ01: PROBLEM 2
 * Spring 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int PRINTV_SIGDIGITS = 2; /* DEFAULT*/

// Usage: ./mysolution [source] [destination]
int main(int argc, char *argv[])
{
    //printf("argv[1] = %s\n",argv[1]);
    //printf("argv[2] = %s\n",argv[2]);
    vector *test_vector = v_read(argv[1]);//("../data/hello.dat"); // TODO: Change to command line argument
    v_print(test_vector);
    secret_fn(test_vector);                     // Modifies test_vector in place - do not remove
    v_write(argv[2],test_vector);//("../data/result.dat", test_vector); // TODO: Change to command line argument
    //v_print(test_vector);

    //v_print(test_vector);
    v_destroy(test_vector);

    return 0;
}