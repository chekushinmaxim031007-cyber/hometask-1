
#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: ������� ������ ��������� " << std::endl;
    std::cout << "Group: �1�-137��-25" << std::endl;
    std::cout << "Task: task_2" << std::endl;
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

int main() {
    setlocale(LC_ALL, "Russian");
    {
        int rows, columns;

        printStudentInfo();
        std::cout << "������� ���������� �����: ";
        std::cin >> rows;

        std::cout << "������� ���������� ��������: ";
        std::cin >> columns;

        auto matrix = fillMatrix(rows, columns);

        std::cout << "���� ������� " << rows << "x" << columns << ":" << std::endl;
        printMatrix(matrix);
    }

}