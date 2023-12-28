#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void printGraph(int graph[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Функция для поиска кратчайшего пути между двумя вершинами с помощью алгоритма Ли
void findShortestPath(int graph[ROWS][COLS], int startVertex, int endVertex) {
    // Здесь можно добавить код для реализации алгоритма Ли
    printf("Кратчайший путь между вершиной %d и вершиной %d: ...\n", startVertex, endVertex);
}

int main() {
    int graph[ROWS][COLS] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0}
    };

    printf("Планарный граф:\n");
    printGraph(graph);

    int startVertex;
    int endVertex;

    printf("Введите начальную вершину (от 1 до %d): ", ROWS);
    scanf("%d", &startVertex);

    printf("Введите конечную вершину (от 1 до %d): ", ROWS);
    scanf("%d", &endVertex);

    findShortestPath(graph, startVertex - 1 , endVertex -1); // -1 чтобы привести к индексации с нуля

    return 0;
}
