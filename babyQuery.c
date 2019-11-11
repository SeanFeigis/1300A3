#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "babies.h"


int main ( int argc, char *argv[] ) {
	FILE *f1;
   int i = 0;
   int j = 1; 
   struct pNames popNames;
   char maleSNumber[20];
   char femaleSNumber[20];
   char string[100];
   int choice = 0;
   char decade[5];
   char decadeChoice[15];
   char branch[6];
   char rank[3];
   char gender[1];
   char name[20];
   char branchEnd[1];
   char end[2];
   int numRank;
   int numGender;
   char decades2[5];
   int userIn;

   if ( argc != 1 ) {
      printf ( "Usage: displayBabies \n" );
      return ( -1 );
   }

   do {
      decade[0] = '\0';
      do {  
         printf("What decade do you want to look at? [1880 to 2010]\n");
         fflush(stdin);
         if (fgets(decade, 5, stdin) != NULL) {
            decade[4] = '\0';
            fflush(stdin);
            if (strcmp(decade, "1880") == 0 || strcmp(decade, "1890") == 0 || strcmp(decade, "1900") == 0 || strcmp(decade, "1910") == 0 || strcmp(decade, "1920") == 0 || strcmp(decade, "1930") == 0 || strcmp(decade, "1940") == 0 || strcmp(decade, "1950") == 0 || strcmp(decade, "1960") == 0 || strcmp(decade, "1970") == 0 || strcmp(decade, "1980") == 0 || strcmp(decade, "1990") == 0 || strcmp(decade, "2000") == 0 || strcmp(decade, "2010") == 0 ) {
               choice = 0;
            } else {
               printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, 2010. No other values are acceptable\n");
               choice = 1;
               strcpy(decade, "");
            }
         }
      } while (choice != 0);

      decadeChoice[0]= '\0';
      strcpy(decades2, decade);
      strcpy(decadeChoice, strcat(decade, "Names.txt"));
      /*printf("%s\n", decadeChoice); */

      fflush(stdin);
      string[0] = '\0';

  
      if ( (f1 = fopen(decadeChoice, "r")) != NULL ) {
         while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
   /* printf ( "%d %s %s %s %s\n",popNames.rank[i],popNames.maleName[i],maleSNumber,popNames.femaleName[i],femaleSNumber ); */
            removeCommas ( maleSNumber );
            removeCommas ( femaleSNumber );
            popNames.maleNumber[i] = atoi ( maleSNumber );
            popNames.femaleNumber[i] = atoi ( femaleSNumber );
            i++;
         }
      } else {
         printf ( "Cannot open %s\n", argv[1] );
         return ( -2 );
      }

      fclose(f1);

      /*
      for ( j=0; j<i; j++ ) {
         printf ( "%d %s %d %s %d\n", popNames.rank[j], popNames.maleName[j], popNames.maleNumber[j], popNames.femaleName[j], popNames.femaleNumber[j] );
      }
      */

     
     while((getchar())!='\n');
      choice = 1;
   
     do {

      choice = 1;
      while ( choice !=0) {
         printf("\nWould you like to see the rank, search for a name, or see a top 10? [rank, search, top]\n");

         if (fgets(branch, 500, stdin) != NULL) {
            branch[strlen(branch)-1] = '\0';
            
            if (strcmp(branch, "rank") == 0 || strcmp(branch, "search") == 0 || strcmp(branch, "top") == 0) {
               choice = 0;
            } else {
               choice = 1;
               printf("\nPlease type in rank, name, or top exactly as requested.");
            }
         }
      } 

      if (strcmp(branch, "rank")  == 0) {
         choice = 1;
         while(choice !=0) {
            printf("\nWhat rank do you wish to see? [1-200]\n");
            if(fgets(rank, 5, stdin) != NULL) {
               numRank = atoi(rank);   
               if (numRank < 201 || numRank < 0) {
                  choice = 0;
               } else {
                  printf("\nOnly numbers between 1 and 200 are acceptable.\n");
               }
            }
         }
         choice = 1;
         while (choice != 0) {
            printf("\nWould you like to see male(0), female (1), or both(2) name(s)?\n");
            if (fgets(gender, 2, stdin) != NULL) {
               numGender = atoi(gender);
               if (numGender > 2 || numGender < 0) {
                  printf("Only the numbers 0, 1, and 2 are acceptable");
               } else {
                  if (numGender == 0){
                     printf("Rank: %d, Male: %s (%d)\n", popNames.rank[numRank-1], popNames.maleName[numRank-1], popNames.maleNumber[numRank-1]);
                     choice = 0;
                  } else if (numGender == 1) {
                     printf("Rank: %d, Female: %s (%d)\n", popNames.rank[numRank-1], popNames.femaleName[numRank-1], popNames.maleNumber[numRank-1]);
                     choice = 0;
                  } else if (numGender == 2) {
                     printf("Rank: %d, Male: %s (%d) and Female: %s (%d)\n", popNames.rank[numRank-1], popNames.maleName[numRank-1], popNames.maleNumber[numRank-1], popNames.femaleName[numRank-1], popNames.maleNumber[numRank-1]);
                     choice = 0;
                  }
               }
            }
         }
      } else if (strcmp(branch, "search") == 0) {

         printf("What name do you want to search for? [case sensitive]:\n");
            if (fgets(name, 20, stdin) != NULL) {
               chop(name);
               printf("Would you like to see male(0), female (1), or both(2) name(s)? [0-2]:\n");
               choice = 1;
               while(choice != 0) {
                  if (fgets(gender, 20, stdin) != NULL) {
                     numGender = atoi(gender);
                     if (numGender > 2 || numGender < 0) {
                        choice = 1;
                        printf("Only the number 0, 1, and 2 are acceptable.\n");
                     } else {
                        choice = 0;
                        
                     }    
                  }   
               }
               if (numGender == 0) {
                  for(i = 0; i < 200; i++) {
                     if (strcmp(name, popNames.maleName[i]) ==0) {
                        printf("In %s, the male name %s is ranked %d with a count of %d.\n", decades2, name, i + 1, popNames.maleNumber[i] );
                        j = 0;
                     }
                  }
                  if (j != 0) {
                     printf("In %s, the male name %s was not found.\n", decades2, name );
                  }
               } else if ( numGender == 1) {

                  for(i = 0; i < 200; i++) {
                     if (strcmp(name, popNames.femaleName[i]) ==0 ) {
                        printf("In %s, the female name %s is ranked %d with a count of %d.\n", decades2, name, i + 1, popNames.femaleNumber[i] );
                        j = 0;
                     }
                  }
                  if (j != 0) {
                     printf("In %s, the female name %s was not found.\n", decades2, name );
                  }
               } else if ( numGender == 2) {
                     for(i = 0; i < 200; i++) {
                     if (strcmp(name, popNames.femaleName[i]) ==0 ) {
                        printf("In %s, the female name %s is ranked %d with a count of %d ", decades2, name, i + 1, popNames.femaleNumber[i]);
                        j = 0;
                     }
                  }
                  if (j != 0) {
                     printf("The female name %s was not ranked", name );
                  }
                  for(i = 0; i < 200; i++) {
                     if (strcmp(name, popNames.maleName[i]) ==0 ) {
                        printf(" and the male name %s is ranked %d with a count of %d\n", name, popNames.rank[i], popNames.maleNumber[i]);
                        j = 0;
                     }
                 }
                 if (j != 0) {
                     printf("The male name %s was not ranked\n", name );
                  }
               }
            }
      } else if (strcmp(branch, "top") == 0) {

         for (i =0;  i< 10; i++) { 

            printf("%d   \t %s   \t %d   \t %s   \t %d \n", popNames.rank[i], popNames.maleName[i], popNames.maleNumber[i], popNames.femaleName[i], popNames.femaleNumber[i]);

         }

      }

      branch[0] = '\0';
      branch[1] = '\0';
      name[0] = '\0';
      rank[0] =  '\0';

      fflush(stdin);
      choice = 1;
      printf("\nDo you want to ask another question about %s? [Y or N]:\n", decades2);
      userIn = 0;
      do {
         fflush(stdin);
         if (fgets(branchEnd, 500 , stdin) != NULL) {
            branchEnd[1] = '\0';
            fflush(stdin);
            if (strcmp(branchEnd, "Y") != 0 && strcmp(branchEnd, "N") != 0) {
               printf("Only the single characters Y and N are acceptable.");
               userIn = 0;
            }
            else if (strcmp(branchEnd, "Y") == 0) {
               choice = 1;
               userIn = 1;
            } else if (strcmp(branchEnd, "N") == 0) {
               choice = 0;
               userIn = 1;
            }
         }
      } while((userIn == 0));
   } while (choice != 0);

      strcpy(branch, "");
      strcpy(gender, "");
      strcpy(name, "");
      strcpy(rank, "");

      fflush(stdin);
      printf("\nWould you like to select another year? [Y or N]\n");
      if (fgets(end, 2 , stdin) != NULL) {
         chop(end);
         if (strcmp(end, "Y") == 0) {
            choice = 1;
         } else if (strcmp(end, "N") == 0) {
            choice = 0;
         }
      }

      strcpy(branch, "");
      strcpy(gender, "");
      strcpy(name, "");
      strcpy(rank, "");
      strcpy(decade, "");
      strcpy(decadeChoice, "");
      strcpy(branchEnd, "");

   } while ((choice = 1 ));

   return (0);
}


         
