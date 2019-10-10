/********************************/
/*Stephen Russell               */
/*CPSC1020 Fall 2019            */
/*UserName: SRusse5             */
/*Instructor:  Dr. Yvon Feaster */
/********************************/

#include "functions.c"
#include <time.h>

int main(int argc, char* argv[]){
    // Check arguments
    checkArguments(argc);

    // Initialize file pointer
    FILE * fpointer;
    fpointer = fopen(argv[1],"r");

    // Allocate memory for matrixInfo "myMat" (for testing purposes)
    matrixInfo_t *myMat = malloc(10*sizeof(matrixInfo_t));

    // Call functions
    allocateWords(myMat);
    readData(fpointer,myMat);
    readWords(fpointer,myMat);
    allocateLetters(myMat);
    readLetters(fpointer,myMat);
    printDirections(myMat);

    // words tester
    // int a=0;
    // while(myMat->words){
    //     printf(" %s",myMat->words[a]);
    //     a++;
    // }

    // Get current time
    time_t base = time(0);
    time_t now = base;

    printf("driver mymat->words[3]: %s\n",myMat->words[2]);
    readUserInput(myMat);
    printf("driver mymat->words[3] (2nd time): %s\n",myMat->words[2]);
    now = time (0);
    double timeDif = now - base;
    int timeDifInt = timeDif;
    int timeDifMin = timeDifInt / 60;
    int timeDifSec = timeDifInt % 60;
    printf("The amount of time for you to find %d words was %d min and %d sec.\n",myMat->numWords,timeDifMin,timeDifSec);
    fclose(fpointer);
}