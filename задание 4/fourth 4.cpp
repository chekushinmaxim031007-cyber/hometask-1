#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Чекушин Максим Артемович " << std::endl;
    std::cout << "Group: М1О-137БВ-25" << std::endl;
    std::cout << "Task: task_4" << std::endl;
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

std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1,
    const std::vector<std::vector<int>>& matrix2) {

    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {

    int rows1, cols1, rows2, cols2;

    printStudentInfo();

    setlocale(LC_ALL, "Russian");

    std::cout << "Введите размеры первой матрицы:" << std::endl;
    std::cout << std::endl;
    std::cout << "Количество строк: ";
    std::cin >> rows1;
    std::cout << "Количество столбцов: ";
    std::cin >> cols1;

    std::cout << "\nВведите размеры второй матрицы:" << std::endl;
    std::cout << std::endl;
    std::cout << "Количество строк: ";
    std::cin >> rows2;
    std::cout << "Количество столбцов: ";
    std::cin >> cols2;

    if (cols1 != rows2) {
        std::cerr << "Ошибка: количество столбцов первой матрицы (" << cols1
            << ") должно равняться количеству строк второй матрицы (" << rows2 << ")" << std::endl;
        return 1;
    }

    auto matrix1 = fillMatrix(rows1, cols1);
    auto matrix2 = fillMatrix(rows2, cols2);

    std::cout << "\nПервая матрица:" << std::endl;
    printMatrix(matrix1);

    std::cout << "Вторая матрица:" << std::endl;
    printMatrix(matrix2);

    auto result = multiplyMatrices(matrix1, matrix2);

    std::cout << "Результат умножения матриц:" << std::endl;
    printMatrix(result);

}