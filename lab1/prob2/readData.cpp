#include <iostream>
#include "readData.h"

// FUNCTION THAT READS A SINGLE CHAR AND RETURNS IT
char readChar() {
  char element;
  std::cin >> element;
  
  return element;
}

// FUNCTION THAT DISPLAYS THE MESSAGE SENT AS PARAMETER, READS A SINGLE INT AND RETURNS IT
int readInt(const std::string &message) {
  int value;
  std::cout << message;
  std::cin >> value;

  return value;
}

// FUNCTION THAT CHECKS IF A INT IS BETWEEN LEFT BORDER AND RIGHT BORDER
// IT WOULD BE VALID IF > LEFT BORDER AND < RIGHT BORDER (EXCLUSIVE)
bool isValidInt(const int value, const int leftBorder, const int rightBorder, const std::string &message) {
  if (value <= leftBorder || value >= rightBorder) {
    std::cout << message << std::endl;
    return 0;
  }

  return 1;
}