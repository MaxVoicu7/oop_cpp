#include <iostream>
#include "charVector.h"
#include "readData.h"

// function that initializes the vector and sets its size
void initializeVector(charVector &v, const int size) {
  v.data = new char[size];
  v.size = size;
}

// function that checks if the address is actual, if yes, it is eliberated
void freeMemory(charVector &v) {
  if (isInitialized(v)) {
    delete [] v.data;
    v.data = nullptr;
    v.size = 0;
  }
}

// function that reads elements from a starting position to an ending position exclusive
// reading the values by char or by int
void readVectorElements(charVector &v, const int start, const int end) {
  if (v.size == 0) {
    std::cout << "No size given to the vector" << std::endl;
    return;
  }

  std::cout << "1. Enter elements as chars" << std::endl;
  std::cout << "2. Enter elements as ints" << std::endl;
  int optionInput = readInt("Your choice: ");
  std::cout << std::endl;

  for (int i = start; i < end; i++) {
    std::cout << "Enter the element from the position " << i << ": ";
    
    if (optionInput == 1)
      v.data[i] = readChar();
    else
      v.data[i] = static_cast<char>(readInt(""));
  }
}

// function that displays vector as ints or as chars
void displayVector(const charVector v, const std::string &message, const int displayOption) {
  std::cout << message << std::endl;

  for(int i = 0; i < v.size; i++) 
    if (displayOption == 1)
      std::cout << v.data[i] << " ";
    else 
      std::cout << static_cast<int>(v.data[i]) << " ";

  std::cout << std::endl;
}

// function that sets a new size for the vector, and if needed, requests reading some new elements
void resizeVector(charVector &v, const int newSize) {
  std::cout << std::endl;

  int oldSize = v.size;

  char *newVector = new char[newSize];
  copyElements(v, newVector, oldSize);

  freeMemory(v);

  v.data = newVector;
  v.size = newSize;
  
  if (newSize > oldSize)
    readVectorElements(v, oldSize, newSize);
}

// function that copies values from a vector to another
void copyElements(charVector &oldVector, char *newVector, const int size) {
  for (int i = 0; i < size; i++) 
    newVector[i] = oldVector.data[i];
}

// function that checks if vector has a size different than 0
bool isInitialized(const charVector &v) {
  return (v.size != 0);
}

// function that multiplies all the negative elements of the vector
long long int multiplyNegativeElements(const charVector &v) {
  long long int product = 1;

  for (int i = 0; i < v.size; i++) {
    int x = static_cast<int>(v.data[i]);

    if (x < 0) 
      product *= x;
  }

  return product;
}

// function that reads a position, checks if it is available and modifies its value
void changeElementByPosition(charVector &v) {
  int index = readInt("Enter the index of the element to be changed: ");

  if (index < 0 || index >= v.size) {
    std::cout << std::endl << "Incorrect index" << std::endl;
    return;
  }

  readVectorElements(v, index, index + 1);
}

// function that changes all the elements with a value if that value present in the vector
void changeElementByValue(charVector &v) {
  std::cout << "Enter the value to be changed: ";
  char oldValue = readChar();
  std::cout << std::endl << "Enter the new value: ";
  char newValue = readChar();

  bool isValue = false;

  for (int i = 0; i < v.size; i++) 
    if (v.data[i] == oldValue) {
      v.data[i] = newValue;
      isValue = true;
    }
  
  if (!isValue) {
    std::cout << std::endl << "Incorrect value" << std::endl;
    return;
  }
}

// function that multiplies two vectors
void multiplyTwoVectors(const charVector &a, const charVector &b) {
  for (int i = 0; i < a.size; i++) 
    std::cout << static_cast<int>(a.data[i]) * static_cast<int>(b.data[i]) << " ";
  
  std::cout << std::endl;
}