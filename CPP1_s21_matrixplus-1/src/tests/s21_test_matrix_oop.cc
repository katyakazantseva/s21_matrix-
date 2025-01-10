#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(EqMatrix, test1) {
  S21Matrix M(2, 2);
  M(0, 0) = 5;
  M(0, 1) = 2;
  M(1, 0) = 7;
  M(1, 1) = 5;
  S21Matrix M2(2, 3);
  M2(0, 0) = 5;
  M2(0, 1) = 2;
  M2(0, 2) = 3;
  M2(1, 0) = 7;
  M2(1, 1) = 5;
  M2(1, 2) = 6;
  ASSERT_EQ(0, M.EqMatrix(M2));
}
TEST(EqMatrix, test2) {
  S21Matrix M(3, 3);
  M(0, 0) = 5;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(1, 0) = 7;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  S21Matrix M2(3, 3);
  M2(0, 0) = 5;
  M2(0, 1) = 2;
  M2(0, 2) = 3;
  M2(1, 0) = 7;
  M2(1, 1) = 5;
  M2(1, 2) = 6;
  M2(2, 0) = 7;
  M2(2, 1) = 8;
  M2(2, 2) = 9;
  ASSERT_EQ(1, M.EqMatrix(M2));
}
TEST(EqMatrix, test3) {
  S21Matrix M(3, 3);
  M(0, 0) = 5;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(1, 0) = 7;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  S21Matrix M2(3, 3);
  M2(0, 0) = 5;
  M2(0, 1) = 2;
  M2(0, 2) = 3;
  M2(1, 0) = 7;
  M2(1, 1) = 5;
  M2(1, 2) = 6;
  M2(2, 0) = 7;
  M2(2, 1) = 8;
  M2(2, 2) = 8;
  ASSERT_EQ(0, M.EqMatrix(M2));
}
TEST(SumMatrix, test1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2 = M;
  M.SumMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 20);
    }
  }
}
TEST(SumMatrix, test2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 150.5;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150.5;
    }
  }
  M.SumMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 301);
    }
  }
}
TEST(SumMatrix, test_3) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2(7, 7);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 10;
    }
  }
  ASSERT_ANY_THROW(M.SumMatrix(M2));
}
TEST(SubMatrix, test_1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 347.475;
    }
  }
  S21Matrix M2 = M;
  M.SubMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 0);
    }
  }
}
TEST(SubMatrix, test_2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 374729.342;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150342.5425;
    }
  }
  M.SubMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 224386.7995);
    }
  }
}
TEST(SubMatrix, test_3) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2(7, 7);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 10;
    }
  }
  ASSERT_ANY_THROW(M.SubMatrix(M2));
}
TEST(MulNumber, test1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  M.MulNumber(1);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 10);
    }
  }
}
TEST(MulNumber, test2) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  M.MulNumber(2);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 20);
    }
  }
}
TEST(MulMatrix, test_1) {
  S21Matrix M(4, 5);
  S21Matrix M2(4, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
      M2(i, j) = 25;
    }
  }
  ASSERT_ANY_THROW(M.MulMatrix(M2));
}
TEST(MulMatrix, test_2) {
  S21Matrix M(4, 5);
  S21Matrix M2(5, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 12;
    }
  }
  M.MulMatrix(M2);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 2280);
    }
  }
}
TEST(Transpose, test_1) {
  int rows_ = 9;
  int cols_ = 3;
  S21Matrix M(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      M(i, j) = 38;
    }
  }
  S21Matrix M2 = M.Transpose();
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      ASSERT_DOUBLE_EQ(M2(i, j), 38);
    }
  }
}
TEST(Transpose, test_2) {
  S21Matrix M(3, 3);
  M(0, 0) = 23;
  M(0, 1) = 76;
  M(0, 2) = 54;
  M(1, 0) = 98;
  M(1, 1) = 578;
  M(1, 2) = 6;
  M(2, 0) = 9;
  M(2, 1) = 2;
  M(2, 2) = 6;
  S21Matrix M2 = M.Transpose();
  ASSERT_DOUBLE_EQ(M2(0, 0), 23);
  ASSERT_DOUBLE_EQ(M2(0, 1), 98);
  ASSERT_DOUBLE_EQ(M2(0, 2), 9);
  ASSERT_DOUBLE_EQ(M2(1, 0), 76);
  ASSERT_DOUBLE_EQ(M2(1, 1), 578);
  ASSERT_DOUBLE_EQ(M2(1, 2), 2);
  ASSERT_DOUBLE_EQ(M2(2, 0), 54);
  ASSERT_DOUBLE_EQ(M2(2, 1), 6);
  ASSERT_DOUBLE_EQ(M2(2, 2), 6);
}
TEST(Transpose, test_3) {
  S21Matrix M(1, 1);
  M(0, 0) = 79;
  S21Matrix M2 = M.Transpose();
  ASSERT_DOUBLE_EQ(M2(0, 0), 79);
}
TEST(CalcComplements, test_1) {
  S21Matrix M(1, 1);
  M(0, 0) = 5;
  S21Matrix M2 = M.CalcComplements();
  ASSERT_DOUBLE_EQ(M2(0, 0), 5);
}
TEST(CalcComplements, test_2) {
  S21Matrix M(3, 2);
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(1, 0) = 0;
  M(1, 1) = 4;
  M(2, 0) = 5;
  M(2, 1) = 2;
  ASSERT_ANY_THROW(M.CalcComplements());
}
TEST(Determinant, test_1) {
  S21Matrix M(1, 1);
  M(0, 0) = 8.589;
  double res = M.Determinant();
  ASSERT_DOUBLE_EQ(res, 8.589);
}
TEST(Determinant, test_2) {
  S21Matrix M(4, 3);
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 3;
  M(2, 0) = 5;
  M(2, 1) = 6;
  M(2, 2) = 6;
  M(3, 0) = 9;
  M(3, 1) = 4;
  M(3, 2) = 1;
  ASSERT_ANY_THROW(M.Determinant());
}
TEST(Determinant, test_3) {
  S21Matrix M(4, 4);
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 4;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 3;
  M(1, 3) = 2;
  M(2, 0) = 5;
  M(2, 1) = 6;
  M(2, 2) = 6;
  M(2, 3) = 7;
  M(3, 0) = 9;
  M(3, 1) = 4;
  M(3, 2) = 1;
  M(3, 3) = 6;
  double res = M.Determinant();
  ASSERT_NEAR(res, -46.0, 1e-6);
}
TEST(InverseMatrix, test_1) {
  S21Matrix M(4, 2);
  M(0, 0) = 7;
  M(0, 1) = 4;
  M(1, 0) = 2;
  M(1, 1) = 9;
  M(2, 0) = 32;
  M(2, 1) = 4;
  M(3, 0) = 6;
  M(3, 1) = 1;
  ASSERT_ANY_THROW(M.InverseMatrix());
}
TEST(InverseMatrix, test_2) {
  S21Matrix M(3, 3);
  M(0, 0) = 2;
  M(0, 1) = 5;
  M(0, 2) = 7;
  M(1, 0) = 6;
  M(1, 1) = 3;
  M(1, 2) = 4;
  M(2, 0) = 5;
  M(2, 1) = -2;
  M(2, 2) = -3;
  S21Matrix M2 = M.InverseMatrix();
  ASSERT_NEAR(M2(0, 0), 1, 1e-6);
  ASSERT_NEAR(M2(0, 1), -1, 1e-6);
  ASSERT_NEAR(M2(0, 2), 1, 1e-6);
  ASSERT_NEAR(M2(1, 0), -38, 1e-6);
  ASSERT_NEAR(M2(1, 1), 41, 1e-6);
  ASSERT_NEAR(M2(1, 2), -34, 1e-6);
  ASSERT_NEAR(M2(2, 0), 27, 1e-6);
  ASSERT_NEAR(M2(2, 1), -29, 1e-6);
  ASSERT_NEAR(M2(2, 2), 24, 1e-6);
}
TEST(Operator_assignment, test_1) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38.456;
    }
  }
  S21Matrix M2;
  M2 = M;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), M2(i, j));
    }
  }
}
TEST(Operator_assignment_move, test_1) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38.456;
    }
  }
  S21Matrix M2;
  M2 = std::move(M);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M2(i, j), 38.456);
    }
  }
  ASSERT_EQ(M.GetRows(), 0);
  ASSERT_EQ(M.GetCols(), 0);
}
TEST(Operator_sum, test_1) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 1;
    }
  }
  S21Matrix M1(4, 4);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  S21Matrix M2(4, 4);
  M2 = M + M1;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M2(i, j), 2);
    }
  }
}
TEST(Operator_sub, test_1) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M1(4, 4);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  S21Matrix M2(4, 4);
  M2 = M - M1;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M2(i, j), 1);
    }
  }
}
TEST(Operator_mulm, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M1(3, 3);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  S21Matrix M2(3, 3);
  M2 = M * M1;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M2(i, j), 6);
    }
  }
}
TEST(Operator_muln, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M2(3, 3);
  M2 = M * 2;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M2(i, j), 4);
    }
  }
}
TEST(Operator_eq, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 1;
    }
  }
  S21Matrix M1(3, 3);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  ASSERT_EQ(M == M1, 1);
}
TEST(Operator_appplus, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M1(3, 3);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  M += M1;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 3);
    }
  }
}
TEST(Operator_appminus, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M1(3, 3);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  M -= M1;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 1);
    }
  }
}
TEST(Operator_appmulm, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M1(3, 3);
  for (int i = 0; i < M1.GetRows(); i++) {
    for (int j = 0; j < M1.GetCols(); j++) {
      M1(i, j) = 1;
    }
  }
  M *= M1;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 6);
    }
  }
}
TEST(Operator_appmuln, test_1) {
  S21Matrix M(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  M *= 2;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 4);
    }
  }
}
TEST(Operator_brec, test_1) {
  S21Matrix M(1, 1);
  M(0, 0) = 1;
  ASSERT_EQ(M(0, 0), 1);
}
TEST(GetRows, test_1) {
  S21Matrix M(3, 3);
  ASSERT_EQ(M.GetRows(), 3);
}
TEST(GetCols, test_1) {
  S21Matrix M(3, 3);
  ASSERT_EQ(M.GetCols(), 3);
}
TEST(SetRows, test_1) {
  S21Matrix M(3, 3);
  M.SetRows(4);
  ASSERT_EQ(M.GetRows(), 4);
}
TEST(SetCols, test_1) {
  S21Matrix M(3, 3);
  M.SetCols(4);
  ASSERT_EQ(M.GetCols(), 4);
}
TEST(SetCols, test_2) {
  S21Matrix M(3, 3);
  S21Matrix L = std::move(M);
  ASSERT_EQ(L.GetCols(), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}