#include "vector.h"

/* Reads vector from file in the .dat format */
vector *v_read(char *filename)
{

    FILE *infile;
    char c;
    int veclen = 0;
    int i = 0;
    infile = fopen(filename,"r");

    if (infile == NULL)
    {
        fprintf(stderr,"File does not exist: {%s}\n",filename);
        exit(EXIT_FAILURE);
    }
    while (c != EOF)
    {
        c = fgetc(infile);
        if (c == '\n')
        {
            veclen+= 1; // successfully counts the number of lines in the file 
        }
    }

    vector *read_vec;
    read_vec = v_make(veclen);
    fseek(infile,0,SEEK_SET); // going back to the beginning of the file 
    while(!feof(infile))
    {
        fscanf(infile,"%f",&read_vec[i]);
        i++;
    }


    fclose(infile);
    return read_vec;
    

}

/* Writes vector to file in the .dat format */
void v_write(char *filename, vector *v)
{
    //int max = v_len(v);
    //v = v_make(5);
    FILE *outfile = fopen(filename,"w");
    if (outfile == NULL)
    {
        fprintf(stderr,"File does not exist: {%s}\n",filename);
        exit(EXIT_FAILURE);
    }
    
        for(int i = 0; i < v_len(v); i++)
        {
            fprintf(outfile,"%f\n",v[i]);
        }
    
     fclose(outfile);




}
