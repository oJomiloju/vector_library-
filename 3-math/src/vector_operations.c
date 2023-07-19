#include "vector.h"

// Verifies that vector a and b have equivalent lengths.
// Outputs an informative error message to std error with the following format
// "Attempting to add vectors of unequal length: {alength} - {blength}"
// If not equal, this function will exit out of program with EXIT_FAILURE CODE
void assertValidOperation(vector *a, vector *b)
{
    int len_a = v_len(a);
    int len_b = v_len(b);
    if (len_a != len_b)
    {
        fprintf(stderr,"Attempting to add vectors of unequal length: {%d} - {%d}\n",len_a,len_b);
        exit(EXIT_FAILURE);
    }
}

// Pairwise add of vectors a and b
// Verifies that addition is legal -- i.e., lengths of a and b are equal
// Result is in a new vector
vector *v_add(vector *a, vector *b)
{
    assertValidOperation(a,b);
    int n = v_len(a);
    vector *vec_sum = v_make(n); // using length of a because to add these vectors they need to be the same size 

    for (int i = 0; i < n; i++)
    {
        vec_sum[i] = a[i]+b[i];
    }
    
    
    return vec_sum;
}

// Pairwise subtraction of vectors a and b
// Verifies that subtraction is legal -- i.e., lengths of a and b are equal
// Result is in a new vector
vector *v_sub(vector *a, vector *b)
{
    assertValidOperation(a,b);
    vector *vec_subt = v_make(v_len(a)); // using length of a because to add these vectors they need to be the same size 

    for (int i = 0; i < v_len(a); i++)
    {
        vec_subt[i] = a[i]-b[i];
    }
    
    
    return vec_subt;
}

// Multiplies every member of vector a with c
// Result is in a new vector
vector *v_mul(vector *a, float c)
{
    int v_length = v_len(a); // finding the length of a 

    vector *v_scalar_mult = v_make(v_length); // result should still be the same size as vector a as the size does not change 
    for (int i = 0; i < v_length; i++)
    {
        v_scalar_mult[i] = c*a[i];
    }



    return v_scalar_mult;
}

// Multiplies every member of vector a with c
// Result is in a new vector
vector *v_div(vector *a, float c)
{
    int v_length = v_len(a); // finding the length of a 

    vector *v_scalar_div = v_make(v_length); // result should still be the same size as vector a as the size does not change
    if (c == 0)
    {
        fprintf(stderr,"Scalar division: Attempting to divide by zero\n");
        exit(EXIT_FAILURE);
    } 
    else
    {
        for (int i = 0; i < v_length; i++)
        {
            v_scalar_div[i] = a[i]/c;
        }
    }



    return v_scalar_div;
}
