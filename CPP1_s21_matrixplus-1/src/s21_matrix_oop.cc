#include "s21_matrix_oop.h"

// базовый конструктор
S21Matrix::S21Matrix() : rows_(0), cols_(0) { CreateMatrix(); }

S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("error");
  }
  CreateMatrix();
}

void S21Matrix::CreateMatrix() {
  this->matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_]();
  }
}

// деструктор
S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

// конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

// конструктор переноса
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

void S21Matrix::RemoveMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    return false;
  } else {
    for (int i = 0; i < other.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) >= 1e-7) {
          return false;
        }
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::exception();
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::exception();
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  S21Matrix matrix_mul(rows_, other.cols_);
  if (cols_ != other.rows_) {
    throw std::exception();
  } else {
    for (int i = 0; i < matrix_mul.rows_; i++) {
      for (int j = 0; j < matrix_mul.cols_; j++) {
        matrix_mul.matrix_[i][j] = 0;
        for (int k = 0; k < other.rows_; k++) {
          matrix_mul.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
  }
  RemoveMatrix();
  *this = matrix_mul;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);
  if (rows_ != cols_) {
    throw std::exception();
  } else {
    if (rows_ == 1) {
      result.matrix_[0][0] = matrix_[0][0];
    } else {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          S21Matrix minor = MinorCreator(i, j);
          result.matrix_[i][j] = minor.Determinant();
        }
      }
      for (int i = 0; i < result.rows_; i++) {
        for (int j = 0; j < result.cols_; j++) {
          result.matrix_[i][j] = result.matrix_[i][j] * pow(-1, i + j);
        }
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::MinorCreator(int l, int m) {
  int k = 0;
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    if (i != l) {
      int k1 = 0;
      for (int j = 0; j < cols_; j++) {
        if (j != m) {
          minor.matrix_[k][k1] = matrix_[i][j];
          k1++;
        }
      }
      k++;
    }
  }
  return minor;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (cols_ != rows_) {
    throw std::exception();
  } else {
    if (cols_ == 1) {
      result = matrix_[0][0];
    } else if (cols_ == 2) {
      result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      result = this->Converting();
    }
  }
  return result;
}

double S21Matrix::Converting() {
  double result = 0;
  int k = 1;
  for (int j = 0; j < cols_; j++) {
    S21Matrix minor = MinorCreator(0, j);
    result += matrix_[0][j] * k * minor.Determinant();
    k *= -1;
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result(rows_, cols_);
  if (rows_ != cols_) {
    throw std::exception();
  } else {
    if (cols_ == 1) {
      result.matrix_[0][0] = 1 / matrix_[0][0];
    } else {
      double rez = Determinant();
      if (rez == 0) {
        throw std::exception();
      }
      S21Matrix matrix = CalcComplements();
      result = matrix.Transpose();
      for (int i = 0; i < result.rows_; i++) {
        for (int j = 0; j < result.cols_; j++) {
          result.matrix_[i][j] = result.matrix_[i][j] * 1 / rez;
        }
      }
    }
  }

  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result = *this;
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    RemoveMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CreateMatrix();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    RemoveMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int rows, int cols) {
  return matrix_[rows][cols];
}

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetCols(int cols) {
  S21Matrix tmp(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < ((cols_ < cols) ? cols_ : cols); j++) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }
  RemoveMatrix();
  *this = tmp;
}

void S21Matrix::SetRows(int rows) {
  S21Matrix tmp(rows, cols_);
  for (int i = 0; i < ((rows_ < rows) ? rows_ : rows); i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }
  RemoveMatrix();
  *this = tmp;
}