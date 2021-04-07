#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_CHARACTERS 25
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


int main()
{
    FILE *origin_file=0, *output_file=0;
    unsigned long int file_length;
    char c, to_store_value;
    char line_string[LINE_MAX_CHARACTERS+1];



    origin_file = fopen(INPUT_FILE_NAME,"r");   //Open file to read and write
    output_file = fopen(OUTPUT_FILE_NAME,"w");   //Open file to read and write

    if (origin_file)
    {
        //printf("Origin address: %x\n", &origin_file);
        //printf("Origin content: %x\n", origin_file);

        ///////////////////
        fseek(origin_file, 0, 2);
        file_length = ftell(origin_file);
        fseek(origin_file, -file_length, 1);     //Returns pointer to original value.
        printf("\nFile length: %d   pos:%d\n", file_length, ftell(origin_file));
        ////////////////////////


        while ((c = getc(origin_file)) != EOF)       //Iterate the whole file.
        {
            to_store_value = c;
            printf("%c(%d) ",to_store_value,ftell(origin_file));
            if(c >= '0' && c <= '9')
                to_store_value = '*';


            fputc(to_store_value,output_file);
        }



        //" | c:%d \n"

    }
    else
        printf("Could not open the file.");

    //showOutputFile(output_file);

    fclose(origin_file);
    fclose(output_file);
    return 0;
}

void showOutputFile(FILE *f)
{
    char c;
    while ((c = getc(f)) != EOF)       //Iterate the whole file.
        printf("%c",c);
}
