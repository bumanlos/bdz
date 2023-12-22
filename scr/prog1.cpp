#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

// Проверка, является ли данная вершина допустимой по координатам
bool isValid(int x, int y) {
return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

// Проверка, была ли данная вершина посещена
bool isVisited(int x, int y, bool visited[SIZE][SIZE]) {
return visited[x][y];
}

// Нахождение кратчайшего пути между двумя вершинами с помощью алгоритма Ли
int findShortestPath(int graph[SIZE][SIZE], int startX, int startY, int endX, int endY) {
// Проверка, являются ли начальная и конечная вершины допустимыми
if (!isValid(startX, startY) || !isValid(endX, endY)) {
return -1;
}

// Создание матрицы посещенных вершин, все значения инициализируются false
bool visited[SIZE][SIZE];
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        visited[i][j] = false;
    }
}

// Определение смещений для движения вверх, вниз, влево и вправо
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Начальная вершина помечается как посещенная
visited[startX][startY] = true;

// Создание очереди для хранения координат вершин
int queue[SIZE * SIZE * 2];
queue[0] = startX;
queue[1] = startY;

int current, currentX, currentY;
int front = 0, rear = 2;

// Пока очередь не пустая, продолжаем поиск пути
while (front < rear) {
    current = queue[front];
    currentX = queue[front++];
    currentY = queue[front++];

    // Если найден конечный путь, возвращаем его длину
    if (currentX == endX && currentY == endY) {
        return current;
    }

    // Иначе двигаемся во всех возможных направлениях
    for (int i = 0; i < 4; i++) {
        int newX = currentX + dx[i];
        int newY = currentY + dy[i];

        // Проверка, является ли новая вершина допустимой и не посещена
        if (isValid(newX, newY) && graph[newX][newY] && !isVisited(newX, newY, visited)) {
            visited[newX][newY] = true;
            queue[rear++] = current + 1;
            queue[rear++] = newX;
            queue[rear++] = newY;
        }
    }
}

// Если пути нет, возвращаем -1
return -1;
}

// Вывод графа на экран
void printGraph(int graph[SIZE][SIZE]) {
for (int i = 0; i < SIZE; i++) {
for (int j = 0; j < SIZE; j++) {
printf("%d ", graph[i][j]);
}
printf("\n");
}
}

int main() {
int graph[SIZE][SIZE] = {
{1, 1, 0, 1, 1, 0, 0, 1},
{1, 1, 0, 0, 0, 0, 0, 1},
{0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 1, 0, 0, 1},
{1, 0, 0, 1, 1, 1, 1, 1},
{0, 0, 0, 0, 1, 1, 0, 0},
{0, 0, 0, 0, 1, 0, 1, 1},
{1, 1, 1, 1, 1, 0, 1, 1}
};

// Вывод графа на экран
printGraph(graph);

int startX, startY, endX, endY;
printf("Введите начальные координаты (x, y): ");
scanf("%d %d", &startX, &startY);
printf("Введите конечные координаты (x, y): ");
scanf("%d %d", &endX, &endY);

// Нахождение кратчайшего пути
int shortestPath = findShortestPath(graph, startX, startY, endX, endY);

// Вывод результата
if (shortestPath != -1) {
    printf("Кратчайший путь между (%d, %d) и (%d, %d) равен %d", startX, startY, endX, endY, shortestPath);
} else {
printf("Пути между (%d, %d) и (%d, %d) нет", startX, startY, endX, endY);
}

return 0;
}
