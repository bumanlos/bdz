#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    char *program_name = (char *)arg;
    system(program_name); // Запускаем программу
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <../src/prog1.cpp> <../src/prog2.cpp>\n", argv[0]);
        return 1;
    }

    pthread_t thread1, thread2;
    char *program1 = argv[1]; // Путь к первой программе
    char *program2 = argv[2]; // Путь ко второй программе

    pthread_create(&thread1, NULL, thread_function, (void *)program1); // Создаем первый поток
    pthread_create(&thread2, NULL, thread_function, (void *)program2); // Создаем второй поток

    pthread_join(thread1, NULL); // Ждем завершения первого потока
    pthread_join(thread2, NULL); // Ждем завершения второго потока

    return 0;
}
