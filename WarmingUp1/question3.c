#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 20

// �� ����ü ����
typedef struct {
    int x;
    int y;
    int z;
} Point;

// �� ����Ʈ ����ü ����
typedef struct {
    Point points[MAX_POINTS];
    int size;
} PointList;

Point original[MAX_POINTS];  // ���� �ε����� �����ϴ� �迭
int sortAFlag = 0;           // �������� ���� ���θ� �����ϴ� �÷��� (1 = ���ĵ�, 2 = ���� ���·� ����)
int sortSFlag = 0;           // �������� ���� ���θ� �����ϴ� �÷��� (1 = ���ĵ�, 2 = ���� ���·� ����)

// �Լ� ����
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
        printf("\n��ɾ� �Է�: ");
        scanf(" %c", &command);  // ���� �߰��� ���� ���� ����

        if (command == '+') {
            if (list.size >= MAX_POINTS) {
                printf("�� �����Ͱ� ���� á���ϴ�.\n");
                continue;
            }
            printf("x, y, z ���� �Է��ϼ���: ");
            scanf("%d %d %d", &x, &y, &z);
            addPointAtTop(&list, x, y, z);
        }
        else if (command == 'e') {
            if (list.size >= MAX_POINTS) {
                printf("�� �����Ͱ� ���� á���ϴ�.\n");
                continue;
            }
            printf("x, y, z ���� �Է��ϼ���: ");
            scanf("%d %d %d", &x, &y, &z);
            addPointAtBottom(&list, x, y, z);
        }
        else if (command == '-') {
            if (list.size == 0) {
                printf("������ ���� �����ϴ�.\n");
            }
            else {
                removePointAtTop(&list);
            }
        }
        else if (command == 'd') {
            if (list.size == 0) {
                printf("������ ���� �����ϴ�.\n");
            }
            else {
                removePointAtBottom(&list);
            }
        }
        else if (command == 'l') {
            printf("����Ʈ�� ����� ���� ����: %d\n", countPoints(&list));
        }
        else if (command == 'c') {
            clearPoints(&list);
            printf("����Ʈ�� �ʱ�ȭ�Ǿ����ϴ�.\n");
            printPoints(&list);  // ��ɾ� c �� ����Ʈ ���
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
                printf("����Ʈ�� ���� ������ �����Ǿ����ϴ�.\n");
            }
            else {
                sortPointsByDistance(&list, 1); // �������� ����
                sortAFlag = 1;
                sortSFlag = 0;  // 's'�� �����ٰ� �ٽ� 'a'�� ������ ���� ���� ����
            }
        }
        else if (command == 's') {
            if (sortSFlag == 1) {
                restoreOriginalOrder(&list);
                sortSFlag = 0;
                printf("����Ʈ�� ���� ������ �����Ǿ����ϴ�.\n");
            }
            else {
                sortPointsByDistance(&list, 0); // �������� ����
                sortSFlag = 1;
                sortAFlag = 0;  // 'a'�� �����ٰ� �ٽ� 's'�� ������ ���� ���� ����
            }
        }
        else if (command == 'q') {
            printf("���α׷� ����.\n");
            break;
        }
        else {
            printf("�߸��� ��ɾ��Դϴ�.\n");
        }

        // 'l', 'm', 'n' ��ɾ�� ��ü ����Ʈ�� ������� ����
        if (command != 'l' && command != 'm' && command != 'n') {
            printPoints(&list);  // ��ɾ� �Ϸ� �� ��ü ����Ʈ ���
        }
    }

    return 0;
}

// �� ����Ʈ �ʱ�ȭ
void initPointList(PointList* list) {
    list->size = 0;
    for (int i = 0; i < MAX_POINTS; i++) {
        list->points[i].x = 0;
        list->points[i].y = 0;
        list->points[i].z = 0;
        original[i] = list->points[i];  // ���� �ε����� �ʱⰪ ����
    }
}

