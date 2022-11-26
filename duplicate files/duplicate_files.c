#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () 
{
    int test_cases, number_of_files;
    char fileName_Id[100010];
    int fileId[100][100000];
    char fileName[100][10];

    FILE *files_in;
    files_in = fopen("files.txt", "r");

    if (files_in == NULL) 
    {
        printf("Error! File cannot be opened Check if file path is correct or if file exists.");
        exit(1);
    }


    fscanf (files_in, "%i", &test_cases);
    printf("%i", test_cases);

    fscanf(files_in, "%i", &number_of_files);
    printf("\n%i", number_of_files);
    
    int line_counter = 1;
    int i = 0;
    while (fgets(fileName_Id, 100010, files_in)) 
    {
        line_counter++;

        if (line_counter > 2) 
        {
            printf("\n%s", fileName_Id);
            char *token = strtok(fileName_Id, " ");
            printf("\n%s", token);
            //strcpy(fileName[i], token);
            //printf("Array of filenames %s", fileName);

        }

        i++;

    }


}