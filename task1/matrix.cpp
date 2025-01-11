#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int rowCount, int colCount) 
    : m_rows(rowCount), m_cols(colCount) {
    AllocateMemory();
}

Matrix::~Matrix() { 
    DeallocateMemory();
Matrix::Matrix(int r, int c) {
    if (r < 0 || c < 0) {
        throw std::out_of_range("");
    }
    if (r == 0 || c == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = r;
        num_cols = c;
        data.assign(r, std::vector<int>(c, 0));
    }
}

void Matrix::Reset(int rowCount, int colCount) {
    DeallocateMemory();  // Освобождаем старую память

    if (rowCount <= 0 || colCount <= 0) {
        m_rows = 0;
        m_cols = 0;
void Matrix::Reset(int r, int c) {
    if (r < 0 || c < 0) {
        throw std::out_of_range("");
    }
    if (r == 0 || c == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        m_rows = rowCount;
        m_cols = colCount;
        AllocateMemory();
        num_rows = r;
        num_cols = c;
        data.assign(r, std::vector<int>(c, 0));
    }
}

int& Matrix::At(int row, int col) {
    CheckBounds(row, col);
    return elements[row][col];
int Matrix::At(int r, int c) const {
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        throw std::out_of_range("");
    }
    return data[r][c];
}

const int& Matrix::At(int row, int col) const {
    CheckBounds(row, col);
    return elements[row][col];
int& Matrix::At(int r, int c) {
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        throw std::out_of_range("");
    }
    return data[r][c];
}

int Matrix::GetRows() const {
    return m_rows;
    return num_rows;
}

int Matrix::GetCols() const {
    return m_cols;
    return num_cols;
}

bool Matrix::operator==(const Matrix& otherMatrix) const {
    if (m_rows != otherMatrix.m_rows || m_cols != otherMatrix.m_cols) return false;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (elements[i][j] != otherMatrix.elements[i][j]) {
                return false;
            }
std::istream& operator>>(std::istream& in, Matrix& m) {
    int r, c;
    in >> r >> c;
    m.Reset(r, c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            in >> m.At(i, j);
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& otherMatrix) const {
    return !(*this == otherMatrix);
    return in;
}

Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    if (m_rows != otherMatrix.m_rows || m_cols != otherMatrix.m_cols) {
        throw std::invalid_argument("Matrices dimensions do not match");
    }

    Matrix sumMatrix(m_rows, m_cols);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            sumMatrix.At(i, j) = this->At(i, j) + otherMatrix.At(i, j);
std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    out << m.GetRows() << " " << m.GetCols() << "\n";
    for (int i = 0; i < m.GetRows(); ++i) {
        for (int j = 0; j < m.GetCols(); ++j) {
            out << m.At(i, j) << " ";
        }
        out << "\n";
    }
    return sumMatrix;
    return out;
}

void Matrix::AllocateMemory() {
    if (m_rows > 0 && m_cols > 0) {
        elements = new int*[m_rows]; // Выделяем память для массива
        for (int i = 0; i < m_rows; ++i) {
            elements[i] = new int[m_cols]{0};  // Инициализация нулями
        }
    } else {
        elements = nullptr; // Указываем на nullptr, если размеры некорректны
    }
bool operator==(const Matrix& m1, const Matrix& m2) {
    return m1.num_rows == m2.num_rows && m1.num_cols == m2.num_cols && m1.data == m2.data;
}

void Matrix::DeallocateMemory() {
    if (elements) {
        for (int i = 0; i < m_rows; ++i) {
            delete[] elements[i]; // Освобождаем каждый из массивов
        }
        delete[] elements; // Освобождаем массив
        elements = nullptr; // Устанавливаем указатель в nullptr для безопасности
    }
bool operator!=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}

void Matrix::CheckBounds(int row, int col) const {
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
        throw std::out_of_range("Index out of range");
Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if (m1.GetRows() != m2.GetRows() || m1.GetCols() != m2.GetCols()) {
        throw std::invalid_argument("");
    }
    Matrix res(m1.GetRows(), m1.GetCols());
    for (int i = 0; i < m1.GetRows(); ++i) {
        for (int j = 0; j < m1.GetCols(); ++j) {
            res.At(i, j) = m1.At(i, j) + m2.At(i, j);
        }
    }
    return res;
}

