#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TURNS 5
#define MATCH_SCORE 5

char board[SIZE][SIZE];
char display[SIZE][SIZE];
int score = 0;
int turns = TURNS;

// 문자 배열 초기화
void initializeBoard() {
    char cards[] = "AABBCCDDEEFFGGHHIIJJKKLL@"; // 12개의 문자와 조커 포함
    int len = SIZE * SIZE;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            board[i][j] = 0;
            display[i][j] = '*'; // 모든 칸을 '*'로 표시
        }
    }
    
    srand(time(NULL)); // 난수 생성기 초기화
    
    // 보드에 무작위 배치
    for (int i = 0; i < len; i++) {
        int r, c;
        do {
            r = rand() % SIZE;
            c = rand() % SIZE;
        } while (board[r][c] != 0); // 빈 칸 찾기
        board[r][c] = cards[i]; // 무작위로 카드 배치
    }
}

// 보드 출력 함수
void printBoard() {
    printf("  a b c d e\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

// 조커와 매칭된 카드의 위치 찾기
void revealMatchingCard(char card) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == card && display[i][j] == '*') {
                display[i][j] = card; // 매칭된 카드 위치도 보이게 함
                return; // 매칭된 첫 번째 위치만 표시
            }
        }
    }
}

// 좌표를 입력받아 카드 선택
void selectCard(int row1, int col1, int row2, int col2) {
    char card1 = board[row1][col1];
    char card2 = board[row2][col2];
    display[row1][col1] = card1;
    display[row2][col2] = card2;
    printBoard();
    
    if (card1 == '@') { // 조커가 첫 번째로 선택된 경우
        printf("Joker selected! Revealing matching card...\n");
        revealMatchingCard(card2); // card2와 매칭되는 다른 카드의 위치를 표시
    } else if (card2 == '@') { // 조커가 두 번째로 선택된 경우
        printf("Joker selected! Revealing matching card...\n");
        revealMatchingCard(card1); // card1과 매칭되는 다른 카드의 위치를 표시
    }

    if (card1 == card2 || card1 == '@' || card2 == '@') {
        printf("Matched!\n");
        score += MATCH_SCORE;
    } else {
        printf("Not matched!\n");
        display[row1][col1] = '*';
        display[row2][col2] = '*';
    }
}

// 게임 리셋
void resetGame() {
    score = 0;
    turns = TURNS;
}

int main() {
    int row1, col1, row2, col2;
    char colChar1, colChar2, command;
    initializeBoard();

    while (turns > 0) {
        printBoard();
        printf("Select two cards (e.g., a1 e3) or 'r' to reset: ");
        
        // 먼저 한 문자를 입력받음
        scanf(" %c", &command);

        // 명령어 'r'을 입력 받으면 게임 리셋
        if (command == 'r') {
            score = 0;
            turns = TURNS;
            initializeBoard();
            printf("Game reset!\n");
            continue;
        }
        else if(command == 'q')
        {
            printf("Ouit Game\n");
            return 0;
        }
        
        // 명령어가 아니라면 좌표 입력 처리
        colChar1 = command;
        scanf(" %d %c%d", &row1, &colChar2, &row2);
        
        // 입력받은 열을 숫자로 변환 (a=0, b=1, ..., e=4)
        col1 = colChar1 - 'a';
        col2 = colChar2 - 'a';

        // 행 번호는 1부터 시작하므로 0 기반 인덱스로 변경
        row1--; 
        row2--;

        // 카드 선택
        selectCard(row1, col1, row2, col2);
        turns--;
    }

    printf("Game over! Total score: %d\n", score);
    return 0;
}