// �� ���� �� �߰� (���� ���̰�)
void addPointAtTop(PointList* list, int x, int y, int z) {
    for (int i = list->size; i > 0; i--) {
        list->points[i] = list->points[i - 1];
    }
    list->points[0].x = x;
    list->points[0].y = y;
    list->points[0].z = z;
    list->size++;
    printf("�� ���� (x: %d, y: %d, z: %d) �߰���.\n", x, y, z);
    for (int i = 0; i < list->size; i++) {
        original[i] = list->points[i];  // �߰� �� ���� �ε��� ����
    }
}

// �� �Ʒ��� �� �߰�
void addPointAtBottom(PointList* list, int x, int y, int z) {
    list->points[list->size].x = x;
    list->points[list->size].y = y;
    list->points[list->size].z = z;
    list->size++;
    printf("�� �Ʒ��� (x: %d, y: %d, z: %d) �߰���.\n", x, y, z);
    for (int i = 0; i < list->size; i++) {
        original[i] = list->points[i];  // �߰� �� ���� �ε��� ����
    }
}

// �� ���� �ִ� �� ���� (�� �ڸ� ����)
void removePointAtTop(PointList* list) {
    list->points[0].x = NULL;
    list->points[0].y = NULL;
    list->points[0].z = NULL;
    printf("�� ���� �� ������.\n");
    // ũ�� ������ ����, ��� �� �ڸ��� ����
}

// �� �Ʒ��� �ִ� �� ����
void removePointAtBottom(PointList* list) {
    list->points[list->size - 1].x = 0;
    list->points[list->size - 1].y = 0;
    list->points[list->size - 1].z = 0;
    list->size--;
    printf("�� �Ʒ��� �� ������.\n");
}

// ����Ʈ ��ü ���
void printPoints(const PointList* list) {
    printf("\n���� ����Ʈ ����:\n");
    for (int i = 0; i < MAX_POINTS; i++) {
        if (i < list->size && (list->points[i].x != NULL || list->points[i].y != NULL || list->points[i].z != NULL)) {
            printf("�ε��� %d: (x: %d, y: %d, z: %d)\n", i, list->points[i].x, list->points[i].y, list->points[i].z);
        }
        else {
            printf("�ε��� %d: �������\n", i);
        }
    }
}

// ����Ʈ ����
void clearPoints(PointList* list) {
    list->size = 0;
    for (int i = 0; i < MAX_POINTS; i++) {
        original[i].x = original[i].y = original[i].z = 0;
    }
}

// ����Ʈ�� �� ���� ��ȯ
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

// �������� ���� �� �� ã��
void findFurthestPoint(const PointList* list) {
    if (list->size == 0) {
        printf("�� �����Ͱ� �����ϴ�.\n");
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

    printf("���� �� ��: (x: %d, y: %d, z: %d)\n", list->points[furthestIndex].x, list->points[furthestIndex].y, list->points[furthestIndex].z);
}

// �������� ���� ����� �� ã��
void findClosestPoint(const PointList* list) {
    if (list->size == 0) {
        printf("�� �����Ͱ� �����ϴ�.\n");
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

    printf("���� ����� ��: (x: %d, y: %d, z: %d)\n", list->points[closestIndex].x, list->points[closestIndex].y, list->points[closestIndex].z);
}

// �������κ����� �Ÿ� ���
double calculateDistance(int x, int y, int z) {
    return sqrt(x * x + y * y + z * z);
}

// �Ÿ� �������� ���� (ascending = 1: ��������, ascending = 0: ��������)
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

    printf("����Ʈ�� %s���� ���ĵǾ����ϴ�.\n", ascending ? "��������" : "��������");
}

// ���� ������ ����
void restoreOriginalOrder(PointList* list) {
    for (int i = 0; i < MAX_POINTS; i++) {
        if (i < list->size && (list->points[i].x != NULL || list->points[i].y != NULL || list->points[i].z != NULL)) {
            printf("�ε��� %d: (x: %d, y: %d, z: %d)\n", i, list->points[i].x, list->points[i].y, list->points[i].z);
        }
        else {
            printf("�ε��� %d: �������\n", i);
        }
    }
}
