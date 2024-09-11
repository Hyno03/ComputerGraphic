//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <windows.h>
//
//#define RESET "\x1b[0m"
//#define RED "\x1b[31m"
//
//int main() {
//    FILE *file = fopen("data.txt", "r");
//
//    char line[256];
//    char order;
//    int orderCCount = 0, orderDCount = 0, orderECount = 0, orderFCount = 0, orderGCount = 0, orderHCount = 0, orderRCount = 0, orderSCount = 0;
//
//    while (1)
//    {
//        printf("\nInput Order\n");
//        scanf("  %c", &order);
//
//        //명령어 c
//        if(order == 'c')
//        {
//            orderCCount++;
//            fseek(file, 0, SEEK_SET);
//
//            //대문자로 시작하는 단어만 색 바꾸기
//            if(orderCCount == 1)
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char *token = strtok(line, " ");
//                    int firstWord = 1;
//                    while(token != NULL)
//                    {
//                        if(firstWord)
//                        {
//                            if(isupper(token[0]))
//                            {
//                                printf("%s%s%s",RED,token,RESET);
//                            }
//                            else
//                            {
//                                printf("%s",token);
//                            }
//                            firstWord = 0;
//                        }
//                        else
//                        {
//                            if(isupper(token[0]))
//                            {
//                                printf(" %s%s%s",RED,token,RESET);
//                            }
//                            else
//                            {
//                                printf(" %s",token);
//                            }
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//            }
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char *token = strtok(line, " ");
//                    int firstWord = 1;
//                    while(token != NULL)
//                    {
//                        if(firstWord)
//                        {
//                           printf("%s",token);
//                           firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s",token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderCCount = 0;
//            }
//        }
//        
//        //명령어 d
//        else if(order == 'd')
//        {
//            orderDCount++;
//            fseek(file, 0, SEEK_SET);
//
//            //문장 한 줄 전체 거꾸로 출력하기
//            if(orderDCount == 1)
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char *emptyToken[256];
//                    int count = 0;
//
//                    char *token = strtok(line, " ");
//                    while(token != NULL)
//                    {
//                        if(strlen(token) > 0)
//                        {
//                            emptyToken[count++] = token;
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                    for(int i = count - 1; i >= 0; i--)
//                    {
//                        int len = strlen(emptyToken[i]);
//                        for(int j = len; j >=0; j--)
//                        {
//                            printf("%c", emptyToken[i][j]);
//                        }
//                        printf(" ");
//                    }
//                }
//            }
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char *token = strtok(line, " ");
//                    int firstWord = 1;
//                    while(token != NULL)
//                    {
//                        if(firstWord)
//                        {
//                           printf("%s",token);
//                           firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s",token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderDCount = 0;
//            }
//        }
//
//        //명령어 e
//        if(order == 'e')
//        {
//            orderECount++;
//            fseek(file, 0, SEEK_SET);
//
//            //3문자 뒤에 @@ 붙이기
//            if(orderECount == 1)
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    int len = strlen(line);
//                    int count = 0;
//
//                    for(int i = 0 ; i < len; i++)
//                    {   
//                        printf("%c", line[i]);
//                        count++;
//                        if(line[i] == '\n')
//                        {
//                            count = 0;
//                        }
//                        if(count == 3)
//                        {
//                            printf("@@");
//                            count = 0;
//                        }
//                    }
//                }
//            }
//
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char *token = strtok(line, " ");
//                    int firstWord = 1;
//                    while(token != NULL)
//                    {
//                        if(firstWord)
//                        {
//                           printf("%s",token);
//                           firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s",token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderECount = 0;
//            }
//        }
//
//        //명령어 f
//        if(order == 'f')
//        {
//            orderFCount++;
//            fseek(file, 0, SEEK_SET);
//
//            //공백을 기준으로 단어 거꾸로 출력
//            if(orderFCount == 1)
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    line[strcspn(line, "\n")] = '\0';
//                    char *emptyToken[256];
//                    int count = 0;
//
//                    char *token = strtok(line, " ");
//                    while(token != NULL)
//                    {
//                        if(strlen(token) > 0)
//                        {
//                            emptyToken[count++] = token;
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                    for(int i = 0; i < count; i++)
//                    {
//                        int len = strlen(emptyToken[i]);
//                        for(int j = len - 1; j >= 0; j--)
//                        {
//                            printf("%c", emptyToken[i][j]);
//                        }
//                        printf(" ");
//                    }
//                    printf("\n");
//                }
//            }
//
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char *token = strtok(line, " ");
//                    int firstWord = 1;
//                    while(token != NULL)
//                    {
//                        if(firstWord)
//                        {
//                           printf("%s",token);
//                           firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s",token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderFCount = 0;
//            }
//        }
//
//        //명령어 g
//        if (order == 'g')
//        {
//            char orignalWord, changeWord;
//            orderGCount++;
//            fseek(file, 0, SEEK_SET);
//
//            //문자 내부의 특정 문자를 다른 문자로 바꾸기 (바꿀 문자와 입력할 문자 입력 받음)
//            if (orderGCount == 1)
//            {
//                //원래 텍스트 출력
//                while (fgets(line, sizeof(line), file))
//                {
//                    printf("%s", line);
//                }
//
//                //바뀔 문자와 바꿀 문자 입력 받기
//                printf("\nEnter the word orignal.");
//                scanf(" %c", &orignalWord);
//                printf("Enter the word to change.");
//                scanf(" %c", &changeWord);
//                
//                //변환 코드
//                fseek(file, 0, SEEK_SET);
//                while (fgets(line, sizeof(line), file))
//                {
//                    int firstword = 1, len = strlen(line);
//                    char tempToken[256];
//                    strcpy(tempToken, line);
//                    for (int i = 0; tempToken[i]; i++)
//                    {
//                        tempToken[i] = tolower(tempToken[i]);
//                    }
//                    for (int i = 0; i < len; i++)
//                    {
//                        if (tempToken[i] == orignalWord)
//                        {
//                            if (firstword)
//                            {
//                                printf("%c", changeWord);
//                                firstword = 0;
//                            }
//                            else
//                            {
//                                printf("%c", changeWord);
//                            }
//                        }
//                        else
//                        {
//                            if (firstword)
//                            {
//                                printf("%c", line[i]);
//                                firstword = 0;
//                            }
//                            else
//                            {
//                                printf("%c", line[i]);
//                            }
//                        }
//                    }
//                }
//            }
//
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char* token = strtok(line, " ");
//                    int firstWord = 1;
//                    while (token != NULL)
//                    {
//                        if (firstWord)
//                        {
//                            printf("%s", token);
//                            firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s", token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderGCount = 0;
//            }
//        }
//
//        //명령어 h
//        if (order == 'h')
//        {
//            orderHCount++;
//            fseek(file, 0, SEEK_SET);
//
//            //각 줄의 단어의 개수
//            if (orderHCount == 1)
//            {
//                 while (fgets(line, sizeof(line), file))
//                 {
//                     printf("%s",line);
//                     int wordCount = 0;
//                     char *token = strtok(line, " ");
//                     while(token != NULL)
//                     {
//                         wordCount++;
//                         token = strtok(NULL, " ");
//                     }
//                     printf(" = Word Count : %d\n", wordCount);
//                 }
//            }
//
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char* token = strtok(line, " ");
//                    int firstWord = 1;
//                    while (token != NULL)
//                    {
//                        if (firstWord)
//                        {
//                            printf("%s", token);
//                            firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s", token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderHCount = 0;
//            }
//        }
//
//        // 명령어 r
//        if (order == 'r')
//        {
//            orderRCount++;
//            fseek(file, 0, SEEK_SET);
//
//            char lines[100][256];
//            int wordCounts[100];
//            int lineCount = 0;
//
//            // 파일의 모든 줄을 읽고 단어 수를 세어서 저장
//            while (fgets(line, sizeof(line), file))
//            {
//                strcpy(lines[lineCount], line);
//
//                int wordCount = 0;
//                char* token = strtok(line, " ");
//                while (token != NULL)
//                {
//                    wordCount++;
//                    token = strtok(NULL, " ");
//                }
//                wordCounts[lineCount] = wordCount;
//                lineCount++;
//            }
//
//            // 오름차순으로 정렬
//            if (orderRCount == 1)
//            {
//                for (int i = 0; i < lineCount - 1; i++)
//                {
//                    for (int j = i + 1; j < lineCount; j++)
//                    {
//                        if (wordCounts[i] > wordCounts[j])
//                        {
//                            // 단어 수 교환
//                            int tempCount = wordCounts[i];
//                            wordCounts[i] = wordCounts[j];
//                            wordCounts[j] = tempCount;
//
//                            // 줄 교환
//                            char tempLine[256];
//                            strcpy(tempLine, lines[i]);
//                            strcpy(lines[i], lines[j]);
//                            strcpy(lines[j], tempLine);
//                        }
//                    }
//                }
//            }
//            // 내림차순으로 정렬
//            else if (orderRCount == 2)
//            {
//                for (int i = 0; i < lineCount - 1; i++)
//                {
//                    for (int j = i + 1; j < lineCount; j++)
//                    {
//                        if (wordCounts[i] < wordCounts[j])
//                        {
//                            // 단어 수 교환
//                            int tempCount = wordCounts[i];
//                            wordCounts[i] = wordCounts[j];
//                            wordCounts[j] = tempCount;
//
//                            // 줄 교환
//                            char tempLine[256];
//                            strcpy(tempLine, lines[i]);
//                            strcpy(lines[i], lines[j]);
//                            strcpy(lines[j], tempLine);
//                        }
//                    }
//                }
//            }
//
//            // 정렬된 결과 출력 (각 줄의 단어 수도 함께 출력)
//            for (int i = 0; i < lineCount; i++)
//            {
//                printf("%s", lines[i]);
//            }
//
//            // orderRCount를 초기화
//            if (orderRCount > 2)
//            {
//                orderRCount = 0;
//            }
//        }
//
//
//        //명령어 s
//        if (order == 's')
//        {
//            char changeWord[256];
//            orderSCount++;
//            fseek(file, 0, SEEK_SET);
//
//            //바꾸기로 입력한 단어 대소문자 구분 없이 색 바꾸기
//            if (orderSCount == 1)
//            {
//                //원래 텍스트 출력
//                while (fgets(line, sizeof(line), file))
//                {
//                    printf("%s", line);
//                }
//
//                //색을 바꿀 단어 입력
//                printf("\nEnter the word to change color ");
//                scanf("%s", changeWord);
//
//                fseek(file, 0, SEEK_SET);
//                //변환 코드
//                while (fgets(line, sizeof(line), file))
//                {
//                    char* token = strtok(line, " ");
//                    int firstWord = 1;
//                    while (token != NULL)
//                    {
//                        char tempToken[256], tempChangeWord[256];
//                        strcpy(tempToken, token);
//                        strcpy(tempChangeWord, changeWord);
//                        for (int i = 0; tempToken[i]; i++) tempToken[i] = tolower(tempToken[i]);
//                        for (int i = 0; tempChangeWord[i]; i++) tempChangeWord[i] = tolower(tempChangeWord[i]);
//
//                        if (strcmp(tempToken, tempChangeWord) == 0)
//                        {
//                            if (firstWord)
//                            {
//                                printf("%s%s",RED, token);
//                                firstWord = 0;
//                            }
//                            else
//                            {
//                                printf(" %s%s",RED, token);
//                            }
//                        }
//                        else
//                        {
//                            if (firstWord)
//                            {
//                                printf("%s%s",RESET, token);
//                                firstWord = 0;
//                            }
//                            else
//                            {
//                                printf(" %s%s",RESET, token);
//                            }
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//            }
//            //원래대로 출력
//            else
//            {
//                while (fgets(line, sizeof(line), file))
//                {
//                    char* token = strtok(line, " ");
//                    int firstWord = 1;
//                    while (token != NULL)
//                    {
//                        if (firstWord)
//                        {
//                            printf("%s", token);
//                            firstWord = 0;
//                        }
//                        else
//                        {
//                            printf(" %s", token);
//                        }
//                        token = strtok(NULL, " ");
//                    }
//                }
//                orderSCount = 0;
//            }
//        }
//
//
//        //명령어 q
//        else if(order == 'q')
//        {
//            fclose(file);
//            return 0;
//        }
//    }
//
//    return 0;
//}
