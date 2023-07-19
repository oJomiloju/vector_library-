
#include "vector.h"
float v_mag(vector *vec)
{
    int n = v_len(vec);
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        float f = vec[i];
        sum += f * f;
    }
    return sqrt(sum);
}
float v_dot(vector *a, vector *b)
{
    int n1 = v_len(a);
    int n2 = v_len(b);

    if (n1 != n2)
    {
        fprintf(stderr, "Attempting to add vectors of unequal length: %d - %d", n1, n2);
        exit(EXIT_FAILURE);
    }

    int n = n1;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
}
float v_project(vector *a, vector *b)
{
    vector *bnorm = v_unit(b);
    float dp = v_dot(a, bnorm);
    return dp;
}

vector *v_unit(vector *vec)
{
    int n = v_len(vec);
    float mag = v_mag(vec);
    vector *c = v_make(n);
    c = v_div(vec, mag);
    return c;
}
float v_cosine(vector *a, vector *b)
{
    float dp = v_dot(a, b);
    float a_mag = v_mag(a);
    float b_mag = v_mag(b);
    return dp / (a_mag * b_mag);
}
float v_sum(vector *vec)
{
    float sum = 0;
    int n = v_len(vec);
    for (int i = 0; i < n; i++)
    {
        float f = vec[i];
        sum += f;
    }
    return sum;
}
