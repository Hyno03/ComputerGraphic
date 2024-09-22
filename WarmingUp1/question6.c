#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define SIZE 30
#define PATH 0
#define BACKGROUND 1
#define OBSTACLE 'X'
#define PLAYER '*'

int board[SIZE][SIZE];
int player_x = -1, player_y = -1;  // 플레이어 위치 (-1은 아직 생성되지 않았음을 의미)
int has_player = 0;

// 경로와 장애물 초기화 함수
void init_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = BACKGROUND;
        }
    }
    // 장애물 배치
    int obstacles = 30;
    while (obstacles > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == BACKGROUND) {
            board[x][y] = OBSTACLE;
            obstacles--;
        }
    }
}

// 경로 생성 함수 (조건에 맞는 경로)
void generate_path() {
    int x = 0, y = 0, steps = 0, direction = rand() % 4;
    while (x != SIZE - 1 || y != SIZE - 1) {
        if (steps == 5 || board[x][y] == OBSTACLE) {
            direction = (direction + rand() % 3 + 1) % 4;  // 다른 방향으로 전환
            steps = 0;
        }

        board[x][y] = PATH;  // 경로 표시
        steps++;

        // 경로 방향에 따른 이동
        if (direction == 0 && x > 0) x--;         // 위쪽
        else if (direction == 1 && x < SIZE - 1) x++;  // 아래쪽
        else if (direction == 2 && y > 0) y--;    // 왼쪽
        else if (direction == 3 && y < SIZE - 1) y++;  // 오른쪽
    }
    board[SIZE - 1][SIZE - 1] = PATH;  // 마지막 지점도 경로로 설정
}

// 보드 출력 함수
void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player_x && j == player_y) {
                printf("\033[1;31m%c \033[0m", PLAYER);  // 빨강색 플레이어
            }
            else if (i == SIZE - 1 && j == SIZE - 1) {
                printf("\033[1;35m* \033[0m");  // 보라색 맨 마지막 지점
            }
            else if (board[i][j] == PATH) {
                printf("\033[1;33m0 \033[0m");  // 노란색 경로
            }
            else if (board[i][j] == OBSTACLE) {
                printf("\033[1;34mX \033[0m");  // 파란색 장애물
            }
            else {
                printf("1 ");
            }
        }
        printf("\n");
    }
}

// 플레이어 이동 함수
void move_player(char direction) {
    int new_x = player_x, new_y = player_y;

    if (direction == 'w' && player_x > 0) new_x--;      // 위쪽
    if (direction == 's' && player_x < SIZE - 1) new_x++;  // 아래쪽
    if (direction == 'a' && player_y > 0) new_y--;      // 왼쪽
    if (direction == 'd' && player_y < SIZE - 1) new_y++;  // 오른쪽

    if (board[new_x][new_y] == PATH) {
        player_x = new_x;
        player_y = new_y;
    }
}

int main() {
    srand(time(NULL));
    char command;

    init_board();
    generate_path();

    while (1) {
        system("cls");  // 화면 클리어
        print_board();
        printf("명령어 입력하세요 (r: 초기화, e: 시작, w/a/s/d: 이동, q: 종료): ");
        scanf(" %c", &command);  // 명령어 입력 (앞의 공백으로 버퍼 문제 해결)

        if (command == 'q') break;
        if (command == 'r') {
            init_board();
            generate_path();
            has_player = 0;  // 플레이어 삭제
        }
        if (command == 'e' && !has_player) {
            player_x = 0;
            player_y = 0;
            has_player = 1;
        }
        if (has_player && (command == 'w' || command == 'a' || command == 's' || command == 'd')) {
            move_player(command);
        }
    }

    return 0;
}
