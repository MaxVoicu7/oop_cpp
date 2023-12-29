#include <cstring>
#include <limits>
#include "myString.h"

// ================== constructors ===================

// default constructor
String::String() : data{nullptr}, length{0} {};

// parameterized constructor
String::String(const char *value) {
  try {
    data = new char[strlen(value) + 1];
    length = strlen(value);
    strcpy(data, value);
    data[length] = '\0';
  } catch (std::bad_alloc& ba) {
    data = nullptr;
    length = 0;
  }
}

// copy constructor
String::String(const String &secondString) {
  try {
    data = new char[secondString.length + 1];
    length = secondString.length;
    strcpy(data, secondString.data);
  } catch (std::bad_alloc& ba) {
    data = nullptr;
    length = 0;
  }
}

// ================== destructor ==================

String::~String() {
  delete[] data;
}

// ==================== getter =====================

// get String length
int String::getLength() const {
 return length;
}

// get string value
char *String::getData() const {
 return data;
}

// ================== operators =====================

// String + String
String String::operator+ (const String &secondString) const {
  String newString;

  newString.length = length + secondString.length;
  newString.data = new char[newString.length + 1];

  strcpy(newString.data, this->data);
  strcat(newString.data, secondString.data);
  
  return newString;
}

// String + char *
String String::operator+ (const char* secondValue) const {
  if (secondValue == nullptr) 
    return *this;
  
  int secondLength = strlen(secondValue);

  String newString;
  newString.length = length + secondLength;
  newString.data = new char[newString.length + 1];

  strcpy(newString.data, this->data);
  strcat(newString.data, secondValue);

  return newString;
}

// assignement operator for String
String& String::operator= (const String &value) {
  if (this != &value) {
    char* newData = new char[value.length + 1];
    strcpy(newData, value.data);

    delete[] data;

    data = newData;
    length = value.length;
  }

  return *this;
}

// assignement operator for char*
String& String::operator= (const char* str) {
  if (str) {
    char* newData = new char[strlen(str) + 1];
    strcpy(newData, str);

    delete[] data;

    data = newData;
    length = strlen(str);
  } else {
    delete[] data;
    data = nullptr;
    length = 0;
  }

  return *this;
}

// += for String
String& String::operator+= (const String &secondString) {
  char *newData = new char[length + secondString.length + 1]; 

  strcpy(newData, this->data);  
  strcat(newData, secondString.data);

  delete[] data; 

  data = newData; 
  length = length + secondString.length;

  return *this;
}

// += for char*
String& String::operator+= (const char* str) {
  if (str) {
    int strLength = strlen(str);
    char *newData = new char[length + strLength + 1];

    strcpy(newData, this->data);
    strcat(newData, str);  

    delete[] data;

    data = newData; 
    length = length + strLength;
  }

  return *this; 
}

// [] to acces a specific element
char& String::operator[] (int index) {
  static char nullChar = '\0';

  if (index < 0 || index >= length) 
    return nullChar;
  
  return data[index];
}

// [] for a const String
const char& String::operator[] (int index) const {
  static const char nullChar = '\0';

  if (index < 0 || index >= length) 
    return nullChar;
  
  return data[index];
}


// ================ friend functions =================

std::ostream& operator<< (std::ostream& os, const String& str) {
  if (str.data != nullptr) {
    os << str.data;
  } else {
    os << "[null]";
  }
  return os;
}

std::istream& operator>>(std::istream& is, String& str) {
  std::string tmp;
  std::getline(is, tmp);
  str = tmp.c_str();     
  return is;
}

// String == String
bool operator== (const String &leftString, const String &rightString) {
  if (leftString.length != rightString.length)
    return false; 
    
  return strcmp(leftString.data, rightString.data) == 0;
}

// String == char*
bool operator== (const String &leftString, const char* rightString) {
  if (rightString == nullptr) 
    return leftString.length == 0;
    
  if (leftString.length != strlen(rightString)) 
    return false; 
    
  return strcmp(leftString.data, rightString) == 0;
}

// char* == String
bool operator==(const char* leftString, const String &rightString) {
  return rightString == leftString;
}

// String != String
bool operator!=(const String &leftString, const String &rightString) {
  return !(leftString == rightString);
}

// String != char
bool operator!=(const String &leftString, const char* rightString) {
  return !(leftString == rightString);
}

// char != String
bool operator!=(const char* leftString, const String &rightString) {
  return !(leftString == rightString);
}


// String < String
bool operator<(const String &leftString, const String &rightString) {
  return strcmp(leftString.data, rightString.data) < 0; 
}

// String < char*
bool operator<(const String &leftString, const char* rightString) {
  if (!rightString)
    return false;
    
  return strcmp(leftString.data, rightString) < 0;  
}

// char* < String
bool operator<(const char* leftString, const String &rightString) {
  if (!leftString)
    return rightString.length > 0; 

  return strcmp(leftString, rightString.data) < 0;
}

// String > String
bool operator>(const String &leftString, const String &rightString) {
  return strcmp(leftString.data, rightString.data) > 0; 
}

// String > char*
bool operator>(const String &leftString, const char* rightString) {
  if (!rightString)
    return leftString.length > 0;
    
  return strcmp(leftString.data, rightString) > 0;
}

// char* > String
bool operator>(const char* leftString, const String &rightString) {
  if (!leftString) 
    return false;
    
  return strcmp(leftString, rightString.data) > 0; 
}

// String + String
String operator+(const char* firstValue, const String &secondString) {
  if (firstValue == nullptr)
    return secondString;

  int firstLength = strlen(firstValue);

  String newString;
  newString.length = firstLength + secondString.length;
  newString.data = new char[newString.length + 1];

  strcpy(newString.data, firstValue);
  strcat(newString.data, secondString.data);

  return newString;
}