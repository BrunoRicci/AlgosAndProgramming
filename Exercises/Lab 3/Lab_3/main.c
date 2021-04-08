#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_CHARACTERS 25
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#define BUFFER_SIZE 1000  //1kB static buffer...


int main()
{
    FILE *origin_file=0, *output_file=0;
    unsigned long int file_length=0;
    char c, to_store_value;
    char line_string[LINE_MAX_CHARACTERS+7]="", character_counter;
    char buffer[BUFFER_SIZE];


    origin_file = fopen(INPUT_FILE_NAME,"r");   //Open file to read and write
    output_file = fopen(OUTPUT_FILE_NAME,"w");   //Open file to read and write

    if (origin_file)
    {
        printf("Origin address: %x\n", &origin_file);
        printf("Origin content: %x\n", origin_file);


        unsigned long int i=0;
        while((c = fgetc(origin_file)) != EOF ){
            buffer[i] = c; //Copies char value to buffer
            i++;
        }
        file_length = i;    //Saves file size
        printf("File length: %d\n", i);
        //printf("\n\nbuffer: %s \n",buffer);



        character_counter=1;

        for(i=0; i < file_length  ; i++)    //Iterate buffer
        {

            printf("%c",buffer[i], i);

            if(buffer[i] >= '0' && buffer[i] <= '9')    //Filters, conditions, etc.
            {
                //printf("\nnumber\n");
                strcat(line_string, "*");
            }
//            else if((buffer[i] == '.' || buffer[i] == ',' || buffer[i] == ';' || buffer[i] == ':' || buffer[i] == '!' || buffer[i] == '?') && (buffer[i+1] != ' ' || buffer[i+1] != '\n') )
//            {
//                //printf("\ndot\n");
//                char x[2]={0,0};
//                x[0]=(char)buffer[i];
//                strcat(line_string, x);
//                strcat(line_string, " ");
//            }
            //
            else if(buffer[i] == '.' || buffer[i] == ',' || buffer[i] == ';' || buffer[i] == ':' || buffer[i] == '!' || buffer[i] == '?')
            {
                if(buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?')   //Add uppercase
                {
                   if(buffer[i+2] >= 'a' && buffer[i+2] <= 'z' )
                      buffer[i+2]-=20;    //Convert to uppercase

                }

                char x[2]={0,0};
                x[0]=(char)buffer[i];
                strcat(line_string, x); //Add character

                if(buffer[i+1] != ' ' || buffer[i+1] != '\n')
                {
                    strcat(line_string, " ");
                }

            }
            else{
                //printf("\ncharacter\n");
                char x[2]={0,0};
                x[0]=(char)buffer[i];
                strcat(line_string, x);
            }

            if(character_counter >= LINE_MAX_CHARACTERS || buffer[i] == '\n' )
            {
                printf("\n###\n");
                char x[3]={0,0,0};
                itoa(character_counter, x , 10);  //Save amount of characters into X array

                if(line_string[character_counter] == '\n')
                    line_string[character_counter]='\0'; //Replace '\n' for SPACE symbol

                while(character_counter < LINE_MAX_CHARACTERS)
                {
                    strcat(line_string, " ");
                    character_counter++;
                }

                strcat(line_string, "| c:");
                strcat(line_string, x);
                strcat(line_string, "\n");

                printf("\nline_string: %s\n", line_string);//debug
                fputs(line_string, output_file);    //Save line to file

                clearBuffer(line_string, sizeof(line_string));

                character_counter = 0;
            }
            character_counter++;

            //fputc(to_store_value,output_file);      //Write character.
        }

        printf("\n\nline_string: %s", line_string);
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

void clearBuffer(char *b, unsigned short int size)
{
    char i=0;
    while(i<size)
    {
        *(b+i)=0;
        i++;
    }

}
