//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define BOARD_SIZE 30
//
//char board[BOARD_SIZE][BOARD_SIZE];
//
//// 사각형 구조체
//typedef struct {
//    int x1, y1;
//    int x2, y2;
//} Rectangle;
//
//// 보드 초기화
//void initBoard() {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            board[i][j] = '.';
//        }
//    }
//}
//
//// 보드에 사각형을 그리기
//void drawRectangle(Rectangle rect) {
//    // 사각형이 보드 밖으로 넘어가는 부분을 계산하여 반대편에 나타나게 함
//    for (int i = rect.y1; i <= rect.y2; i++) {
//        for (int j = rect.x1; j <= rect.x2; j++) {
//            // 보드 경계를 넘어가는 경우 처리
//            int x = (j + BOARD_SIZE) % BOARD_SIZE;
//            int y = (i + BOARD_SIZE) % BOARD_SIZE;
//            board[y][x] = '#';
//        }
//    }
//}
//
//// 보드 출력
//void printBoard() {
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            printf("%c ", board[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// 사각형 이동
//void moveRectangle(Rectangle *rect, char command) {
//    switch (command) {
//        case 'x':  // x축 우측으로 한 칸 이동
//            rect->x1++;
//            rect->x2++;
//            break;
//        case 'X':  // x축 좌측으로 한 칸 이동
//            rect->x1--;
//            rect->x2--;
//            break;
//        case 'y':  // y축 아래로 한 칸 이동
//            rect->y1++;
//            rect->y2++;
//            break;
//        case 'Y':  // y축 위로 한 칸 이동
//            rect->y1--;
//            rect->y2--;
//            break;
//        case 's':  // 사각형 크기 축소
//            if (rect->x2 > rect->x1) rect->x2--;
//            if (rect->y2 > rect->y1) rect->y2--;
//            break;
//        case 'S':  // 사각형 크기 확대
//            if (rect->x2 < BOARD_SIZE - 1) rect->x2++;
//            if (rect->y2 < BOARD_SIZE - 1) rect->y2++;
//            break;
//        case 'i':  // x축 한 칸 축소
//            if (rect->x2 > rect->x1) rect->x2--;
//            break;
//        case 'I':  // x축 한 칸 확대
//            if (rect->x2 < BOARD_SIZE - 1) rect->x2++;
//            break;
//        case 'j':  // y축 한 칸 축소
//            if (rect->y2 > rect->y1) rect->y2--;
//            break;
//        case 'J':  // y축 한 칸 확대
//            if (rect->y2 < BOARD_SIZE - 1) rect->y2++;
//            break;
//        case 'a':  // x축 확대, y축 축소
//            if (rect->x2 < BOARD_SIZE - 1) rect->x2++;
//            if (rect->y2 > rect->y1) rect->y2--;
//            break;
//        case 'A':  // x축 축소, y축 확대
//            if (rect->x2 > rect->x1) rect->x2--;
//            if (rect->y2 < BOARD_SIZE - 1) rect->y2++;
//            break;
//        case 'm':  // 사각형 면적 출력
//            printf("사각형의 면적: %d\n", (rect->x2 - rect->x1 + 1) * (rect->y2 - rect->y1 + 1));
//            break;
//        case 'n':  // 전체 면적 대비 사각형 면적 비율 출력
//            printf("사각형 면적 비율: %.2f%%\n", ((rect->x2 - rect->x1 + 1) * (rect->y2 - rect->y1 + 1)) / (float)(BOARD_SIZE * BOARD_SIZE) * 100);
//            break;
//    }
//}
//
//// 프로그램 실행
//int main() {
//    Rectangle rect;
//    char command;
//
//    while (1) {
//        printf("사각형의 좌표를 입력하세요 (x1, y1, x2, y2): ");
//        scanf("%d %d %d %d", &rect.x1, &rect.y1, &rect.x2, &rect.y2);
//
//        while (1) {
//            initBoard();               // 보드를 초기화하고
//            drawRectangle(rect);       // 사각형을 그린 후
//            printBoard();              // 보드를 출력
//
//            printf("명령어를 입력하세요: ");
//            scanf(" %c", &command);
//
//            if (command == 'q') {
//                printf("프로그램 종료\n");
//                return 0;
//            } else if (command == 'r') {
//                printf("보드 리셋\n");
//                break;
//            }
//
//            moveRectangle(&rect, command);  // 명령어에 따라 사각형 이동 및 크기 조정
//        }
//    }
//
//    return 0;
//}
