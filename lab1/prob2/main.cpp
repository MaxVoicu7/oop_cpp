#include <iostream>

#include "readData.h"
#include "charVector.h"

int main() {
  charVector vector, vector2;
  vector.size = 0;
  int option, optionInput;

  do {
    std::cout << std::endl << " ================= Menu =================" << std::endl << std::endl;
    std::cout << "\t1.  Initialize vector" << std::endl;
    std::cout << "\t2.  Display vector as integer" << std::endl;
    std::cout << "\t3.  Display vector as char" << std::endl;
    std::cout << "\t4.  Resize vector" << std::endl;
    std::cout << "\t5.  Add one element to the end of the vector" << std::endl;
    std::cout << "\t6.  Delete last element of the vector" << std::endl;
    std::cout << "\t7.  Multiply negative elements of vector" << std::endl;
    std::cout << "\t8.  Change element value by position" << std::endl;
    std::cout << "\t9.  Change element value by value" << std::endl;
    std::cout << "\t10. Multiply 2 vectors" << std::endl;
    std::cout << "\t11. Free memory and leave program" << std::endl <<std::endl;

    option = readInt("Your choice: ");
    std::cout << std::endl << " ========================================" << std::endl << std::endl;

    switch (option) {
      case 1:
        // checking if the vector was not initialized before
        if (!isInitialized(vector)) {
          // reading the size and after reading the elements
          initializeVector(vector, readInt("Enter the initial size of the vector: "));
          std::cout << std::endl;
          readVectorElements(vector, 0, vector.size);
        }
        else 
          std::cout << std::endl << "Your vector was already initialized" << std::endl << std::endl;

        break;

      case 2: 
        // displaying elements as ints
        displayVector(vector, "Vector elements as ints: ", 2);
        break;

      case 3:
        // displaying elements as chars
        displayVector(vector, "Vector elements as chars: ", 1);
        break;

      case 4:
        // vector should be initialized before this operation
        if (!isInitialized(vector)) {
          std::cout << "You have to initialize the vector before this operation" << std::endl;
          break;
        }

        // modifying the size of the vector and reading new elements if needed
        resizeVector(vector, readInt("Enter new size of the vector: "));
        std::cout << std::endl;
        break;

      case 5:
        // resizing the vector by adding an element
        resizeVector(vector, vector.size + 1);
        break;

      case 6:
        // resizing the vector by removing an element
        resizeVector(vector, vector.size - 1);
        break;

      case 7: 
        if (!isInitialized(vector)) {
          std::cout << "You have to initialize the vector before this operation" << std::endl;
          break;
        }

        // multipling all the negative values of the vector
        std::cout << std::endl << "Product of negative elements: " << multiplyNegativeElements(vector) << std::endl << std::endl;
        break;

      case 8:
        if (!isInitialized(vector)) {
          std::cout << "You have to initialize the vector before this operation" << std::endl;
          break;
        }

        // changing a value by position
        changeElementByPosition(vector);
        break;

      case 9:
        if (!isInitialized(vector)) {
          std::cout << "You have to initialize the vector before this operation" << std::endl;
          break;
        }

        // changing all the instances of a value
        changeElementByValue(vector);
        break;

      case 10:
        // creating a new temporary vector of the same size to multiply two vectors
        if (!isInitialized(vector)) {
          std::cout << "Initialize first vector before" << std::endl;
          break;
        }

        initializeVector(vector2, vector.size);
        readVectorElements(vector2, 0, vector2.size);

        std::cout << std::endl << "Vectors multiplied: " << std::endl;
        multiplyTwoVectors(vector, vector2);
        freeMemory(vector2);
        break;

      case 11:
        freeMemory(vector);
        break;

      default:
        std::cout << "Incorrect choice" << std::endl;
    }

  } while (option != 11);

  return 0;
}