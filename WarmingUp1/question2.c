#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define RESET "\x1b[0m"
#define RED "\x1b[31m"

int main() {
    FILE *file = fopen("data.txt", "r");

    char line[256];
    char order;
    // while (fgets(line, sizeof(line), file))
    // {
    //     printf("%s",line);
    //     int wordCount = 0;
    //     char *token = strtok(line, " ");
    //     while(token != NULL)
    //     {
    //         wordCount++;
    //         token = strtok(NULL, " ");
    //     }
    //     printf(" = Word Count : %d\n", wordCount);
    // }

    while (1)
    {
        printf("Input Order\n");
        scanf(" %c", &order);

        if(order == 'c')
        {
            while (fgets(line, sizeof(line), file))
            {

                char *token = strtok(line, " ");
                while(token != NULL)
                {
                    if(isupper(token[0]))
                    {
                        printf("%s%s%s ",RED,token,RESET);
                    }
                    else
                    {
                        printf("%s ",token);
                    }
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
        }

        else if(order == 'q')
        {
            fclose(file);
            return 0;
        }

        else
        {
            printf("No Order Exist.");
        }
    }
    
    // fclose(file);

    return 0;
}
