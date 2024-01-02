#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* runProgram(void* arg) {
    char* programPath = (char*)arg;
    char command[100];
    sprintf(command, "g++ %s -o program.out", programPath);
    system(command);
    system("./program.out");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    const char *program1Path = "https://raw.githubusercontent.com/bumanlos/bdz/main/src/prog1.cpp";
    const char *program2Path = "https://raw.githubusercontent.com/bumanlos/bdz/main/src/prog2.cpp";

    pthread_create(&thread1, NULL, runProgram, (void *)program1Path);
    pthread_create(&thread2, NULL, runProgram, (void *)program2Path);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
