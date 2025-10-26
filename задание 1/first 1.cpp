
#include <iostream>
#include <vector>

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Чекушин Максим Артемович " << std::endl;
    std::cout << "Group: М10-137БВ-25" << std::endl;
    std::cout << "Task: task_1" << std::endl;
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

int main() {
    printStudentInfo();
    std::cout << "Ваша пробная матрица:";
    std::cout << std::endl;
    std::vector<std::vector<int>> demoMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printMatrix(demoMatrix);

    return 0;
}


