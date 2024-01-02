#include <stdio.h>
#include <pthread.h>

// Программа 1
void* program1(void* arg) {
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

int main1() {
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
}

// Программа 2
void* program2(void* arg) {
#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <time.h>  // Используем правильный заголовочный файл для функции ctime
#include <fcntl.h>  
#include <sys/sysinfo.h>  
#include <sys/statvfs.h>  
#include <sys/resource.h> 
 
int main2() { 
  // Перенаправляем вывод stdout в log.txt (функция freopen используется для перенаправления стандартных потоков в указанный файл) 
  freopen("../files/log.txt", "w", stdout); 
 
  // Отображение информации о мониторинге системы 
  printf("Мониторинг системы\n"); 
 
  // Код мониторинга 
  // Отображение текущего идентификатора процесса и системного времени 
  int pid = getpid(); 
  printf("Текущий идентификатор процесса: %d\n", pid); 
  time_t current_time = time(NULL);  
  printf("Текущее время: %s", ctime(&current_time)); 
 
  // Получение информации об использовании памяти 
  struct sysinfo mem_info; //структура sysinfo для получения информации об использовании оперативной памяти
  sysinfo(&mem_info); 
  printf("Общий объем ОЗУ: %ld МБ\n", mem_info.totalram / 1024 / 1024);  
  printf("Свободная ОЗУ: %ld МБ\n", mem_info.freeram / 1024 / 1024); 
 
  // Получение информации об использовании ЦП 
  struct rusage cpu_info; //структура rusage для получения информации об использовании процессорного времени
  getrusage(RUSAGE_SELF, &cpu_info); 
  printf("Использование ЦП: %ld.%06ld секунд\n", cpu_info.ru_utime.tv_sec, cpu_info.ru_utime.tv_usec); 
 
  // Получение информации о дисковом пространстве 
  struct statvfs disk_info; //структура statvfs для получения информации о дисковом пространстве
  statvfs(".", &disk_info); 
  printf("Общий объем дискового пространства: %ld ГБ\n", (disk_info.f_blocks * disk_info.f_frsize) / 1024 / 1024 / 1024);  
  printf("Доступное дисковое пространство: %ld ГБ\n", (disk_info.f_bavail * disk_info.f_frsize) / 1024 / 1024 / 1024); 
 
  return 0; 
}
}

int main() {
    pthread_t thread1, thread2;

    // Создание и запуск потоков
    pthread_create(&thread1, NULL, program1, NULL);
    pthread_create(&thread2, NULL, program2, NULL);

    // Ожидание завершения потоков
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Обе программы завершили выполнение\n");

    return 0;
}
