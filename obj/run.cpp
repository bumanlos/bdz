#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/resource.h>
#include <sys/statvfs.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int shortestPath[ROWS][COLS];

void* findShortestPath(void* arg) {
    // Реализация алгоритма Ли для поиска кратчайшего пути
    // Здесь должен быть ваш код для нахождения кратчайшего пути
    // Примерно так:
    // ... ваш код для алгоритма Ли ...
    return NULL;
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
