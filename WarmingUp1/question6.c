#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#define SIZE 30
#define PATH 0
#define BACKGROUND 1
#define OBSTACLE 'X'
#define OBJECT '*'
#define EMPTY ' '

char board[SIZE][SIZE];
int playerX = -1, playerY = -1;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = BACKGROUND;
        }
    }
}

void placeObstacles() {
    int count = 0;
    while (count < 30) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == BACKGROUND) {
            board[x][y] = OBSTACLE;
            count++;
        }
    }
}

bool isValidMove(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] != OBSTACLE);
}

void drawBoard() {
    system("clear");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == PATH) {
                printf("\033[1;33m%d \033[0m", board[i][j]); // 노란색
            } else if (board[i][j] == BACKGROUND) {
                printf("%d ", board[i][j]);
            } else if (board[i][j] == OBSTACLE) {
                printf("\033[1;34mX \033[0m"); // 파란색
            } else if (board[i][j] == OBJECT) {
                printf("\033[1;31m* \033[0m"); // 빨간색
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void placePath() {
    // 경로 생성 로직 구현
    // (조건을 따르도록 작성)
    // 예시로 간단한 경로를 사용
    for (int i = 0; i < SIZE; i++) {
        board[i][0] = PATH;
    }
    for (int j = 0; j < SIZE; j++) {
        board[SIZE - 1][j] = PATH;
    }
}

void resetPath() {
    initializeBoard();
    placeObstacles();
    placePath();
}

void placeObject() {
    if (playerX == -1 && playerY == -1) {
        playerX = 0;
        playerY = 0;
        board[playerX][playerY] = OBJECT;
    }
}

void moveObject(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch (direction) {
        case 'w': newX--; break;
        case 'a': newY--; break;
        case 's': newX++; break;
        case 'd': newY++; break;
    }

    if (isValidMove(newX, newY) && board[newX][newY] == PATH) {
        board[playerX][playerY] = BACKGROUND; // 이전 위치 비우기
        playerX = newX;
        playerY = newY;
        board[playerX][playerY] = OBJECT; // 새로운 위치에 객체 배치
    }
}

int main() {
    srand(time(0));
    initializeBoard();
    placeObstacles();
    placePath();

    char command;
    while (true) {
        drawBoard();
        command = getch();

        if (command == 'r') {
            resetPath();
        } else if (command == 'e') {
            placeObject();
        } else if (command == 'w' || command == 'a' || command == 's' || command == 'd') {
            moveObject(command);
        } else if (command == 'q') {
            break;
        }
    }

    return 0;
}
