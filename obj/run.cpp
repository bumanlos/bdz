#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork(); // Создаем первый дочерний процесс

    if (pid1 == 0) {
        // Этот код будет выполняться в первом дочернем процессе
        execlp("prog1", "prog1", NULL); // Запускаем программу program1
    }

    pid2 = fork(); // Создаем второй дочерний процесс

    if (pid2 == 0) {
        // Этот код будет выполняться во втором дочернем процессе
        execlp("prog2", "prog2", NULL); // Запускаем программу program2
    }

    // Родительский процесс ждет завершения обоих дочерних процессов
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
