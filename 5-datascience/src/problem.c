
/**
 * PROJ01: PROBLEM 5
 * Spring 2023
 * Utility functions are implemented for you in this problem.
 * I/O function have been implemented for you in this problem.
 * Math functions have been implemented for you in this problem.
 * Vector functions have been implemented for you in this problem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define DEFAULT_OPERATION "unit"

#define DEFAULT_FILE_A "../data/a.dat"

int PRINTV_SIGDIGITS = 2; /* DEFAULT*/

// Usage: ./mysolution [mean|range|std|clamp|minmaxscale|standardize] [fileA]
int main(int argc, char *argv[])
{
    char *op = argv[1];//DEFAULT_OPERATION;


    vector *a = v_read(argv[2]);//(DEFAULT_FILE_A); // TODO: Change to command line argument - fileA
    // TODO: Change operation to command line argument
    // Change operation based on argument
    vector *v_result = v_read(argv[2]); //= v_minmaxscale(a);

    if (strcmp(op,"mean") == 0)
    {
        float mean;
        mean = v_mean(a);//(v_result);
        printf("%.2f\n",mean);
    }
    else if (strcmp(op,"range") == 0)
    {
        float range;
        range = v_range(a);
        printf("%.2f\n",range);
    }
    else if (strcmp(op,"std") == 0)
    {
        float SD;
        SD = v_std(a);
        printf("%.2f\n",SD);
        //printf("%.2f\n",v_std(a));
    }
    else if (strcmp(op,"clamp") == 0)
    {
        //v_result = v_clamp(a, 0, 1);
        //v_print(v_result);
        v_clamp(a, 0, 1);
        v_print(a);

    }
    else if (strcmp(op,"minmaxscale") == 0)
    {
        //v_result = v_minmaxscale(a);
        //v_print(v_result);
        v_minmaxscale(a);
        v_print(a);
    }
    else if (strcmp(op,"standardize") == 0)
    {
        //v_result = v_standardize(a);
        //v_print(v_result);
        v_standardize(a);
        v_print(a);
    }








    
    //v_print(v_result); // FOR VECTOR RESULTS,

    // float s_result = v_mean(a);
    // printf("%2.2f\n", s_result); // FOR SCALARS RESULTS

    // Cleanup
    v_destroy(a);
    v_destroy(v_result);

    return 0;
}
