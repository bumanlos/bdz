#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Функция для печати графа
void printGraph(int graph[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Функция для реализации алгоритма Ли
void leeAlgorithm(int graph[ROWS][COLS], int startX, int startY, int endX, int endY) {
    int queue[ROWS * COLS * 2]; // Очередь для хранения координат вершин
    int front = 0, rear = 0; // Фронт и зад очереди
    int dx[] = {-1, 0, 1, 0}; // Смещения по оси x для соседних вершин
    int dy[] = {0, 1, 0, -1}; // Смещения по оси y для соседних вершин

    queue[rear++] = startX; // Добавляем начальную вершину в очередь
    queue[rear++] = startY;

    while (front < rear) { // Пока очередь не пуста
        int x = queue[front++]; // Извлекаем координаты вершины из очереди
        int y = queue[front++];

        if (x == endX && y == endY) { // Если достигли конечной вершины
            printf("Кратчайший путь между вершиной (%d, %d) и вершиной (%d, %d): %d шагов\n", startX, startY, endX, endY, graph[endX][endY]);
            return;
        }

        for (int i = 0; i < 4; i++) { // Перебираем соседние вершины
            int nx = x + dx[i]; // Вычисляем координаты соседней вершины
            int ny = y + dy[i];

            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && graph[nx][ny] == 0) { // Если соседняя вершина доступна для перемещения
                graph[nx][ny] = graph[x][y] + 1; // Устанавливаем расстояние до неё
                queue[rear++] = nx; // Добавляем её в очередь
                queue[rear++] = ny;
            }
        }
    }

    printf("Кратчайший путь между вершиной (%d, %d) и вершиной (%d, %d) не найден\n", startX, startY, endX, endY);
}

int main() {
    int graph[ROWS][COLS] = {
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 1, 1, 0}
    };

    printf("Планарный граф:\n");
    printGraph(graph);

    int startX;
    int startY;
    int endX;
    int endY;

    printf("Введите начальные координаты вершины (x y): ");
    scanf("%d %d", &startX , &startY );

    printf("Введите конечные координаты вершины (x y): ");
    scanf("%d %d", &endX , &endY );

    leeAlgorithm(graph,startX , startY , endX , endY );

    return 0;
}
