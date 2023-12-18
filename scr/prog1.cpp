#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Структура для хранения координат вершин
struct Vertex {
    int x;
    int y;
};

// Функция для генерации матрицы с заданными размерами
vector<vector<int>> generateMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    int value = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    return matrix;
}

// Функция для нахождения кратчайшего пути между двумя вершинами в матрице
int findShortestPath(const vector<vector<int>>& matrix, const Vertex& start, const Vertex& end) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<Vertex> q;
    
    // Инициализируем расстояния
    distance[start.x][start.y] = 0;
    q.push(start);
    
    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();
        
        // Перебор соседних вершин
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            
            // Если соседняя вершина находится в пределах матрицы и еще не была посещена
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[v.x][v.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return distance[end.x][end.y];
}

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    
    vector<vector<int>> matrix = generateMatrix(rows, cols);
    
    int start_x, start_y, end_x, end_y;
    cout << "Введите координаты начальной вершины (x и y через пробел): ";
    cin >> start_x >> start_y;
    cout << "Введите координаты конечной вершины (x и y через пробел): ";
    cin >> end_x >> end_y;
    
    Vertex start = {start_x, start_y};
    Vertex end = {end_x, end_y};
    
    int shortestPath = findShortestPath(matrix, start, end);
    cout << "Кратчайший путь между выбранными вершинами: " << shortestPath << endl;
    
    return 0;
}
