// The header is shared between all problems in this assignment
// Find it here: /include/vector.h
#include <vector.h>

// Allocates memory for a vector array -- memory block should be instantiated to 0 (i.e., use calloc)
// The vector structure should use a special marker (VEC_END_FLAG) to signify
// the end of the vector in memory. Note, you should allocate n+1 units and set
// VEC_END_FLAG in the nth location. This is the same strategy used with char* arrays to indicate the end of a string ('\0').

// Usage:
// v_make(3) should produce a block of memory as follows:
// [0.0 0.0 0.0  VEC_END_FLAG]

vector *v_make(int n)
{
    vector* vector_make;
    vector_make = (float*) calloc(n, sizeof(float));
    if (vector_make == NULL)
    {
        fprintf(stderr,"Error! Memory not allocated\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < n; i++)
    {
        vector_make[n] = VEC_END_FLAG;
    }
    
    

    return vector_make;
}

/* Releases memory held by the vector v*/
void v_destroy(vector *v)
{
    free(v);
}

/* Error handling for null vector */
// Print "Attempting to manipulate NULL vector\n" to stderr
// Exit EXIT_FAILURE
void assertValidVec(vector *vec)
{
    if (vec == NULL)
    {
        fprintf(stderr,"Atttempting to manipulate NULL vector\n");
        exit(EXIT_FAILURE);
    }
}

// Determines the size of a vector by traversing the memory
// block associated with v until VEC_END_FLAG is found.
// VEC_END_FLAG marks the end of the vector.
int v_len(vector *v)
{
    int length_v = 0;
    int i = 0;
    while (v[i] != VEC_END_FLAG )
    {

        length_v++; // to obtain length of vector 
        i++;
    }
  
    return length_v;
}

// Prints a vector in the format
// [v1 v2 .. vn] n={length}\n
// PRINTV_SIGDIGITS indicates the number of significant digits you
// should render in your response.
// e.g. PRINTV_SIGDIGITS=2; length=3--> [1.00 1.00 1.00] n=3
// e.g. PRINTV_SIGDIGITS=1; length=3;--> [1.0 1.0 1.0] n=3

void v_print(vector *vec)
{
    int vec_len = v_len(vec); //  creating an integer variable and setting it equal to the length of vector
    //printf("Vec_len = %d\n",vec_len);
    printf("["); 
    int j = 0;
    //while (*vec != vec_len)
    while (j < vec_len)
    {
        if (j != vec_len && j != 0)
        {
            printf(" ");
        }

        switch (PRINTV_SIGDIGITS) // determining decimal places needed 
        {
            case 1:
            printf("%.1lf",vec[j]);
            break;
            case 2:
            printf("%.2lf",vec[j]);
            break;
            case 3:
            printf("%.3lf",vec[j]);
            break;
            case 4:
            printf("%.4lf",vec[j]);
            break;
            case 5:
            printf("%.5lf",vec[j]);
            break;
            case 6:
            printf("%.6lf",vec[j]);
            break;
            case 7:
            printf("%.7lf",vec[j]);
            break;
            case 8:
            printf("%.8lf",vec[j]);
            break;
            case 9:
            printf("%.9lf",vec[j]);
            break;
            case 10:
            printf("%.10lf",vec[j]);
            break;
        }


        j++;
    }
    printf("] "); 

  
    printf("n=%d\n",vec_len);
    
}

// Creates a vector of size n and fills it with scalar s.
vector *v_fill(int n, float s)
{
    vector *vec_fill = v_make(n);
    //vec_fill = (float*)malloc(n)//sizeof(float));
    if (vec_fill == NULL)
    {
        fprintf(stderr,"Error! Memory not allocated\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < n; i++)
    {
        vec_fill[i] = s;
        //vec_fill[n] = VEC_END_FLAG;
    }

    return vec_fill;
}

// Creates a vector of size n and fills it with ones.
vector *v_ones(int n)
{
    vector *vec_ones;
    vec_ones = v_make(n); //(float*)calloc(n,sizeof(float));
    for(int i = 0; i < n; i++)
    {
        vec_ones[i] = 1.0;
        //vec_ones[n] = VEC_END_FLAG;
    }

    return vec_ones;
}

