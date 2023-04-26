#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
  FILE *filePointer ;
     
    // Declare the variable for the data to be read from file
    char dataToBeRead[50];
 
    // Open the existing file GfgTest.c using fopen()
    // in read mode using "r" attribute
    filePointer = fopen("Sorting.txt", "r") ;
     
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "GfgTest.c file failed to open." ) ;
    }
    else
    {
         
        printf("The file is now opened.\n") ;
         
        // Read the dataToBeRead from the file
        // using fgets() method
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
        {
         
            // Print the dataToBeRead
            printf( "%s" , dataToBeRead ) ;
        }
         
        // Closing the file using fclose()
        fclose(filePointer) ;
         
        printf("Data successfully read from file GfgTest.c\n");
        printf("The file is now closed.") ;
    }
    printf("%s", dataToBeRead);
    int arr[50];
    int index=0,c=0;
    for(int i=0;i!='\0';i++)
    {
        printf("%c",dataToBeRead[i]);
    }
    printf("\n%d\n",c);
  /*  for(int i=0;i<index;i++)
     printf("%d\n",arr[i]);
    return 0;  */     
}
