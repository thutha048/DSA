#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct csv_line {
  int value1;
  float value3;
  int value2;
  char char1;
};

struct csv_line *line_pointer = NULL;

int main(void) 
{
    FILE *csvFile = NULL;
    csvFile = fopen("/home/test.txt", "r");
    if (csvFile == NULL)
    {
        perror( "fopen failed" );
        exit(1);
    }

    size_t i = 1;
    line_pointer = malloc( sizeof(struct csv_line) * i );
    if( ! line_pointer )
    {
        perror( "malloc failed" );
        fclose( csvFile );
        exit( EXIT_FAILURE );
    }

    while ( (fscanf(csvFile, "%d,%f,%d,%c",
                &(line_pointer + i)->value1,
                &(line_pointer + i)->value3,
                &(line_pointer + i)->value2,
                &(line_pointer + i)->char1) ) == 4 )
    {
        i++;
        struct csv_line *temp = realloc(line_pointer, sizeof(struct csv_line) * i );
        if( ! temp )
        {
            perror( "realloc failed" );
            free( line_pointer );
            fclose( csvFile );
            exit( EXIT_FAILURE );
        }
    }

    fclose(csvFile);

    // per the request that the last entry contains NULL
    memset( &line_pointer[i], 0, sizeof( struct csv_line ) );

    for( size_t k=0; k < (i-1); k++ ) 
    {
        printf("%d, %.2f, %d, %c",
                (line_pointer + k)->value1,
                (line_pointer + k)->value3,
                (line_pointer + k)->value2,
                (line_pointer + k)->char1);
        printf("\n");
    }

    free(line_pointer);

    return EXIT_SUCCESS;
}
