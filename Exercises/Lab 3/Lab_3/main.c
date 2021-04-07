#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_CHARACTERS 25
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


int main()
{
    FILE *origin_file=0, *output_file=0;
    unsigned long int file_length=0;
    char c, to_store_value;
    char line_string[LINE_MAX_CHARACTERS+1];
    char *buffer;


    origin_file = fopen(INPUT_FILE_NAME,"r");   //Open file to read and write
    output_file = fopen(OUTPUT_FILE_NAME,"w");   //Open file to read and write

    if (origin_file)
    {
        printf("Origin address: %x\n", &origin_file);
        printf("Origin content: %x\n", origin_file);

        ///////////////////
        fseek(origin_file, 0, 2);                   //Get cursor to the end of the file
        file_length = ftell(origin_file);           //Cursor position.
        fseek(origin_file, -file_length, 1);        //Return cursor to original value.

        buffer = malloc((sizeof(char) * file_length)+1);    //Allocates RAM to store into array.
        ////////////////////////

        printf("Origin content: %x\n", origin_file);
        printf("File length: %d\n", file_length);

        unsigned long int i=0;
        while((c = fgetc(origin_file)) != EOF ){
            buffer[i] = c; //Copies char value to buffer
            printf("%d",i);
            i++;
        }
        //buffer[i] = c;
        printf("%d", i);
        printf("\n buffer: %s \n",buffer);

        for(i=0; i < file_length ; i++){    //Iterate buffer
            to_store_value = buffer[i];
            printf("%c(%d) ",to_store_value, i);
        }

//        while ((c = getc(origin_file)) != EOF)       //Iterate the whole file.
//        {
//            to_store_value = c;
//            printf("%c(%d) ",to_store_value,ftell(origin_file));
//
//            if(c >= '0' && c <= '9')    //Filters, conditions, etc.
//                to_store_value = '*';
//            else if(c == '.' && 1)
//            {
//
//            }
//
//            fputc(to_store_value,output_file);      //Write character.
//        }



        //" | c:%d \n"

    }
    else
        printf("Could not open the file.");

    //showOutputFile(output_file);

    fclose(origin_file);
    fclose(output_file);
    free(buffer);
    return 0;
}

void showOutputFile(FILE *f)
{
    char c;
    while ((c = getc(f)) != EOF)       //Iterate the whole file.
        printf("%c",c);
}
