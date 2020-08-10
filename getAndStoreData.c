#include <stdio.h>
void getArbitraryDataAndStore()
{
    FILE * fp;
    char c;
    printf("Go on, Give your input ... \n");
	
	// creating and inserting data into the file named "data.txt". Next time when we give input the data get appended to the file
    fp = fopen("data.txt", "a+");

    while ((c = getchar()) != EOF && (c != '\n')) {
        putc(c, fp);
    }
    
    fclose(fp);
}
int main()
{
	getArbitraryDataAndStore();
    return 0;
}

