#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <sys/resource.h>

void* monitoring() {
// Описание функции monitoring

FILE* id = fopen("../files/log.txt", "w"); // Открытие файла для записи
printf("Мониторинг системы\n"); // Вывод сообщения о начале мониторинга

int pid = getpid(); // Получение идентификатора процесса
fprintf(id, "Текущий идентификатор процесса: %d\n", pid); // Запись идентификатора процесса в файл

time_t current_time = time(NULL); // Получение текущего времени
fprintf(id, "Текущее время: %s", ctime(&current_time)); // Запись текущего времени в файл

struct sysinfo mem_info; // Структура для информации о памяти
sysinfo(&mem_info); // Получение информации о памяти
fprintf(id, "Общий объем ОЗУ: %ld МБ\n", mem_info.totalram / 1024 / 1024); // Запись общего объема ОЗУ в файл
fprintf(id, "Свободная ОЗУ: %ld МБ\n", mem_info.freeram / 1024 / 1024); // Запись свободной памяти в файл

struct rusage cpu_info; // Структура для информации о использовании ЦП
getrusage(RUSAGE_SELF, &cpu_info); // Получение информации об использовании ЦП
fprintf(id, "Использование ЦП: %ld.%06ld секунд\n", cpu_info.ru_utime.tv_sec, cpu_info.ru_utime.tv_usec); // Запись информации об использовании ЦП в файл

fclose(id); // Закрытие файла
return 0; // Возврат значения
}
