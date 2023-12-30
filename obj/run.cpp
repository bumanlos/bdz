#include <iostream>
#include <thread>

void thread_function(const std::string& program_name) {
    system(program_name.c_str()); // Запускаем программу
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <../src/prog1> <../src/prog2>" << std::endl;
        return 1;
    }

    std::string program1 = argv[1]; // Путь к первой программе
    std::string program2 = argv[2]; // Путь ко второй программе

    std::thread thread1(thread_function, program1); // Создаем первый поток
    std::thread thread2(thread_function, program2); // Создаем второй поток

    thread1.join(); // Ждем завершения первого потока
    thread2.join(); // Ждем завершения второго потока

    return 0;
}
