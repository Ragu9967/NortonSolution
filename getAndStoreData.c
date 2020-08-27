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
    fputs("\nPress ctrl+c to terminate the input operation. enter exit to exit the application\n",stdout);
}

//Initialized the buffer
void init()
{
    inputBuffer = malloc(BUF_LENGTH);

}
//Clears the outfile before each input
void flushOutputFile()
{
    if( access( fileName, F_OK ) != -1 )
        remove(fileName);
}

//Stores the data
void dumpData()
{
    FILE *filePtr = fopen(fileName, "ab+");

    //fputws(L"\nCheck : ", stdout);
    //fputws(inputBuffer, stdout);
    //if(fputws(inputBuffer, filePtr) < 0)
    if(fwrite(inputBuffer, 1, BUF_LENGTH, filePtr) < 0)
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
    flushOutputFile();
    puts("Give your console input : ");
    /*
    1. reads n(n = BUF_LENGTH) characters from stdin with the inputBuffer.
    2. dumps the data in the file
    3. read next n characters and the steps continues
    */
    //while(fgetws(inputBuffer, BUF_LENGTH, stdin))
    while(fread(inputBuffer, 1, BUF_LENGTH, stdin))
    {
        dumpData();
        //free(inputBuffer);
    }

    // checks if reading input from stdin is successful
    if(ferror(stdin))
    {
        free(inputBuffer);
        perror("\nread from stdin failed\n");
        exit(3);
    }
    puts("\n[Data written successfully]\n");
}

/*
    You can pass a normal txt file / unicode txt file / img file as a input.
    Provide a valid filename. If the file exists then the data is read and stored in the OUTPUT file as bin.
    Then you can open the bin file via right application to view the data stored.
*/
void getFileInput()
{
    flushOutputFile();
    char IfileName[100];
    printf("\nProvide a valid fileName : ");
    scanf("%s",IfileName);
    if( access( IfileName, F_OK ) != -1 )
    {
        FILE *filePtr = fopen(IfileName, "rb");
        int n;
        while(n = (fread(inputBuffer, 1, BUF_LENGTH, filePtr)))
        {
            printf("%d bytes written\n",n);
            dumpData();
        }
        fclose(filePtr);

        // checks if reading input from stdin is successful
        if(ferror(stdin))
        {
            free(inputBuffer);
            perror("\nread from stdin failed\n");
            exit(3);
        }
        puts("\n[Data written successfully]\n");
    }
    else
    {
        puts("\nInvalid file...\n");
        //getFileName;
    }
}

/*
    Gets the input from the user
    enter 1 to pass a file as a input
    enter 0 to exit the program
    enter any other key to give a stdin input
*/
void getInputType()
{
    puts("Enter '1' to provide a FILENAME as input || Enter '0' to EXIT || Press any other key for CONSOLE input :");
    char inputChoice;
    scanf(" %c", &inputChoice);

    if(inputChoice == '1' )
        getFileInput();
    else if(inputChoice == '0')
        exit(0);
    else
        getArbitraryDataAndStore();
}

int main(){

    // display terminate condition
    displayInstructions();

    while(1)    // terminates only if user wishes to terminate
    {
        // initialize
        init();

        // Get if its a file input or console input.
        getInputType();

        // invokes once EOF is reached. ie when ctrl+d is pressed.
        if(feof(stdin))
        {
            puts("\nEOF detected - Input mode Terminated\n");
        }
    }
    return 0;
}
