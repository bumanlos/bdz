#include <stdio.h>
#include <pthread.h>

// Программа 1
void* program1(void* arg) {
    // Ваш код для программы 1
    return NULL;
}

// Программа 2
void* program2(void* arg) {
    // Ваш код для программы 2
    return NULL;
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
