#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    char *program = (char *)arg;
    system(program); // Запускаем программу
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    char *prog1 = "./prog1"; // Путь к первой программе
    char *prog2 = "./prog2"; // Путь ко второй программе

    pthread_create(&thread1, NULL, thread_function, (void *)program1); // Создаем первый поток
    pthread_create(&thread2, NULL, thread_function, (void *)program2); // Создаем второй поток

    pthread_join(thread1, NULL); // Ждем завершения первого потока
    pthread_join(thread2, NULL); // Ждем завершения второго потока

    return 0;
}
