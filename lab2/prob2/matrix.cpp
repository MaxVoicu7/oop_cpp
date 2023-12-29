#include <iostream>
#include <sstream>
#include <iomanip>
#include "matrix.h"
#include "readData.h"

using std::cout;
using std::endl;

// default constructor
//Matrix::Matrix() {
//  data = nullptr;
//  setParameters(0, 0, NO_ERROR);
//}

Matrix::Matrix() : data {nullptr}, nrRows {}, nrColumns {}, errorCode {NO_ERROR} {}

// parameterized constructor with one argument
Matrix::Matrix(const int matrixSize) {
  try {
    data = new int[matrixSize * matrixSize];
    setParameters(matrixSize, matrixSize, NO_ERROR);
    initializeMatrixWithZero();
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    setParameters(0, 0, MEMORY_ALLOCATION_ERROR);
  }
}

// parameterized constructor with 2 arguments
Matrix::Matrix(const int rows, const int cols) {
  try {
    data = new int[rows * cols];
    setParameters(rows, cols, NO_ERROR);
    initializeMatrixWithZero();
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    setParameters(0, 0, MEMORY_ALLOCATION_ERROR);
  }
}

// copy constructor
Matrix::Matrix(const Matrix& other) {
  try {
    data = new int[other.nrRows * other.nrColumns];
    setParameters(other.nrRows, other.nrColumns, other.errorCode);
    for (int i = 0; i < other.nrRows * other.nrColumns; i++) {
      data[i] = other.data[i];
    }
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    setParameters(0, 0, MEMORY_ALLOCATION_ERROR);
  }
}

// destructor
Matrix::~Matrix() {
  delete [] data;
}

// sets the number of rows, columns and the errorCode
void Matrix::setParameters(const int rows, const int cols, const ErrorCode errorCodeValue) {
  nrRows = rows;
  nrColumns = cols;
  errorCode = errorCodeValue;
}

// displays all about the matrix
void Matrix::displayMatrix() {
  cout << "Rows: " << nrRows << endl;
  cout << "Columns: " << nrColumns << endl;
  displayErrorCode();

  cout << endl << "Matrix:" << endl << endl;

  for (int i = 0, count = 0; i < nrRows; i++) {
    for(int j = 0; j < nrColumns; j++, count++)
      cout << std::setw(3) << data[count] << " ";

    cout << endl;
  }

  cout << endl;
}

// sets all the elements of the matrix with 0
void Matrix::initializeMatrixWithZero() {
  for (int i = 0; i < nrRows * nrColumns; i++)
    data[i] = 0;
}

// sets all the elements by reading a specific int for each position
void Matrix::initializeMatrix() {
  for (int i = 0, count = 0; i < nrRows; i++)
    for (int j = 0; j < nrColumns; j++, count++) {
      std::stringstream ss;
      ss << "matrix[" << i << "][" << j << "] = ";
      data[count] = readInt(ss.str());
    }
}

// displays the error code of a matrix
void Matrix::displayErrorCode() {
  switch (errorCode) {
    case NO_ERROR:
      cout << "NO ERROR FOR MATRIX" << endl;
      break;

    case MEMORY_ALLOCATION_ERROR:
      cout << "MEMORY ALLOCATION ERROR. MATRIX SIZE SET TO 0" << endl;
      break;

    case SIZE_INEQUALITY_ERROR:
      cout << "SIZE ERROR WHEN PERFORMING AN OPERATION BETWEEN 2 MATRICES" << endl;
      break;
  }

  cout << endl;
}

// returns the number of cols for a matrix
int Matrix::getColumnsNumber() const {
  return nrColumns;
}

// returns the number of rows for a matrix
int Matrix::getRowsNumber() {
  return nrRows;
}

// returns the errorCode for a matrix
int Matrix::getErrorCode() {
  return errorCode;
}

// sets the value in the position matrix[i][j]
void Matrix::setElementValue(const int element, const int i, const int j) {
  data[i * nrColumns + j] = element;
}

// gets the value from the position [i][j]
int Matrix::getElementValue(const int i, const int j) {
  return data[i * nrColumns + j];
}

// returns 1 if matrix is square, 0 otherwise
bool Matrix::isSquareMatrix() {
  return nrRows == nrColumns;
}

// check if matrices have the same size and adds them, results stored in result
void addTwoMatrices(Matrix &m1, Matrix &m2, Matrix &result) {
  if (!areMatricesSameSize(m1, m2)) {
    cout << "MATRICES HAVE DIFFERENT SIZES. SELECT MATRICES WITH EQUAL SIZES" << endl;
    result.setParameters(0, 0, Matrix::SIZE_INEQUALITY_ERROR);
    return;
  }

  for (int i = 0, count = 0; i < m1.getRowsNumber(); i++)
    for (int j = 0; j < m1.getColumnsNumber(); j++, count++)
      result.setElementValue(m1.data[count] + m2.data[count], i, j);
}

// check if matrices of the same size and subtracts them
void subtractTwoMatrices(Matrix &m1, Matrix &m2, Matrix &result) {
  if (!areMatricesSameSize(m1, m2)) {
    cout << "MATRICES HAVE DIFFERENT SIZES. SELECT MATRICES WITH EQUAL SIZES" << endl;
    result.setParameters(0, 0, Matrix::SIZE_INEQUALITY_ERROR);
    return;
  }

  for (int i = 0, count = 0; i < m1.getRowsNumber(); i++)
    for (int j = 0; j < m1.getColumnsNumber(); j++, count++)
      result.setElementValue(m1.data[count] - m2.data[count], i, j);
}

// returns 1 if matrices are the same size, 0 otherwise
bool areMatricesSameSize(Matrix &m1, Matrix &m2) {
  return m1.getRowsNumber() == m2.getRowsNumber() && m1.getColumnsNumber() == m2.getColumnsNumber();
}

// multiplies each element of the matrix with the number
void multiplyMatrixAndNumber(Matrix &m1, const int number, Matrix &result) {
  for (int i = 0; i < m1.getRowsNumber() * m1.getColumnsNumber(); i++)
    result.data[i] = m1.data[i] * number;
}

// checks if matrices sizes match and multiplies them
void multiplyTwoMatrices(Matrix &m1, Matrix &m2, Matrix &result) {
  if (m1.getColumnsNumber() != m2.getRowsNumber()) {
    cout << "MATRICES SIZES DONT MATCH" << endl;
    result.setParameters(0, 0, Matrix::SIZE_INEQUALITY_ERROR);
    return;
  }

  for (int i = 0; i < m1.getRowsNumber(); i++)
    for (int j = 0; j < m2.getColumnsNumber(); j++) {
      int sum = 0;

      for (int k = 0; k < m1.getColumnsNumber(); ++k)
        sum += m1.getElementValue(i, k) * m2.getElementValue(k, j);

      result.setElementValue(sum, i, j);
    }
}