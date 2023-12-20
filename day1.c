#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

   fp = fopen("input1", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    int sum = 0;
   while ((read = getline(&line, &len, fp)) != -1) {
     
     int lineStart = 0;
     int lineEnd = read - 2;
     char numOnLine[3] = {'\0', '\0', '\0'};
     while (!isdigit(line[lineStart])) {
       lineStart += 1;
     }
     numOnLine[0] = line[lineStart];
     while(!isdigit(line[lineEnd])) {
       lineEnd -= 1;
     }
     numOnLine[1] = line[lineEnd];
     int converted = atoi(numOnLine);
     if (converted > 99) {
       printf("\n\n\n%d\n\n\n", converted);
       //exit(0);
     }
     sum += converted;
     printf("\nStart: %c\nEnd: %c\nNumber: %d\nCurrent Sum: %d\n", numOnLine[0], numOnLine[1], converted, sum);
     //printf("%s -> First Digit %c, Last Digit %c, Number %s, Current Sum %d\n", line, firstDigit, lastDigit, numOnLine, convertedNum);
    }
   printf("%d\n", sum);
   

   free(line);
    exit(EXIT_SUCCESS);
}
