#include <cstdlib>
int main() {
    // Запуск программы p1.cpp
    system("g++ ../src/prog1.cpp -o prog1 && ./prog1");

    // Запуск программы p2.cpp
    system("g++ ../src/prog2.cpp -o prog2 && ./prog2");

    return 0;
}
