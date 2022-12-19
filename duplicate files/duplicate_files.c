#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 10
#define MAX_FILES 100000

struct File {
  char name[MAX_FILENAME_LENGTH + 1];
  int id;
};

int compare_files(const void* a, const void* b) {
  return ((struct File*)a)->id - ((struct File*)b)->id;
}

int main() {

    FILE *files_in;
    files_in = fopen("files.txt", "r");

    /*If file is not found or the file can't be read
     the funtion returns NULL, check if the file opening 
    function returns NULL, print the error to the user 
    and stop running the code*/ 
    if (files_in == NULL) 
    {
        printf("Error! File cannot be opened Check if file path is correct or if file exists.");
        exit(1);
    }

    // Read the number of test cases
    int T;
    fscanf(files_in, "%d", &T);

    for (int t = 0; t < T; t++) {
      // Read the number of files
      int N;
      fscanf(files_in, "%d", &N);

      // Create an array to store the files
      struct File files[MAX_FILES];

      for (int i = 0; i < N; i++) {
        // Read the file name and ID
        fscanf(files_in, "%s%d", files[i].name, &files[i].id);
      }

      // Sort the files in increasing order by ID
      qsort(files, N, sizeof(struct File), compare_files);

      // Print the IDs of the surviving files
      for (int i = 0; i < N; i++) {
        if (i == 0 || strcmp(files[i].name, files[i - 1].name) != 0) {
          printf("%d ", files[i].id);
        }
      }
      printf("\n");
    }

    return 0;
}
