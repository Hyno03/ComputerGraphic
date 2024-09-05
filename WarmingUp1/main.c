#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //명령어 입력
    int a[4][4], b[4][4];
    int c[4][4] = { 0 }, d[4][4] = { 0 };
    char order;
    int inputE = 0;
    int i, j;
    int numof2A = 0, numof2B = 0;

    //두개의 배열 값 주기
    srand(time(NULL));
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            a[i][j] = rand() % 3;
            b[i][j] = rand() % 3;
            if (a[i][j] == 2)
            {
                numof2A++;
                if (numof2A > 2)
                {
                    a[i][j] = rand() % 2;
                }
            }
            if (b[i][j] == 2)
            {
                numof2B++;
                if (numof2B > 2)
                {
                    b[i][j] = rand() % 2;
                }
            }
        }
    }

    while(1)
    {
        printf("\n명령어를 입력하세요\n");
        scanf(" %c", &order);

        //첫번째 배열 값만 출력
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        //명령어 m
        if (order == 'm')
        {
            //두번째 배열 출력
            printf("   *\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //행렬의 곱셈 값
            int k;

            printf("   =\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    for (k = 0; k < 4; k++)
                    {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        //명령어 a
        if (order == 'a')
        {
            //두번째 배열 출력
            printf("   +\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //행렬의 덧셈 값
            printf("   =\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        //명령어 d
        if (order == 'd')
        {
            //두번째 배열 출력
            printf("   -\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //행렬의 뺄셈 값
            printf("   =\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    c[i][j] = a[i][j] - b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        //명령어 r (!!!!!!행렬식의 값에 대해 공부 후 하기!!!!!!!!!!!!)
        if (order == 'r')
        {
            //두번째 배열 출력
            printf("   *\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //행렬의 덧셈 값
            printf("   =\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        }

        //명령어 t
        if (order == 't')
        {
            //두번째 배열 출력
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //a의 전치 행렬 값
            printf("   =\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    c[i][j] = a[j][i];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }

            //b의 전치 행렬 값
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    d[i][j] = b[j][i];
                    printf("%d ", d[i][j]);
                }
                printf("\n");
            }
        }

        //명령어 e (아직 안함!!!!!!!!!!!!!!!!!!!!)
        if (order == 'e')
        {
            inputE += 1;
            //두번째 배열 출력
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            printf("   =\n");
            //행렬 짝수 출력
            if (inputE == 1)
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        if (a[i][j] == 1)
                        {
                            c[i][j] = 0;
                        }
                        else
                        {
                            c[i][j] = a[i][j];
                        }

                        if (b[i][j] == 1)
                        {
                            d[i][j] = 0;
                        }
                        else
                        {
                            d[i][j] = b[i][j];
                        }
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        printf("%d ", d[i][j]);
                    }
                    printf("\n");
                }
            }

            //행렬 홀수 출력
            if (inputE == 2)
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        if (a[i][j] == 2)
                        {
                            c[i][j] = 0;
                        }
                        else
                        {
                            c[i][j] = a[i][j];
                        }

                        if (b[i][j] == 2)
                        {
                            d[i][j] = 0;
                        }
                        else
                        {
                            d[i][j] = b[i][j];
                        }
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        printf("%d ", d[i][j]);
                    }
                    printf("\n");
                }
            }
            
            //원래 값 출력
            if (inputE == 3)
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        printf("%d ", a[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        printf("%d ", b[i][j]);
                    }
                    printf("\n");
                }
                inputE = 0;
            } 
        }

        //명령어 s
        if (order == 's')
        {
            //두번째 배열 출력
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //행렬 랜덤하게 재설정 후 첫번째 배열 출력
            srand(time(NULL));
            printf("   =\n");
            numof2A = 0, numof2B = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    a[i][j] = rand() % 3;
                    b[i][j] = rand() % 3;
                    if (a[i][j] == 2)
                    {
                        numof2A++;
                        if (numof2A > 2)
                        {
                            a[i][j] = rand() % 2;
                        }
                    }
                    if (b[i][j] == 2)
                    {
                        numof2B++;
                        if (numof2B > 2)
                        {
                            b[i][j] = rand() % 2;
                        }
                    }
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }

            //두번째 배열 출력
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }
        }

        //숫자 명령어
        if (isdigit(order))
        {
            //입력 받은 값 곱하기
            printf(" * %c =\n", order);
            int orderNum = order - '0';
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    c[i][j] = a[i][j] * orderNum;
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }

            //두번째 배열 출력
            printf("\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //두번째 배열 입력 받은 값 곱하기
            printf(" * %c =\n", order);
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    d[i][j] = b[i][j] * orderNum;
                    printf("%d ", d[i][j]);
                }
                printf("\n");
            }
        }

        //명령어 q
        if (order == 'q')
        {
            return 0;
        }
    }
    
    return 0;
}