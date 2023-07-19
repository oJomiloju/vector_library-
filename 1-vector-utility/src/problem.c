
/**
 * PROJ01: PROBLEM 1
 * Spring 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define DEFAULT_SIZE 3
#define DEFAULT_FILL 6
#define DEFAULT_SIGS 2

int PRINTV_SIGDIGITS =  DEFAULT_SIGS; /* DEFAULT*/

// Usage: ./mysolution [size of vector] [fill-scalar] [print-sig-digits]
int main(int argc, char *argv[])
{
    // TODO: Adjust PRINTV_SIGDIGITS based off of command line arguments
    float value = atof(argv[3]);
     PRINTV_SIGDIGITS = value;
     //printf("print_sigdigits is %s\n",argv[3]);
    //int size_vec = atof(argv[1]);
    //int fill_scalar = atof(argv[1]);
    //printf("fill scalar is equal to %d\n",fill_scalar);
    //int print_sig_digits = atoi(argv[3]);

    // Creates a vector filled with 1s with dimension 10
    // TODO -- update dimension i.e., length of array, to be supplied from the command line
    vector *test_vector = v_ones(atof(argv[1]));//(DEFAULT_SIZE);
    v_print(test_vector);
    v_destroy(test_vector);

    // Creates a vector filled with 5s with dimension 10
    // TODO -- update dimension i.e., length of array, to be supplied from the command line
    // TODO -- update scalar to be supplied from the command line
    test_vector = v_fill(atof(argv[1]),atof(argv[2]));  //(DEFAULT_SIZE, DEFAULT_FILL);
    v_print(test_vector);
    v_destroy(test_vector);



    return 0;
}
