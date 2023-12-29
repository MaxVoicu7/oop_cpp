#include <iostream>
#include "bool.h"

using std::cout;
using std::endl;

// ============ constructors ===============

// default constructor
Bool::Bool() : value{false} {}

// copy constructor
Bool::Bool(const Bool& object) : value{object.value} {}

// constructor with a boolean parameter
Bool::Bool(bool boolValue) : value{boolValue} {}

// constructor with an integer parameter
Bool::Bool(int number) : value{number != 0} {}





// =========== destructor ====================

Bool::~Bool() {};





// =========== getter functions ===============

bool Bool::getValue() const { return value; }





// ============ display functions ==============

void Bool::displayValue() const {
  cout << std::boolalpha << "Value: " << value << endl;
}





// ============= operators ================

// Bool || Bool
Bool Bool::operator+ (const Bool &secondValue) const {
  return Bool(value || secondValue.value);
}

// Bool || int
Bool Bool::operator+ (const int secondValue) const {
  return Bool(value || static_cast<bool>(secondValue));
}

// Bool && Bool
Bool Bool::operator* (const Bool &secondValue) const {
  return Bool(value && secondValue.value);
}

// Bool && int
Bool Bool::operator* (const int secondValue) const {
  return Bool(value && static_cast<bool>(secondValue));
}

// Bool ^ Bool
Bool Bool::operator^ (const Bool &secondValue) const {
  return Bool(value ^ secondValue.value);
}

// Bool ^ int
Bool Bool::operator^ (const int secondValue) const {
  return Bool(value ^ static_cast<bool>(secondValue));
}




// ============ friend functions =============

//  int || Bool
Bool operator+(const int firstValue, const Bool &secondValue) {
  return Bool(static_cast<bool>(firstValue) || secondValue.value);
}

//  int && Bool
Bool operator*(const int firstValue, const Bool &secondValue) {
  return Bool(static_cast<bool>(firstValue) && secondValue.value);
}

//  int ^ Bool
Bool operator^(const int firstValue, const Bool &secondValue) {
  return Bool(static_cast<bool>(firstValue) ^ secondValue.value);
}

// Bool == Bool
Bool operator== (const Bool &firstValue, const Bool &secondValue) {
  return Bool(firstValue.value == secondValue.value);
}

// Bool == int
Bool operator== (const Bool &firstValue, const int secondValue) {
  return Bool(firstValue.value == static_cast<bool>(secondValue));
}

// int == Bool
Bool operator== (const int firstValue, const Bool &secondValue) {
  return Bool(static_cast<bool>(firstValue) == secondValue.value);
}

// Bool != Bool
Bool operator!= (const Bool &firstValue, const Bool &secondValue) {
  return Bool(firstValue.value != secondValue.value);
}

// Bool != int
Bool operator!= (const Bool &firstValue, const int secondValue) {
  return Bool(firstValue.value != static_cast<bool>(secondValue));
}

// int != Bool
Bool operator!= (const int firstValue, const Bool &secondValue) {
  return Bool(static_cast<bool>(firstValue) == secondValue.value);
}