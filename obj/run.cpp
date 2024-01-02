#include <stdio.h>
#include <stdlib.h>

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


void* monitorSystem(void* arg) {
    struct rusage cpu_info;
    getrusage(RUSAGE_SELF, &cpu_info);
    printf("Использование ЦП: %ld.%06ld секунд\n", cpu_info.ru_utime.tv_sec, cpu_info.ru_utime.tv_usec);

    struct statvfs disk_info;
    statvfs(".", &disk_info);
    printf("Общий объем дискового пространства: %ld ГБ\n", (disk_info.f_blocks * disk_info.f_frsize) / 1024 / 1024 / 1024);
    printf("Доступное дисковое пространство: %ld ГБ\n", (disk_info.f_bavail * disk_info.f_frsize) / 1024 / 1024 / 1024);

    // Здесь можно сохранить результаты мониторинга в файл
    // Примерно так:
    // FILE *file = fopen("monitoring_results.txt", "w");
    // fprintf(file, "Использование ЦП: %ld.%06ld секунд\n", cpu_info.ru_utime.tv_sec, cpu_info.ru_utime.tv_usec);
    // ... другие данные ...
    // fclose(file);

    return NULL;
}

int main() {
    pthread_t pathThread, monitorThread;

    // Инициализация сетки для поиска кратчайшего пути
    // ... ваш код ...

    pthread_create(&pathThread, NULL, findShortestPath, NULL);
    pthread_create(&monitorThread, NULL, monitorSystem, NULL);

    pthread_join(pathThread, NULL);
    pthread_join(monitorThread, NULL);

    return 0;
}
