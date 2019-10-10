/********************************/
/*Stephen Russell               */
/*CPSC1020 Fall 2019            */
/*UserName: SRusse5             */
/*Instructor:  Dr. Yvon Feaster */
/********************************/

#include "functions.h"
/* read data, then print, then do input*/

/*This function reads the information from the a file. I included a 
 *sample file for your use. */
void readData(FILE* fpointer, matrixInfo_t* myMat){ 
    // Check if file is found
    if(fpointer==NULL){
        printf("File Not Found");
        exit(1);
    }

    // read each line of data into array inputArray
    char inputArray[20][20];
    char buffer[50];
    int count = 0;
    //fscanf(fpointer,"%2s",buffer) ???
    while(fgets(buffer,50,fpointer)!=NULL){
        strcpy(inputArray[count],buffer);
        // printf("line %d: %s",count,inputArray[count]);
        count++;
    }

    // TODO: MAKE THIS WORK FOR ARRAYS LARGER THAN 9X9 (those which use double digit numbers)
    // assign lines from inputArray to myMat
    int rows = atoi(&inputArray[0][0]);
    int cols = atoi(&inputArray[0][2]);
    myMat->rows = rows;
    myMat->cols = cols;
    int numWords = atoi(inputArray[2]);
    myMat->numWords = numWords;
    for(int i=3;i<numWords+3;i++){
        myMat->words[i-3] = inputArray[i];
        printf("i: %d\t",i);
        printf("myMat->words[i-3]: %s", myMat->words[i-3]);
    }
};


/*This function contains the print statements that will give the user
 *directions. See the sample run in the document. */
void printDirections(matrixInfo_t* myMat){
    printMatrix(myMat);
    printf("\t\tConsidering the above matrix of characters. This matrix has\n");
    printf("\t\tat least 12 words in it. Your job is to find as many of these\n");
    printf("\t\twords as possible. The letter for each word must touch. In\n");
    printf("\t\tother words, the letters should be side-by-side or diagonal \n");
    printf("\t\tof each other\n\n");
    printf("\t\tType each word then enter. When you are finished type quit.\n");
};

//Done..ish.. TODO: MAKE WORK FOR NON 3X3 MATRICES
/*This function is used to print the matrix complete with the characters.
 * the following is the format.
 +-----+-----+-----+
 |  s  |  h  |  o  |
 +-----+-----+-----+
 |  h  |  u  |  t  |
 +-----+-----+-----+
 |  i  |  g  |  h  |
 +-----+-----+-----+
 */
void printMatrix(matrixInfo_t* myMat){
    char rows = myMat->rows;
    char cols = myMat->cols;

    int count = 0;
    for(int r = 0; r <= rows; r++){
        printf("\t\t\t\t\t");
        for(int c = 0; c < cols; c++)
            printf("+-----");

        printf("+\n");
        printf("\t\t\t\t\t");
        if(r<rows){
            for(int c = 0; c < cols; c++){
                printf("|  %c  ", myMat->letters[count]);
                count++;
            }
            printf("|\n");
        }
    }
    printf("\n");
};

/*This function is used to read the user input*/
int readUserInput(matrixInfo_t* myMat){
    int r = myMat->rows;
    int c = myMat->cols;
    char inp;

    scanf(" %s",&inp);
    printf("readUserInput 2 mymat->words[2]: %s\n",myMat->words[2]);
    while(strcmp(&inp,"quit")){
        printf("readUserInput 3 mymat->words[2]: %s\n",myMat->words[2]);
        checkWords(&inp,myMat);
        scanf("%s", &inp);
    }
    return 1;
};

/*This function is used to determine if the word
 *the user entered is one of the word in the data
 *file.  If it is one of the words in the data
 *1 is returned and 0 otherwise*/
int checkWords(char* inp, matrixInfo_t* myMat){
    int i = 0;
    // char* thisWord;
    for(int i=0;i<myMat->numWords;i++){
        printf(" words[%d]: %s\n",i,myMat->words[i]);
        // printf("HERE'S 3: %s",myMat->words[3]);
        // strcpy(thisWord, myMat->words[i]);
        // printf("%s", thisWord);
        // if(*myMat->words[i]='\0'){
        //     printf("break");
        //     break;
        // }
        // if(*myMat->words[i]==*inp){
        //     printf("Match!");
        // }
        // printf("here");
    }
};

// DONE
/*This allocates memory for a 1D array for the letters
 *that will displayed in the matrix*/
void allocateLetters(matrixInfo_t* myMat){
    int r = myMat->rows;
    int c = myMat->cols;
    myMat->letters = calloc(r*c,sizeof(int));
};

// DONE
/*This allocates memory for a 2D array to hold the possible
 *words in the matrix.  In the data file you will be given
 *the number of words. so you will first allocate for that
 *number of pointers.  You will then need to allocate the
 *space for each word.  But how do you know how large the
 *word may be?  Think about what is the largest possible
 *size a word in the matrix could be. Allocate that size
 *for each word.*/
void allocateWords(matrixInfo_t* myMat){
    int numWords = myMat->numWords;
    int r = myMat->rows;
    int c = myMat->cols;

    // printf("From allocateWords: numWords = %d",numWords);
    // yields 12
    
    // printf("r = %d  |  c = %d",r,c);
    // 3 and 3
    myMat->words = malloc(numWords*sizeof(char));
    for(int i=0;i<numWords;i++){
        myMat->words[i] = malloc(r*c*sizeof(char));
    }
};

// DONE?
/*This function reads the letters from the data file for
 *the matrix*/
void readLetters(FILE* fpointer, matrixInfo_t* myMat){
    char inputArray[20][20];
    char buffer[50];
    char letters[50];
    int rows = myMat->rows;
    int cols = myMat->cols;
    int count = 0;
    //fscanf(fpointer,"%2s",buffer) ???
    // while(fgets(buffer,50,fpointer)!=NULL & count<2){
    //     strcpy(inputArray[count],buffer);
    //     printf("line %d: %s",count,inputArray[count]);
    //     count++;
    // }
    int i = 0;
    int j = 0;
    // remove spaces
    // TODO: FIX GLOBAL VARIABLE INPUTARRAY
    while(inputArray[1][i] != '\0'){
        if(i%2==0){
            myMat->letters[j] = inputArray[1][i];
            j++;
        }
        myMat->letters[i] = inputArray[1][i];
        i++;
    }
    myMat->letters[j] = '\0';    
    printf("myMatLetters[i] is: %s\n",myMat->letters);
};

// currently not being used right i think
/*This function reads the words from the data file*/
void readWords(FILE* fpointer, matrixInfo_t* myMat){
    char inputArray[20][20];
    char buffer[50];
    int count = 0;
    //fscanf(fpointer,"%2s",buffer) ???
    while(fgets(buffer,50,fpointer)!=NULL){
        strcpy(inputArray[count],buffer);
        printf("line %d: %s",count,inputArray[count]);
        count++;
    }
};

// DONE
/*This function checks to make sure the appropriate number of
 *command line arguements are used when running. The program
 *should have one argument for <executable> <file name>*/
void checkArguments(int argc){
    if(argc != 2){
        printf("\n Usage error. Correct usage: ./a.out <datafilename.txt>\n\n");
        exit(-1);
    }
};

/*This function gives the memory back to the operating system.
 *This is used for a 1D matrix*/
void free1DMemory(matrixInfo_t*);

/*This function gives the memory back to the operating system.
 *This is used for a 2D matrix*/
void free2DMemory(matrixInfo_t*);