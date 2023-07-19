
/**
 * PROJ01: PROBLEM 4
 * Spring 2023
 * Utility functions are implemented for you in this problem.
 * I/O function have been implemented for you in this problem.
 * Math functions have been implemented for you in this problem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define DEFAULT_OPERATION "unit"

#define DEFAULT_FILE_A "../data/a.dat"
#define DEFAULT_FILE_B "../data/b.dat"

int PRINTV_SIGDIGITS = 2; /* DEFAULT*/

// Usage: ./mysolution [dot|mag|cosine|project|unit|sum] [fileA] [fileB]
int main(int argc, char *argv[])
{
    char *op = DEFAULT_OPERATION;

    vector *a = v_read(DEFAULT_FILE_A); // TODO: Change to command line argument - fileA
    vector *b = v_read(DEFAULT_FILE_B); // TODO: Change to command line argument - fileB

    // TODO: Change operation to command line argument
    // Change operation based on argument
    vector *v_result_a = v_unit(a);
    vector *v_result_b = v_unit(b);
    v_print(v_result_a); // FOR VECTOR RESULTS,
    v_print(v_result_b); // FOR VECTOR RESULTS,

    // float s_result_a = v_mag(a);
    // float s_result_b = v_mag(b);
    // printf("%2.2f\n", s_result_a); // FOR SCALARS RESULTS
    // printf("%2.2f\n", s_result_b); // FOR SCALARS RESULTS

    // Cleanup
    v_destroy(a);
    v_destroy(b);
    v_destroy(v_result_a);
    v_destroy(v_result_b);

    return 0;
}
