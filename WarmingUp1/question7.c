#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 30

char board[BOARD_SIZE][BOARD_SIZE];

// 사각형 구조체
typedef struct {
   int x1, y1;
   int x2, y2;
} Rectangle;

// 보드 초기화
void initBoard() {
   for (int i = 0; i < BOARD_SIZE; i++) {
       for (int j = 0; j < BOARD_SIZE; j++) {
           board[i][j] = '.';
       }
   }
}

// 보드에 사각형을 그리기
void drawRectangle(Rectangle rect, char symbol) {
   for (int i = rect.y1; i <= rect.y2; i++) {
       for (int j = rect.x1; j <= rect.x2; j++) {
           // 보드 경계를 넘어가는 경우 처리
           int x = (j + BOARD_SIZE) % BOARD_SIZE;
           int y = (i + BOARD_SIZE) % BOARD_SIZE;

           // 충돌 처리
           if (board[y][x] != '.' && board[y][x] != symbol) {
               board[y][x] = '#'; // 겹치는 부분을 빨강색 #으로 표시
           } else {
               board[y][x] = symbol;
           }
       }
   }
}

// 보드 출력 (색상 적용)
void printBoard() {
   for (int i = 0; i < BOARD_SIZE; i++) {
       for (int j = 0; j < BOARD_SIZE; j++) {
           if (board[i][j] == '#') {
               printf("\033[31m%c \033[0m", board[i][j]); // 빨강색으로 출력
           } else {
               printf("%c ", board[i][j]);
           }
       }
       printf("\n");
   }
}

// 사각형 이동 및 크기 조정
void moveResizeRectangles(Rectangle *rect1, Rectangle *rect2, char command) {
   switch (command) {
       case 'x':  // 첫 번째 도형 x축 우측 이동
           rect1->x1++;
           rect1->x2++;
           break;
       case 'X':  // 첫 번째 도형 x축 좌측 이동
           rect1->x1--;
           rect1->x2--;
           break;
       case 'y':  // 첫 번째 도형 y축 아래 이동
           rect1->y1++;
           rect1->y2++;
           break;
       case 'Y':  // 첫 번째 도형 y축 위로 이동
           rect1->y1--;
           rect1->y2--;
           break;
       case 's':  // 첫 번째 도형 축소
           if (rect1->x2 > rect1->x1) rect1->x2--;
           if (rect1->y2 > rect1->y1) rect1->y2--;
           break;
       case 'S':  // 첫 번째 도형 확대
           if (rect1->x2 < BOARD_SIZE - 1) rect1->x2++;
           if (rect1->y2 < BOARD_SIZE - 1) rect1->y2++;
           break;

       case 'w':  // 두 번째 도형 x축 우측 이동
           rect2->x1++;
           rect2->x2++;
           break;
       case 'W':  // 두 번째 도형 x축 좌측 이동
           rect2->x1--;
           rect2->x2--;
           break;
       case 'a':  // 두 번째 도형 y축 아래 이동
           rect2->y1++;
           rect2->y2++;
           break;
       case 'A':  // 두 번째 도형 y축 위로 이동
           rect2->y1--;
           rect2->y2--;
           break;
       case 'd':  // 두 번째 도형 축소
           if (rect2->x2 > rect2->x1) rect2->x2--;
           if (rect2->y2 > rect2->y1) rect2->y2--;
           break;
       case 'D':  // 두 번째 도형 확대
           if (rect2->x2 < BOARD_SIZE - 1) rect2->x2++;
           if (rect2->y2 < BOARD_SIZE - 1) rect2->y2++;
           break;
   }
}

// 프로그램 실행
int main() {
   Rectangle rect1, rect2;
   char command;

   // 첫 번째 사각형 좌표 입력
   printf("첫 번째 사각형의 좌표를 입력하세요 (x1, y1, x2, y2): ");
   scanf("%d %d %d %d", &rect1.x1, &rect1.y1, &rect1.x2, &rect1.y2);

   // 두 번째 사각형 좌표 입력
   printf("두 번째 사각형의 좌표를 입력하세요 (x1, y1, x2, y2): ");
   scanf("%d %d %d %d", &rect2.x1, &rect2.y1, &rect2.x2, &rect2.y2);

   while (1) {
       initBoard();                // 보드를 초기화하고
       drawRectangle(rect1, '0'); // 첫 번째 사각형을 그리고
       drawRectangle(rect2, 'X'); // 두 번째 사각형을 그린 후
       printBoard();               // 보드를 출력

       printf("명령어를 입력하세요: ");
       scanf(" %c", &command);

       if (command == 'q') {
           printf("프로그램 종료\n");
           return 0;
       } else if (command == 'r') {
           printf("보드 리셋\n");
           // 사각형 좌표 재입력
           printf("첫 번째 사각형의 좌표를 입력하세요 (x1, y1, x2, y2): ");
           scanf("%d %d %d %d", &rect1.x1, &rect1.y1, &rect1.x2, &rect1.y2);
           printf("두 번째 사각형의 좌표를 입력하세요 (x1, y1, x2, y2): ");
           scanf("%d %d %d %d", &rect2.x1, &rect2.y1, &rect2.x2, &rect2.y2);
           continue;
       }

       moveResizeRectangles(&rect1, &rect2, command);  // 명령어에 따라 사각형 이동 및 크기 조정
   }

   return 0;
}
