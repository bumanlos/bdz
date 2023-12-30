#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>    
#include <sys/types.h>  
#include <sys/stat.h>  
#include <time.h>  // Используем правильный заголовочный файл для функции ctime
#include <fcntl.h>  
#include <sys/sysinfo.h>  
#include <sys/statvfs.h>  
#include <sys/resource.h> 
#include <pthread.h>

void *runProgram1(void *args) {
#define ROWS 10
#define COLS 10

// Функция для печати графа(ROWS и COLS - кол-во строк и столбцов)
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
    int queue[ROWS * COLS * 2]; // Очередь для хранения координат вершин(2 - кол-во столбцов для хранения координат x y)
    int front = 0, rear = 0; // Фронт и зад очереди
    int dx[] = {-1, 0, 1, 0}; // Смещения по оси x для соседних вершин
    int dy[] = {0, 1, 0, -1}; // Смещения по оси y для соседних вершин

    queue[rear++] = startX; // Добавляем начальную вершину в очередь
    queue[rear++] = startY;

    while (front < rear) { // цикл обхода графа, Пока очередь не пуста
        int x = queue[front++]; // Извлекаем координаты вершины из очереди
        int y = queue[front++];

        if (x == endX && y == endY) { // Если достигли конечной вершины
            printf("Кратчайший путь между вершиной (%d, %d) и вершиной (%d, %d): %d шагов\n", startX, startY, endX, endY, graph[endX][endY]);
            return;
        }

        for (int i = 0; i < 4; i++) { // Перебираем соседние вершины
            int newX = x + dx[i]; // Вычисляем координаты соседней вершины
            int newY = y + dy[i];

            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && graph[newX][newY] == 0) { // Если соседняя вершина доступна для перемещения
                graph[newX][newY] = graph[x][y] + 1; // Устанавливаем расстояние до неё
                queue[rear++] = newX; // Добавляем её в очередь
                queue[rear++] = newY;
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
    return NULL;
}

void *runProgram2(void *args) {
    // Вставьте код второй программы сюда
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, runProgram1, NULL);
    pthread_create(&thread2, NULL, runProgram2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
