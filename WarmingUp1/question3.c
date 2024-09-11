#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 20

// 점 구조체 정의
typedef struct {
    int x;
    int y;
    int z;
} Point;

// 점 리스트 구조체 정의
typedef struct {
    Point points[MAX_POINTS];
    int size;
} PointList;

Point original[MAX_POINTS];  // 원래 인덱스를 저장하는 배열
int sortAFlag = 0;           // 오름차순 정렬 여부를 관리하는 플래그 (1 = 정렬됨, 2 = 원래 상태로 복원)
int sortSFlag = 0;           // 내림차순 정렬 여부를 관리하는 플래그 (1 = 정렬됨, 2 = 원래 상태로 복원)

// 함수 선언
void initPointList(PointList* list);
void addPointAtTop(PointList* list, int x, int y, int z);
void addPointAtBottom(PointList* list, int x, int y, int z);
void removePointAtTop(PointList* list);
void removePointAtBottom(PointList* list);
void printPoints(const PointList* list);
void clearPoints(PointList* list);
int countPoints(const PointList* list);
void findFurthestPoint(const PointList* list);
void findClosestPoint(const PointList* list);
double calculateDistance(int x, int y, int z);
void sortPointsByDistance(PointList* list, int ascending);
void restoreOriginalOrder(PointList* list);

int main() {
    PointList list;
    initPointList(&list);

    char command;
    int x, y, z;

    while (1) {
        printf("\n명령어 입력: ");
        scanf(" %c", &command);  // 공백 추가로 버퍼 문제 방지

        if (command == '+') {
            if (list.size >= MAX_POINTS) {
                printf("점 데이터가 가득 찼습니다.\n");
                continue;
            }
            printf("x, y, z 값을 입력하세요: ");
            scanf("%d %d %d", &x, &y, &z);
            addPointAtTop(&list, x, y, z);
        }
        else if (command == 'e') {
            if (list.size >= MAX_POINTS) {
                printf("점 데이터가 가득 찼습니다.\n");
                continue;
            }
            printf("x, y, z 값을 입력하세요: ");
            scanf("%d %d %d", &x, &y, &z);
            addPointAtBottom(&list, x, y, z);
        }
        else if (command == '-') {
            if (list.size == 0) {
                printf("삭제할 점이 없습니다.\n");
            }
            else {
                removePointAtTop(&list);
            }
        }
        else if (command == 'd') {
            if (list.size == 0) {
                printf("삭제할 점이 없습니다.\n");
            }
            else {
                removePointAtBottom(&list);
            }
        }
        else if (command == 'l') {
            printf("리스트에 저장된 점의 개수: %d\n", countPoints(&list));
        }
        else if (command == 'c') {
            clearPoints(&list);
            printf("리스트가 초기화되었습니다.\n");
            printPoints(&list);  // 명령어 c 후 리스트 출력
        }
        else if (command == 'm') {
            findFurthestPoint(&list);
        }
        else if (command == 'n') {
            findClosestPoint(&list);
        }
        else if (command == 'a') {
            if (sortAFlag == 1) {
                restoreOriginalOrder(&list);
                sortAFlag = 0;
                printf("리스트가 원래 순서로 복원되었습니다.\n");
            }
            else {
                sortPointsByDistance(&list, 1); // 오름차순 정렬
                sortAFlag = 1;
                sortSFlag = 0;  // 's'를 눌렀다가 다시 'a'를 누르면 복원 없이 정렬
            }
        }
        else if (command == 's') {
            if (sortSFlag == 1) {
                restoreOriginalOrder(&list);
                sortSFlag = 0;
                printf("리스트가 원래 순서로 복원되었습니다.\n");
            }
            else {
                sortPointsByDistance(&list, 0); // 내림차순 정렬
                sortSFlag = 1;
                sortAFlag = 0;  // 'a'를 눌렀다가 다시 's'를 누르면 복원 없이 정렬
            }
        }
        else if (command == 'q') {
            printf("프로그램 종료.\n");
            break;
        }
        else {
            printf("잘못된 명령어입니다.\n");
        }

        // 'l', 'm', 'n' 명령어는 전체 리스트를 출력하지 않음
        if (command != 'l' && command != 'm' && command != 'n') {
            printPoints(&list);  // 명령어 완료 후 전체 리스트 출력
        }
    }

    return 0;
}

// 점 리스트 초기화
void initPointList(PointList* list) {
    list->size = 0;
    for (int i = 0; i < MAX_POINTS; i++) {
        list->points[i].x = 0;
        list->points[i].y = 0;
        list->points[i].z = 0;
        original[i] = list->points[i];  // 원래 인덱스에 초기값 저장
    }
}

// 맨 위에 점 추가 (위로 쌓이게)
void addPointAtTop(PointList* list, int x, int y, int z) {
    for (int i = list->size; i > 0; i--) {
        list->points[i] = list->points[i - 1];
    }
    list->points[0].x = x;
    list->points[0].y = y;
    list->points[0].z = z;
    list->size++;
    printf("맨 위에 (x: %d, y: %d, z: %d) 추가됨.\n", x, y, z);
    for (int i = 0; i < list->size; i++) {
        original[i] = list->points[i];  // 추가 시 원래 인덱스 갱신
    }
}

