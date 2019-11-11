#include <string.h>

/*
Author: Sean Feigis
Last Updated: November 11, 2019
Purpose: removes the end of line character from each line
*/

int chop( char *line ) {

   if (line[strlen(line) -1] == 10) {
      line[strlen(line)-1]  = '\0';
      return(0);
   } else {
      return(-1);
   }
}


