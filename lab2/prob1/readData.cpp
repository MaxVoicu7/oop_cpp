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

int readPositiveInt(const std::string &message) {
  int value;
  std::cout << message;
  
  do {
    std::cin >> value;

    if (value < 0) 
      std::cout << "Value should be positive" << std::endl;
  } while(value < 0);

  return value;
}