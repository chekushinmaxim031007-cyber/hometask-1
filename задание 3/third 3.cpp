#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Чекушин Максим Артемович " << std::endl;
    std::cout << "Group: М1О-137БВ-25" << std::endl;
    std::cout << "Task: task_3" << std::endl;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            std::cout << row[j];
            if (j < row.size() - 1) {
                std::cout << '\t';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> fillMatrix(int rows, int columns) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-500, 500);

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = dist(gen);
        }
    }

    return matrix;
}

std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {

    int rows = matrix.size();
    int columns = matrix[0].size();

    std::vector<std::vector<int>> transposed(columns, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main() {

    int rows, columns;

    printStudentInfo();

    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    std::cout << "Введите количество столбцов: ";
    std::cin >> columns;

    auto matrix = fillMatrix(rows, columns);

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);

    auto transposed = transposeMatrix(matrix);

    std::cout << "Транспонированная матрица:" << std::endl;
    printMatrix(transposed);

}