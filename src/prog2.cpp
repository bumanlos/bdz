#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char command[] = "prog1"; // команда для мониторинга prog1

    file = fopen("../files/log.txt", "a"); // открываем файл для добавления данных (если файла нет, он будет создан)

    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    fprintf(file, "Результаты мониторинга программы prog1:\n");

    // выполняем команду и записываем результат в файл
    if (system(command) == -1) {
        fprintf(file, "Ошибка выполнения команды.\n");
    }

    fclose(file); // закрываем файл

    return 0;
}
