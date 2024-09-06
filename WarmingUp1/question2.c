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
    int orderCCount = 0;
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

        //명령어 c
        if(order == 'c')
        {
            orderCCount++;
            fseek(file, 0, SEEK_SET);

            //대문자로 시작하는 단어만 색 바꾸기
            if(orderCCount == 1)
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
            //원래대로 출력
            else
            {
                while (fgets(line, sizeof(line), file))
                {
                    char *token = strtok(line, " ");
                    while(token != NULL)
                    {
                        printf("%s%s ",RESET,token);
                        token = strtok(NULL, " ");
                    }
                    printf("\n");
                }
                orderCCount = 0;
            }
        }
        
        //명령어 d
        else if(order == 'd')
        {
            orderCCount++;
            fseek(file, 0, SEEK_SET);

            //문장 한 줄 전체 거꾸로 출력하기
            if(orderCCount == 1)
            {
                while (fgets(line, sizeof(line), file))
                {
                    char *emptyToken[128];
                    int count = 0;

                    char *token = strtok(line, " ");
                    while(token != NULL)
                    {
                        if(strlen(token) > 0)
                        {
                            emptyToken[count++] = token;
                        }
                        token = strtok(NULL, " ");
                    }
                    for(int i = count - 1; i >= 0; i--)
                    {
                        int len = strlen(emptyToken[i]);
                        for(int j = len; j >=0; j--)
                        {
                            printf("%c", emptyToken[i][j]);
                        }
                        printf(" ");
                    }
                    printf("\n");
                }
            }
            //원래대로 출력
            else
            {
                while (fgets(line, sizeof(line), file))
                {
                    char *token = strtok(line, " ");
                    while(token != NULL)
                    {
                        printf("%s ", token);
                        token = strtok(NULL, " ");
                    }
                    printf("\n");
                }
                orderCCount = 0;
            }
        }

        //명령어 e
        if(order == 'e')
        {
                
        }

        //명령어 q
        else if(order == 'q')
        {
            fclose(file);
            return 0;
        }

        //지정된 명령어를 입력하지 않았을 때
        else
        {
            printf("No Order Exist.");
        }
    }
    
    // fclose(file);

    return 0;
}
