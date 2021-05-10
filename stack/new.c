#include <stdio.h>
#include <stdlib.h>

struct csv_line{
  int value1;
  float value3;
  int value2;
  char char1;
};

struct csv_line *line_pointer = NULL;

int main(void) {
    FILE *csvFile = NULL;
    csvFile = fopen("test.txt", "r");
    if (csvFile == NULL)
      exit(1);

    size_t i = 0;
    while (1) {
    line_pointer = (struct csv_line *)realloc(line_pointer, sizeof(struct csv_line) * (i + 1));
    if (fscanf(csvFile, "%d,%f,%d,%c",
            &(line_pointer + i)->value1,
            &(line_pointer + i)->value3,
            &(line_pointer + i)->value2,
            &(line_pointer + i)->char1) != EOF) {
      i++;
    } else{
        (line_pointer + i)->value1 = 0;
        (line_pointer + i)->value3 = 0.0;
        (line_pointer + i)->value2 = 0;
        (line_pointer + i)->char1 = '\0';
        break;
     }
    }
    fclose(csvFile);
    int k = 0;
    while('\0' != (line_pointer + k)->char1) {
        printf("%d, %.2f, %d, %c",
                (line_pointer + k)->value1,
                (line_pointer + k)->value3,
                (line_pointer + k)->value2,
                (line_pointer + k)->char1);
        printf("\n");
        k++;
    }

    free(line_pointer);

    return EXIT_SUCCESS;
}
