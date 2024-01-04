#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "monitoring.h"
#include "lee.h"

int main() {

pthread_t thread1, thread2;

// Нужно запускать в pthread_create функции, а не прописывать имена файлов :)
// На выходе, после компиляции у вас должен быть один общий файл, а не три
pthread_create(&thread1, NULL, monitoring, NULL);
pthread_create(&thread2, NULL, beginlee, NULL);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

return 0;
}
