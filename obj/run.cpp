#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runProgram(void *path) {
    char *programPath = (char *)path;
    system(programPath);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    char *program1Path = "/main/src/prog1.cpp";  // Замените на путь к первой программе
    char *program2Path = "/main/src/prog2.cpp";  // Замените на путь ко второй программе

    pthread_create(&thread1, NULL, runProgram, (void *)program1Path);
    pthread_create(&thread2, NULL, runProgram, (void *)program2Path);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
