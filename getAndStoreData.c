#include <stdio.h>

void getArbitraryDataAndStore()
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;    
    char *pStr = malloc(len_max);
    current_size = len_max;
    
	// to store the data
    char *fileName = "data.txt";

    printf("\Give your Input ! \n");

    if(pStr != NULL)
    {
    	// accept the user input till the end of line
		int c = EOF;
		unsigned int i =0;
		while (( c = getchar() ) != '\n' && c != EOF)
		{
			pStr[i++]=(char)c;
			if(i == current_size)
			{
	            current_size = i+len_max;
				pStr = realloc(pStr, current_size);
			}
		}
	
		pStr[i] = '\0';
		
		// append the data to the file
		FILE *filePtr = fopen(fileName, "a+");
		fputs(pStr, filePtr);
		fclose(filePtr);
		
		//free the char pointer 
		free(pStr);
		pStr = NULL;
    }	    
}
int main()
{
	getArbitraryDataAndStore();
    return 0;
}

