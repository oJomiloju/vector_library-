
#include "vector.h"

float v_mean(vector *vec)
{
    float vec_count = v_len(vec);
    float vec_sum = 0;
    float vec_average;
    for (int i = 0; i< vec_count; i++)
    {
        vec_sum = vec_sum + vec[i];
    }

    vec_average = (vec_sum/vec_count); // adding all the numbers together and dividing by the amount of numbers in vector 

    
    return vec_average;
}

float v_range(vector *vec)
{
    float max = vec[0];  // to find the maximum number 
    float min = vec[0]; // to find the minimum number 
    int v_length = v_len(vec);
    for (int i = 0; i<= v_length; i++)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }
        if (vec[i] > max)
        {
            max = vec[i];
        }
    }


    float range = max - min;


    return range;
}

float v_std(vector *vec)
{
    int length = v_len(vec);
    //float sum = v_sum(vec); not needed since we already had a function calculate the mean 
    float mean = v_mean(vec);
    float SD; // for standard deviation. this will be the value returned in the function 
    for (int i = 0; i< length; i++ )
    {
        SD+= pow(vec[i]-mean,2);
    }
    
    SD = sqrt(SD/length); //if we dont find the square root it will be the variance calculated but we need the standard dv

    return SD;
}

vector *v_clamp(vector *a, float minV, float maxV)
{
    int length = v_len(a);
    minV = (-3 * v_std(a));
    maxV = (3 * v_std(a));

    for (int j = 0; j < length; j++)
    {
        if (a[j] > maxV)
        {
            a[j] = maxV;
        }
        if (a[j] < minV)
        {
            a[j] = minV;
        }
    }
    return a;
}

vector *v_minmaxscale(vector *a)
{
    //This is asking you to scale the numbers.
    //  The largest number becomes 1, the smallest
    // number becomes 0, and every other number is in between 0 and 1. 
    //The math equation provided will help you with calculating this.
    // to find the maximum number 
    float max = 1;//a[0];
    float min = 0;//a[0]; // to find the minimum number 
    int length = v_len(a);
    for (int i = 0; i< length; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    //v_clamp(a,min,max);






    return a;
}

vector *v_standardize(vector *a)
{
    int length = v_len(a);
    float meanV = v_mean(a);
    float std = v_std(a);
    

    for (int i = 0; i< length; i++)
    {
        a[i] = (a[i] - meanV)/std;
    }
    
    return a;
}
