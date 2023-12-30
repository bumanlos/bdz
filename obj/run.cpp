#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runProgram1(void *args) {
    system("../src/prog1.cpp"); // Замените "program1.exe" на имя исполняемого файла первой программы
    return NULL;
}

void *runProgram2(void *args) {
    system("../src/prog2.cpp"); // Замените "program2.exe" на имя исполняемого файла второй программы
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
