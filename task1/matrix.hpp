#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;

    Matrix(Matrix&& other) noexcept : num_rows(other.num_rows), num_cols(other.num_cols), data(std::move(other.data)) {
        other.num_rows = 0;
        other.num_cols = 0;
    }
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            num_rows = other.num_rows;
            num_cols = other.num_cols;
            data = std::move(other.data);
            other.num_rows = 0;
            other.num_cols = 0;
        }
        return *this;
    }

    void Reset(int rowCount, int colCount);
    int At(int row, int col) const;
    const int& At(int row, int col) const;

    int GetRows() const;
    int GetCols() const;
    bool operator==(const Matrix& otherMatrix) const;
    bool operator!=(const Matrix& otherMatrix) const;
    Matrix operator+(const Matrix& otherMatrix) const;

private:
    int m_rows;    // Количество строк
    int m_cols;    // Количество столбцов
    int** elements; // Динамический массив для хранения элементов матрицы
    friend std::istream& operator>>(std::istream& in, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

    void AllocateMemory();
    void DeallocateMemory();
    void CheckBounds(int row, int col) const;
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
private:
    int num_rows;
    int num_cols;
    std::vector<std::vector<int>> data;
};
