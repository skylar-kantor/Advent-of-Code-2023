#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(void) {
  FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

   fp = fopen("input2", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    int gameIDs = 0;
   while ((read = getline(&line, &len, fp)) != -1) {
     char *gameIDString = strtok(line, ":");
     char *gameInfo = strtok(NULL, ":");
     //strcpy(preserveID, gameIDString);
     char *extractedGameID = strtok(gameIDString, " ");
     extractedGameID = strtok(NULL, " ");
     //printf("extracted ID %s\n", extractedGameID);
     //printf("remaining: %s\n", gameInfo);

     char *subset1 = strtok(gameInfo, ";");
     char *subset2 = strtok(NULL, ";");

     printf("Game %s\n", extractedGameID);


     //Order is different, so we need to reset each time
     printf("SUBSET 1:\n");
     char *storeSubset;
     storeSubset = strcpy(storeSubset, subset1);
     char *subset1Green = strtok(subset1, " green");
     subset1  = strcpy(subset1, storeSubset);
     char *subset1Blue = strtok(subset1, " blue");

     char *subset1Red = strtok(subset1, " red");

     printf("Subset 1 contains %s green, %s blue, and %s red\n", subset1Green, subset1Blue, subset1Red);

      printf("SUBSET 2:\n");
     /* char *subset2Green = strtok(subset2, " green"); */
     /* char *subset2Blue = strtok(NULL, " blue"); */
     /* char *subset2Red = strtok(NULL, " red"); */

      storeSubset = strcpy(storeSubset, subset2);
     char *subset2Green = strtok(subset2, " green");
     subset2  = strcpy(subset2, storeSubset);
     char *subset2Blue = strtok(subset2, " blue");
     subset2  = strcpy(subset2, storeSubset);
     char *subset2Red = strtok(subset2, " red");

     printf("Subset 2 contains %s green, %s blue, and %s red\n\n", subset2Green, subset2Blue, subset2Red);
       
       

     
     
   }

  return 0;
}
