#include <iostream>
#include <vector>

#include "matrix.h"
#include "readData.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool isMatrixArrayEmpty(const vector<Matrix> &matrixArray);
int selectMatrixFromArray(const vector<Matrix> &matrixArray);
int getMatrixForUsage(const vector<Matrix> &matrixArray, const string &message);

int main() {
  // creating an array of Matrices
  vector<Matrix> matrixArray;
  // variables used for menu interaction
  int selectedMenuOption, exitOption = 16;
  // variables used for reading values needed for functions to interact with matrices
  int element, selectedMatrix, selectedMatrix2, rowNr, columnNr;

  do {
    // displaying menu options
    cout << endl << " ===================== Menu =====================" << endl << endl;
    cout << "\t1.  Create 0 x 0 matrix using implicit constructor" << endl;
    cout << "\t2.  Create square matrix" << endl;
    cout << "\t3.  Create rectangular matrix" << endl;
    cout << "\t4.  Display matrix" << endl;
    cout << "\t5.  Populate matrix with values" << endl;
    cout << "\t6.  Get the number of rows for a matrix" << endl;
    cout << "\t7.  Get the number of columns for a matrix" << endl;
    cout << "\t8.  Get error code for a matrix" << endl;
    cout << "\t9.  Set a specific element of matrix" << endl;
    cout << "\t10. Get the value of an element from a specific position" << endl;
    cout << "\t11. Check if matrix is square" << endl;
    cout << "\t12. Add two matrices" << endl;
    cout << "\t13. Subtract two matrices" << endl;
    cout << "\t14. Multiply a matrix and a number" << endl;
    cout << "\t15. Multiply two matrices" << endl;
    cout << "\t16. Leave program" << endl << endl;

    selectedMenuOption = readInt("Your choice: ");
    cout << endl << " ================================================" << endl << endl;

    switch (selectedMenuOption) {
      case 1:
        // creating a 0x0 matrix using the default constructor directly inside the vector
        matrixArray.emplace_back();
        break;
      
      case 2: {
        // creating a square n x n matrix using parameterized constructor with one argument
        // matrix is created directly inside the vector, size is read as a positive integer
        int squareMatrixSize = readPositiveInt("Enter the size of the square matrix: ");
        matrixArray.emplace_back(squareMatrixSize);
        break;
      }

      case 3: {
        // creating an n x m matrix using parameterized constructor with 2 arguments
        // matrix is created directly inside the vector, sizes are read as positive integers
        int nrRows = readPositiveInt("Enter the number of rows for the matrix: ");
        int nrColumns = readPositiveInt("Enter the number of columns for the matrix: ");
        matrixArray.emplace_back(nrRows, nrColumns);
        break;
      }

      case 4: {
        // selecting a matrix from the available list, the index of matrix is returned
        // if -1 is returned, no matrices are available and error message is displayed
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO DISPLAY ONE");
        if (selectedMatrix == -1) break;

        // displaying the selected matrix using the displayMatrix method
        matrixArray[selectedMatrix].displayMatrix();
        break;
      }

      case 5: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO POPULATE ONE");
        if (selectedMatrix == -1) break;

        // initializing the selected matrix with values, for each position an int value from the console will be read
        matrixArray[selectedMatrix].initializeMatrix();
        break;
      }

      case 6: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO GET THE NUMBER OF ROWS");
        if (selectedMatrix == -1) break;

        // displaying the number of rows the matrix has
        cout << "Matrix has " << matrixArray[selectedMatrix].getRowsNumber() << " rows" << endl;
        break;
      }

      case 7: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO GET THE NUMBER OF COLUMNS");
        if (selectedMatrix == -1) break;

        // displaying the number of columns the matrix has
        cout << "Matrix has " << matrixArray[selectedMatrix].getColumnsNumber() << " columns" << endl;
        break;
      }

      case 8: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO GET THE ERROR CODE");
        if (selectedMatrix == -1) break;

        // displaying the error Code the matrix has
        cout << "Error code for this matrix is: ";
        matrixArray[selectedMatrix].displayErrorCode();
        break;
      }

      case 9: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO SET A SPECIFIC ELEMENT");
        if (selectedMatrix == -1) break;

        // if matrix sizes = 0, no element can be set and error message displayed
        if (!matrixArray[selectedMatrix].getRowsNumber() || !matrixArray[selectedMatrix].getColumnsNumber()) {
          cout << "SET VALUES GREATER THAN 0 FOR THE NUMBER OF ROWS AND COLUMNS" << endl;
          break;
        }

        // reading the i and j parameters as ints between borders and element as int
        rowNr = getIntBetweenBordersInclusive(0, matrixArray[selectedMatrix].getRowsNumber() - 1, "Enter the number of the row: ");
        columnNr = getIntBetweenBordersInclusive(0, matrixArray[selectedMatrix].getColumnsNumber() - 1, "Enter the number of the column: ");
        element = readInt("Enter the value of the element: ");

        // setting the value of the element from the matrix[i][j]
        matrixArray[selectedMatrix].setElementValue(element, rowNr, columnNr);
        break;
      }

      case 10: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE TRYING TO GET A SPECIFIC ELEMENT");
        if (selectedMatrix == -1) break;

        // if matrix sizes = 0, no element can be gotten and error message displayed
        if (!matrixArray[selectedMatrix].getRowsNumber() || !matrixArray[selectedMatrix].getColumnsNumber()) {
          cout << "SET VALUES GREATER THAN 0 FOR THE NUMBER OF ROWS AND COLUMNS" << endl;
          break;
        }

        // reading i and j as ints between borders and displaying the element from matrix[i][j]
        rowNr = getIntBetweenBordersInclusive(0, matrixArray[selectedMatrix].getRowsNumber() - 1, "Enter the number of the row: ");
        columnNr = getIntBetweenBordersInclusive(0, matrixArray[selectedMatrix].getColumnsNumber() - 1, "Enter the number of the column: ");
        cout << "Matrix[" << rowNr << "][" << columnNr << "] = " << matrixArray[selectedMatrix].getElementValue(rowNr, columnNr) << endl;
        break;
      }

      case 11: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE CHECKING IF IT IS SQUARE");
        if (selectedMatrix == -1) break;

        // if matrix sizes = 0 no check required and error message displayed
        if (!matrixArray[selectedMatrix].getRowsNumber() || !matrixArray[selectedMatrix].getColumnsNumber()) {
          cout << "SET VALUES GREATER THAN 0 FOR THE NUMBER OF ROWS AND COLUMNS" << endl;
          break;
        }

        // checking if matrix is square and displaying the corresponding message
        if (matrixArray[selectedMatrix].isSquareMatrix()) cout << "Matrix is square!" << endl;
        else cout << "Matrix is rectangular!" << endl;
        break;
      }

      case 12: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE ADDING");
        if (selectedMatrix == -1) break;

        // selecting the second matrix
        selectedMatrix2 = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE ADDING");
        if (selectedMatrix2 == -1) break;

        // creating a new matrix at the end of vector, adding the selected matrices and storing the result in the newly created matrix
        matrixArray.emplace_back(matrixArray[selectedMatrix].getRowsNumber(), matrixArray[selectedMatrix].getColumnsNumber());
        addTwoMatrices(matrixArray[selectedMatrix], matrixArray[selectedMatrix2], matrixArray[matrixArray.size() - 1]);
        break;
      }

      case 13: {
        // selecting working as in case 4, selecting 2 matrices
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE SUBTRACTING");
        if (selectedMatrix == -1) break;

        selectedMatrix2 = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE SUBTRACTING");
        if (selectedMatrix2 == -1) break;

        // creating a new matrix at the end of the vector, subtracting the selected matrices and storing the result in the newly created matrix
        matrixArray.emplace_back(matrixArray[selectedMatrix].getRowsNumber(), matrixArray[selectedMatrix].getColumnsNumber());
        subtractTwoMatrices(matrixArray[selectedMatrix], matrixArray[selectedMatrix2], matrixArray[matrixArray.size() - 1]);
        break;
      }

      case 14: {
        // selecting working as in case 4
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE MULTIPLYING WITH A NUMBER");
        if (selectedMatrix == -1) break;

        // creating a new matrix at the end of the array, reading the value and multiplying the value with the selected matrix
        matrixArray.emplace_back(matrixArray[selectedMatrix].getRowsNumber(), matrixArray[selectedMatrix].getColumnsNumber());
        element = readInt("Enter the number to be multiplied with the matrix: ");
        multiplyMatrixAndNumber(matrixArray[selectedMatrix], element, matrixArray[matrixArray.size() - 1]);
        break;
      }

      case 15: {
        // selecting working as in case 4, selecting 2 matrices
        selectedMatrix = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE MULTIPLYING");
        if (selectedMatrix == -1) break;

        selectedMatrix2 = getMatrixForUsage(matrixArray, "CREATE A MATRIX BEFORE MULTIPLYING");
        if (selectedMatrix2 == -1) break;

        // creating a new matrix at the end of the array and storing the results of multiplying in it
        matrixArray.emplace_back(matrixArray[selectedMatrix].getRowsNumber(), matrixArray[selectedMatrix2].getColumnsNumber());
        multiplyTwoMatrices(matrixArray[selectedMatrix], matrixArray[selectedMatrix2], matrixArray[matrixArray.size() - 1]);
        break;
      }

      case 16: 
        break;

      default:
        cout << "ENTER AN AVAILABLE MENU OPTION" << endl;
        break;
    }

  } while (selectedMenuOption != exitOption);

  return 0;
}


// checking it the matrix array is empty
bool isMatrixArrayEmpty(const vector<Matrix> &matrixArray) {
  return matrixArray.empty();
}


// selecting a matrix from the array and returning the index
int selectMatrixFromArray(const vector<Matrix> &matrixArray) {
  // the values are displayed from 1, array is indexed from 0
  cout << "Select one matrix from the following:" << endl;
  for (int i = 0; i < matrixArray.size(); i++) 
    std::cout << "\t" << i + 1 << ".  Matrix nr. " << i + 1 << endl;

  cout << endl;

  int selectedMatrix;

  // read index till the entered value is between borders 1 and array.size
  do {
    selectedMatrix = readPositiveInt("Enter the selected matrix: ");
  } while (selectedMatrix < 1 || selectedMatrix > matrixArray.size());

  cout << endl;
  
  // return the value - 1, because the options were displayed indexed from 1
  return selectedMatrix - 1;
}


// if no matrices in array, -1 returned, else the index of matrix is returned
int getMatrixForUsage(const vector<Matrix> &matrixArray, const string &message) {
  if (isMatrixArrayEmpty(matrixArray)) {
    cout << message << endl;
    return -1;
  } 

  return selectMatrixFromArray(matrixArray);
}