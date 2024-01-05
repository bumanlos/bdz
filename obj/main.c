#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../src/monitoring.h" // Подключаем заголовочный файл для мониторинга
#include "../src/lee.h" // Подключаем заголовочный файл для алгоритма Ли

int main() {
    pthread_t thread1, thread2; // Объявляем переменные для идентификаторов потоков

    // Создаем поток для мониторинга
    pthread_create(&thread1, NULL, monitoring, NULL);

    // Создаем поток для выполнения алгоритма Ли
    pthread_create(&thread2, NULL, beginlee, NULL);

    // Ожидаем завершения работы потоков
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
