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
    // Вставьте код первой программы сюда
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
