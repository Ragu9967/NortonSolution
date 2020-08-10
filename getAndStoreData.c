#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#define LEN_MAX 128
#define CHAR_MAX 100000

//Global variables
unsigned int len_max;
unsigned int current_size;
char *pStr;
// to store the data
char *fileName = "data.txt";

//Flag to check if EOF is called
bool check=false;

//once you press ctrl+d exit HANDLER gets called 
void exitHandler(int sig)
{
    char  cc;
    signal(sig, SIG_IGN);
	check = true;
	printf("\nDo you really want to quit? [y/n] ");
    cc = getchar();
}

//initialize the global variables
void init()
{
	len_max = LEN_MAX;
    current_size = 0;
    pStr = malloc(len_max);
    current_size = len_max;
}

// function to get the user data and store	
void getArbitraryDataAndStore()
{
	printf("\n[CRTL-D to exit]\nType something : \n");

    if(pStr != NULL)
    {
    	int c = EOF;
		unsigned int i =0;
		
	    //accept user input character by character
		while (c = getchar())
		{
			if(check == true)
			{
				if( c == 'y')
					exit(0);	// terminates the program
				else
				{
					check = false;
					signal(SIGINT, exitHandler);	//if user wishes to continue
					continue;
				}
			}
			
			if(c == EOF)
			{
				free(pStr);
				//pStr = NULL;			
				init();
				i = 0;
			}
			else
			{
				pStr[i++]=(char)c;
				//if i reached maximize size then realloc size
				if(i == current_size)
				{
	                current_size = i+len_max;
					pStr = realloc(pStr, current_size);
				}
				
				if(c == '\n' || i == CHAR_MAX ) {
					pStr[i] = '\0';
					//writes the data
					FILE *filePtr = fopen(fileName, "a+");
					fputs(pStr, filePtr);
					fclose(filePtr);
					free(pStr);
					init();
					i = 0;
				}
			}
		}
	}
}


int main()
{	

	// Register signal and signal handler
	signal(SIGINT, exitHandler);
	init();
    getArbitraryDataAndStore();
	return 0;
}
/*

*/
