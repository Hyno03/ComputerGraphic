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
        printf("\nInput Order\n");
        scanf("  %c", &order);

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
                    int firstWord = 1;
                    while(token != NULL)
                    {
                        if(firstWord)
                        {
                            if(isupper(token[0]))
                            {
                                printf("%s%s%s",RED,token,RESET);
                            }
                            else
                            {
                                printf("%s",token);
                            }
                            firstWord = 0;
                        }
                        else
                        {
                            if(isupper(token[0]))
                            {
                                printf(" %s%s%s",RED,token,RESET);
                            }
                            else
                            {
                                printf(" %s",token);
                            }
                        }
                        token = strtok(NULL, " ");
                    }
                }
            }
            //원래대로 출력
            else
            {
                while (fgets(line, sizeof(line), file))
                {
                    char *token = strtok(line, " ");
                    int firstWord = 1;
                    while(token != NULL)
                    {
                        if(firstWord)
                        {
                           printf("%s",token);
                           firstWord = 0;
                        }
                        else
                        {
                            printf(" %s",token);
                        }
                        token = strtok(NULL, " ");
                    }
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
                    char *emptyToken[256];
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
                }
            }
            //원래대로 출력
            else
            {
                while (fgets(line, sizeof(line), file))
                {
                    char *token = strtok(line, " ");
                    int firstWord = 1;
                    while(token != NULL)
                    {
                        if(firstWord)
                        {
                           printf("%s",token);
                           firstWord = 0;
                        }
                        else
                        {
                            printf(" %s",token);
                        }
                        token = strtok(NULL, " ");
                    }
                }
                orderCCount = 0;
            }
        }

        //명령어 e
        if(order == 'e')
        {
            orderCCount++;
            fseek(file, 0, SEEK_SET);

            //3문자 뒤에 @@ 붙이기
            if(orderCCount == 1)
            {
                while (fgets(line, sizeof(line), file))
                {
                    int len = strlen(line);
                    int count = 0;

                    for(int i = 0 ; i < len; i++)
                    {   
                        printf("%c", line[i]);
                        count++;
                        if(line[i] == '\n')
                        {
                            count = 0;
                        }
                        if(count == 3)
                        {
                            printf("@@");
                            count = 0;
                        }
                    }
                }
            }

            //원래대로 출력
            else
            {
                while (fgets(line, sizeof(line), file))
                {
                    char *token = strtok(line, " ");
                    int firstWord = 1;
                    while(token != NULL)
                    {
                        if(firstWord)
                        {
                           printf("%s",token);
                           firstWord = 0;
                        }
                        else
                        {
                            printf(" %s",token);
                        }
                        token = strtok(NULL, " ");
                    }
                }
                orderCCount = 0;
            }
        }

        //명령어 q
        else if(order == 'q')
        {
            fclose(file);
            return 0;
        }
    }

    return 0;
}
