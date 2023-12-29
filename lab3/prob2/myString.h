#ifndef STRING_H
#define STRING_H

#include <string>
#include <iostream>

class String {
  private:
    char *data;
    int length;

  public:
    // constructors
    String();
    explicit String(const char *value);
    String(const String &secondString);

    // destructor
    ~String();

    // getters
    int getLength() const;
    char *getData() const;

    // + operator
    String operator+ (const String &secondString) const;
    String operator+ (const char* secondValue) const;

    // = operator
    String &operator= (const String &value);
    String &operator= (const char* str);

    // += operator
    String &operator+= (const String &secondString);
    String &operator+= (const char* str);

    // [] operator
    char& operator[](int index);
    const char& operator[] (int index) const;

    // friend function for +
    friend String operator+(const char* firstValue, const String &secondString);

    // friend functions for << and >>
    friend std::ostream& operator<< (std::ostream& os, const String& str);
    friend std::istream& operator>> (std::istream& is, String& str);

    // friend functions for == operator
    friend bool operator== (const String &leftString, const String &rightString);
    friend bool operator== (const String &leftString, const char* rightString);
    friend bool operator== (const char* leftString, const String &rightString);

    // friend functions for != operator
    friend bool operator!= (const String &leftString, const String &rightString);
    friend bool operator!= (const String &leftString, const char* rightString);
    friend bool operator!= (const char* leftString, const String &rightString);

    // friend functions for < operator
    friend bool operator< (const String &leftString, const String &rightString);
    friend bool operator< (const String &leftString, const char* rightString);
    friend bool operator< (const char* leftString, const String &rightString);

    // friend functions for > operator
    friend bool operator> (const String &leftString, const String &rightString);
    friend bool operator> (const String &leftString, const char* rightString);
    friend bool operator> (const char* leftString, const String &rightString);
};

#endif