// 맨 아래에 점 추가
void addPointAtBottom(PointList* list, int x, int y, int z) {
    list->points[list->size].x = x;
    list->points[list->size].y = y;
    list->points[list->size].z = z;
    list->size++;
    printf("맨 아래에 (x: %d, y: %d, z: %d) 추가됨.\n", x, y, z);
    for (int i = 0; i < list->size; i++) {
        original[i] = list->points[i];  // 추가 시 원래 인덱스 갱신
    }
}

// 맨 위에 있는 점 삭제 (빈 자리 유지)
void removePointAtTop(PointList* list) {
    list->points[0].x = NULL;
    list->points[0].y = NULL;
    list->points[0].z = NULL;
    printf("맨 위의 점 삭제됨.\n");
    // 크기 줄이지 않음, 대신 빈 자리만 남김
}

// 맨 아래에 있는 점 삭제
void removePointAtBottom(PointList* list) {
    list->points[list->size - 1].x = 0;
    list->points[list->size - 1].y = 0;
    list->points[list->size - 1].z = 0;
    list->size--;
    printf("맨 아래의 점 삭제됨.\n");
}

// 리스트 전체 출력
void printPoints(const PointList* list) {
    printf("\n현재 리스트 상태:\n");
    for (int i = 0; i < MAX_POINTS; i++) {
        if (i < list->size && (list->points[i].x != NULL || list->points[i].y != NULL || list->points[i].z != NULL)) {
            printf("인덱스 %d: (x: %d, y: %d, z: %d)\n", i, list->points[i].x, list->points[i].y, list->points[i].z);
        }
        else {
            printf("인덱스 %d: 비어있음\n", i);
        }
    }
}

// 리스트 비우기
void clearPoints(PointList* list) {
    list->size = 0;
    for (int i = 0; i < MAX_POINTS; i++) {
        original[i].x = original[i].y = original[i].z = 0;
    }
}

// 리스트의 점 개수 반환
int countPoints(const PointList* list) {
    for (int i = 0; i < MAX_POINTS; i++) {
        if (list->points[i].x == NULL || list->points[i].y == NULL || list->points[i].z == NULL) {
            return list->size - 1;
        }
        else
        {
            return list->size;
        }
    }
}

// 원점에서 가장 먼 점 찾기
void findFurthestPoint(const PointList* list) {
    if (list->size == 0) {
        printf("점 데이터가 없습니다.\n");
        return;
    }

    int furthestIndex = 0;
    double maxDistance = calculateDistance(list->points[0].x, list->points[0].y, list->points[0].z);

    for (int i = 1; i < list->size; i++) {
        double distance = calculateDistance(list->points[i].x, list->points[i].y, list->points[i].z);
        if (distance > maxDistance) {
            maxDistance = distance;
            furthestIndex = i;
        }
    }

    printf("가장 먼 점: (x: %d, y: %d, z: %d)\n", list->points[furthestIndex].x, list->points[furthestIndex].y, list->points[furthestIndex].z);
}

// 원점에서 가장 가까운 점 찾기
void findClosestPoint(const PointList* list) {
    if (list->size == 0) {
        printf("점 데이터가 없습니다.\n");
        return;
    }

    int closestIndex = 0;
    double minDistance = calculateDistance(list->points[0].x, list->points[0].y, list->points[0].z);

    for (int i = 1; i < list->size; i++) {
        double distance = calculateDistance(list->points[i].x, list->points[i].y, list->points[i].z);
        if (distance < minDistance) {
            minDistance = distance;
            closestIndex = i;
        }
    }

    printf("가장 가까운 점: (x: %d, y: %d, z: %d)\n", list->points[closestIndex].x, list->points[closestIndex].y, list->points[closestIndex].z);
}

// 원점으로부터의 거리 계산
double calculateDistance(int x, int y, int z) {
    return sqrt(x * x + y * y + z * z);
}

// 거리 기준으로 정렬 (ascending = 1: 오름차순, ascending = 0: 내림차순)
void sortPointsByDistance(PointList* list, int ascending) {
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = i + 1; j < list->size; j++) {
            double dist1 = calculateDistance(list->points[i].x, list->points[i].y, list->points[i].z);
            double dist2 = calculateDistance(list->points[j].x, list->points[j].y, list->points[j].z);

            if ((ascending && dist1 > dist2) || (!ascending && dist1 < dist2)) {
                Point temp = list->points[i];
                list->points[i] = list->points[j];
                list->points[j] = temp;
            }
        }
    }

    printf("리스트가 %s으로 정렬되었습니다.\n", ascending ? "오름차순" : "내림차순");
}

// 원래 순서로 복원
void restoreOriginalOrder(PointList* list) {
    for (int i = 0; i < MAX_POINTS; i++) {
        if (i < list->size && (list->points[i].x != NULL || list->points[i].y != NULL || list->points[i].z != NULL)) {
            printf("인덱스 %d: (x: %d, y: %d, z: %d)\n", i, list->points[i].x, list->points[i].y, list->points[i].z);
        }
        else {
            printf("인덱스 %d: 비어있음\n", i);
        }
    }
}
