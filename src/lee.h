// Для правильного разделения программы используйте заголовочные файлы
// Почитайте про это, например, у Таненбаума или где-то ещё.
#define ROWS 10
#define COLS 10

void* beginlee(); // Объявление функции для запуска алгоритма
void leeAlgorithm(int graph[ROWS][COLS], int startX, int startY, int endX, int endY); // Объявление функции для реализации алгоритма Ли
void printGraph(int graph[ROWS][COLS]); // Объявление функции для печати графа
