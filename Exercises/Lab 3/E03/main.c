#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_CHARACTERS 25
#define INPUT_FILE_NAME "numbers.txt"

#define BUFFER_SIZE 100  //1kB static buffer...

void main (void)
{

    FILE *origin_file=0;
    char c;
    signed short int buffer[BUFFER_SIZE];
    char numbuffer[5];
    int counter, discarded_numbers;

    origin_file = fopen(INPUT_FILE_NAME, "r");

    int i=0;
    clearBuffer(numbuffer);
    counter=0;
    while ((c = getc(origin_file)) != EOF)       //Iterate the whole file.
    {
        if((c >= '0' && c<='9') || c=='-')
        {
            char x[2]={0,0};
            x[0] = c;  //Convert ascii to int value.
            strcat(numbuffer,x);
        }
        else
        {
            buffer[counter]=atoi(numbuffer);
            printf("\nnumber: %d",buffer[counter]);
            counter++;
            clearBuffer(numbuffer);
        }
    }
    //buffer[counter]=0;        //End of string


    discarded_numbers=0;
    signed int max_val=0, min_val=0;
    for(i=2; i < counter; i++)
    {
        signed short int a,b;
        a=buffer[i-2];
        b=buffer[i-1];

        if( (a+b) == buffer[i] ||
            (a-b) == buffer[i] ||
            (a*b) == buffer[i] ||
            (b != 0 && (a/b) == buffer[i]))
        {
            //printf("\nSum OK.\n");
            if (a>max_val)
                max_val=a;
            if (b>max_val)
                max_val=b;

            if (a<min_val)
                min_val=a;
            if (b<min_val)
                min_val=b;

            printf("\nMax value: %d", max_val);
            printf("\nMin value: %d", min_val);
        }
        else
        {
            //discard value
            discarded_numbers++;
        }


    }

    printf("\n\nNumber of discarded values: %d", discarded_numbers);
    printf("\nMax value: %d", max_val);
    printf("\nMin value: %d", min_val);


    fclose(origin_file);
}


void clearBuffer(char *b, unsigned short int size)
{
    char i=0;
    while(i<size)
    {
        *(b+i)=0;
        i++;
    }

}

