#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("data.txt", "r");;

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s",line);
        int wordCount = 0;
        char *token = strtok(line, " ");
        while(token != NULL)
        {
            wordCount++;
            token = strtok(NULL, " ");
        }
        printf(" = Word Count : %d\n", wordCount);
    }

    fclose(file);

    return 0;
}
