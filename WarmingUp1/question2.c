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
                                printf("%s",token);
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

        //명령어 f
        if(order == 'f')
        {
            orderCCount++;
            fseek(file, 0, SEEK_SET);

            //공백을 기준으로 단어 거꾸로 출력
            if(orderCCount == 1)
            {
                while (fgets(line, sizeof(line), file))
                {
                    line[strcspn(line, "\n")] = '\0';
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
                    for(int i = 0; i < count; i++)
                    {
                        int len = strlen(emptyToken[i]);
                        for(int j = len - 1; j >= 0; j--)
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

        //명령어 g
        if (order == 'g')
        {
            char orignalWord[256], changeWord[256];
            orderCCount++;
            fseek(file, 0, SEEK_SET);

            ////문자 내부의 특정 문자를 다른 문자로 바꾸기 (바꿀 문자와 입력할 문자 입력 받음)
            if (orderCCount == 1)
            {
                //원래 텍스트 출력
                while (fgets(line, sizeof(line), file))
                {
                    printf("%s", line);
                }

                //원래 단어와 바꿀 단어 입력 받기
                printf("\nEnter the word orignal.");
                scanf(" %s", &orignalWord);
                printf("Enter the word to change.");
                scanf(" %s", &changeWord);
                
                //변환 코드
                fseek(file, 0, SEEK_SET);
                while (fgets(line, sizeof(line), file))
                {
                    int firstword = 1;
                    char* token = strtok(line, " ");
                    while (token != NULL)
                    {
                        if (strcmp(token, orignalWord) == 0)
                        {
                            if (firstword)
                            {
                                printf("%s", changeWord);
                                firstword = 0;
                            }
                            else
                            {
                                printf(" %s", changeWord);
                            }
                        }
                        else
                        {
                            if (firstword)
                            {
                                printf("%s", token);
                                firstword = 0;
                            }
                            else
                            {
                                printf(" %s", token);
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
                    char* token = strtok(line, " ");
                    int firstWord = 1;
                    while (token != NULL)
                    {
                        if (firstWord)
                        {
                            printf("%s", token);
                            firstWord = 0;
                        }
                        else
                        {
                            printf(" %s", token);
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
