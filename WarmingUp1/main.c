#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //��ɾ� �Է�
    int a[4][4], b[4][4];
    int c[4][4] = { 0 }, d[4][4] = { 0 };
    char order;
    int inputE = 0;
    int i, j;
    int numof2A = 0, numof2B = 0;

    //�ΰ��� �迭 �� �ֱ�
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
        printf("\n��ɾ �Է��ϼ���\n");
        scanf(" %c", &order);

        //ù��° �迭 ���� ���
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        //��ɾ� m
        if (order == 'm')
        {
            //�ι�° �迭 ���
            printf("   *\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //����� ���� ��
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

        //��ɾ� a
        if (order == 'a')
        {
            //�ι�° �迭 ���
            printf("   +\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //����� ���� ��
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

        //��ɾ� d
        if (order == 'd')
        {
            //�ι�° �迭 ���
            printf("   -\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //����� ���� ��
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

        //��ɾ� r (!!!!!!��Ľ��� ���� ���� ���� �� �ϱ�!!!!!!!!!!!!)
        if (order == 'r')
        {
            //�ι�° �迭 ���
            printf("   *\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //����� ���� ��
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

        //��ɾ� t
        if (order == 't')
        {
            //�ι�° �迭 ���
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //a�� ��ġ ��� ��
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

            //b�� ��ġ ��� ��
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

        //��ɾ� e (���� ����!!!!!!!!!!!!!!!!!!!!)
        if (order == 'e')
        {
            inputE += 1;
            //�ι�° �迭 ���
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
            //��� ¦�� ���
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

            //��� Ȧ�� ���
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
            
            //���� �� ���
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

        //��ɾ� s
        if (order == 's')
        {
            //�ι�° �迭 ���
            printf("   \n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //��� �����ϰ� �缳�� �� ù��° �迭 ���
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

            //�ι�° �迭 ���
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

        //���� ��ɾ�
        if (isdigit(order))
        {
            //�Է� ���� �� ���ϱ�
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

            //�ι�° �迭 ���
            printf("\n");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }

            //�ι�° �迭 �Է� ���� �� ���ϱ�
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

        //��ɾ� q
        if (order == 'q')
        {
            return 0;
        }
    }
    
    return 0;
}