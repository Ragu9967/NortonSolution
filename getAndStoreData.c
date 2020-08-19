#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define BUF_LENGTH 1024

//Input buffer to get the data
wchar_t *inputBuffer;

//File name provided to store the data
char *fileName = "Data";

// display terminate condition
void displayInstructions()
{
    fputs("\nPress ctrl+d to terminate.\nEnter your input : \n",stdout);
}

//Initialized the buffer
void init()
{
    inputBuffer = malloc(BUF_LENGTH);
}

//Stores the data
void dumpData()
{
    FILE *filePtr = fopen(fileName, "ab+");

    //fputws(L"\nCheck : ", stdout);
    //fputws(inputBuffer, stdout);
    //fwrite(str, sizeof(wchar_t), wcslen(str), filePtr);
    if(fputws(inputBuffer, filePtr) < 0)
    {
        printf("\nWrite operation is not successful. Check if your disk space ran out ! \n");
        fclose(filePtr);
        exit(0);
    }
    fclose(filePtr);
}

//function to read the data from stdin
void getArbitraryDataAndStore()
{
    /*
    1. reads n(n = BUF_LENGTH) characters from stdin with the inputBuffer.
    2. dumps the data in the file
    3. read next n characters and the steps continues
    */
    while(fgetws(inputBuffer, BUF_LENGTH, stdin))
    {
        dumpData();
    }

    // checks if reading input from stdin is successful
    if(ferror(stdin))
    {
        free(inputBuffer);
        perror("read from stdin failed");
        exit(3);
    }
}

int main(){

    // display terminate condition
    displayInstructions();

    // initialize
    init();

    // get the data from stdin
    getArbitraryDataAndStore();

    // invokes once EOF is reached. ie when ctrl+d is pressed
    if(feof(stdin))
    {
      	puts("\nEOF detected - Terminated\n");
    }

    return 0;
}
