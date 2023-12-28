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
 
int main() { 
  // Перенаправляем вывод stdout в log.txt
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
  struct sysinfo mem_info; 
  sysinfo(&mem_info); 
  printf("Общий объем ОЗУ: %ld МБ\n", mem_info.totalram / 1024 / 1024);  
  printf("Свободная ОЗУ: %ld МБ\n", mem_info.freeram / 1024 / 1024); 
 
  // Получение информации об использовании ЦП 
  struct rusage cpu_info; 
  getrusage(RUSAGE_SELF, &cpu_info); 
  printf("Использование ЦП: %ld.%06ld секунд\n", cpu_info.ru_utime.tv_sec, cpu_info.ru_utime.tv_usec); 
 
  // Получение информации о дисковом пространстве 
  struct statvfs disk_info; 
  statvfs(".", &disk_info); 
  printf("Общий объем дискового пространства: %ld ГБ\n", (disk_info.f_blocks * disk_info.f_frsize) / 1024 / 1024 / 1024);  
  printf("Доступное дисковое пространство: %ld ГБ\n", (disk_info.f_bavail * disk_info.f_frsize) / 1024 / 1024 / 1024); 
 
  return 0; 
}
