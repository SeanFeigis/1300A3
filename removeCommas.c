#include <string.h>

/*
Author: Sean Feigis
Last Updated: October 27, 2019
Purpose: To reduce all the extra white space
*/

int removeCommas( char *line) {
	int j,i;

   for (i = 0; i < strlen(line); i++){

      if (line[i] == 44) {
         for (j = i;  j < strlen(line); j++) {
	         line[j] = line[j+1]; 
	      }		
      } 
   }
   return (0);
}


