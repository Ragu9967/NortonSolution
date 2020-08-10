#include <stdio.h>
#include <stdbool.h>

#define LEN_MAX 128

struct getInput{
//	unsigned int len_max;
//    unsigned int current_size;    
    //char *pStr;
//    int c;
//	unsigned int i;
};

void init(){
	
}

void getArbitraryDataAndStore(struct getInput **gInit)
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;
    char *pStr = malloc(len_max);
    current_size = len_max;
    // to store the data
    char *fileName = "data.txt";
    
//	while()
	{
    
	printf("\nGive your data : ");

    if(pStr != NULL)
    {
		int c = EOF;
		unsigned int i =0;
	      //accept user input until hit enter or end of file
		while (( c = getchar() != '\n') && c != EOF)
		{
				pStr[i++]=(char)c;
				//fputc('c', filePtr);
				//if i reached maximize size then realloc size
				if(i == current_size)
				{
		                        current_size = i+len_max;
					pStr = realloc(pStr, current_size);
				}
			//if(c == '\n')
			if(i == 10)
			{
				pStr[i] = '\0';
	
			    printf("\nLineBreak : Long String value:%s \n\n",pStr);			    
	    		FILE *filePtr = fopen(fileName, "w+");
				fputs(pStr, filePtr);
				fclose(filePtr);
								
			    //free it 
				free(pStr);
				//pStr = NULL;			
				
				//unsigned int 
				len_max = 128;
				//unsigned int 
				current_size = 0;
				//char 
				*pStr = malloc(len_max);
				current_size = len_max;
				i = 0;
				printf("\n remaining data : ");	
				
//				printf("\nGive your data : ");					
			}	
		}
		printf("\nEND\n");
	/*
		pStr[i] = '\0';
	
	    printf("\nLong String value:%s \n\n",pStr);
	    
	    		FILE *filePtr = fopen(fileName, "w+");
						fputs(pStr, filePtr);
						fclose(filePtr);
						
	    //free it 
		free(pStr);
		pStr = NULL;
    */
	}
	}
}
int main()
{
	struct getInput *gInit;

	getArbitraryDataAndStore(&gInit);
    return 0;
}

